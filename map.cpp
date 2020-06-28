#include "map.h"
#include "ui_map.h"
#include "ui_result.h"
#include <QDebug>

Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    map3 = false;
    //鼠标变手
    ui->backsub->setCursor(QCursor(Qt::PointingHandCursor));
    ui->start->setCursor(QCursor(Qt::PointingHandCursor));

    //每60ms刷新一次页面
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
    timer->start(60);

    timer2 = new QTimer(this);
    player = new QMediaPlayer;
    player_bgm = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    res = new Result;

}
Map::~Map(){
    //清空航点、敌人、子弹、防御塔
    qDeleteAll(waypoint_list);
    waypoint_list.clear();
    qDeleteAll(elf_list);
    elf_list.clear();
    qDeleteAll(enemy_list);
    enemy_list.clear();
    qDeleteAll(place_list);
    place_list.clear();
    qDeleteAll(bullet_list);
    bullet_list.clear();

    playlist->clear();
    delete player;
    delete player_bgm;
    delete playlist;
}
//绘制
void Map::paintEvent(QPaintEvent *event){
    QPixmap Pix = map.scaled(width(),height());
    QPainter Pixpainter(&Pix);
    //遍历防御塔并绘画
    foreach (Elf *elf, elf_list) {
        elf->draw(&Pixpainter,map3);
    }
    //遍历敌人并绘画
    foreach (Enemy* enemy, enemy_list) {
        enemy->setParent(this);
        enemy->draw(&Pixpainter,map3);
        enemy->move(enemy->get_current_pos());
        enemy->show();
        //关联敌人对基地的伤害函数
        connect(enemy,&Enemy::damage_base,this,&Map::deal_damage);
    }
    //遍历子弹并绘画
    foreach (Bullet *bullet,bullet_list){
        bullet->draw(&Pixpainter);
    }

    //数值面板
    QPainter painter(this);
    painter.drawPixmap(0,0,Pix);
    QFont font("Arial Rounded MT Bold", 20, QFont::Bold);
    ui->life->setFont(font);
    ui->money->setFont(font);
    ui->wave->setFont(font);
    QPalette pa;
    //当前生命
    pa.setColor(QPalette::WindowText,"#CC0000");
    ui->life->setPalette(pa);
    QString str1 = "              "+QString::number(life_current);
    ui->life->setText(str1);
    //当前金币
    pa.setColor(QPalette::WindowText,"#EEEE00");
    ui->money->setPalette(pa);
    QString str2 = "            "+QString::number(money_current);
    ui->money->setText(str2);
    //波数
    pa.setColor(QPalette::WindowText,"#AAAAAA");
    ui->wave->setPalette(pa);
    QString str3 = "            "+QString::number(wave_current)+" / "+QString::number(wave_total);
    ui->wave->setText(str3);
}
//更新画面
void Map::updateMap()
{
    foreach (Bullet *bullet,bullet_list){
        bullet->move();
        //如果子弹已击中，移去
        if(bullet->get_state()){
            if(object_list.indexOf(bullet->get_target_object()) != -1){
                bullet->get_target_object()->getDamage(bullet->get_damage(),bullet->get_ice());
            }
            removedBullet(bullet);
            continue;
        }
        //如果发射对象消失
        if(object_list.indexOf(bullet->get_cast_object()) == -1){
            removedBullet(bullet);
            continue;
        }
        //如果目标点超过射程，移去
        if(distance(bullet->get_target_pos(),bullet->get_start_pos())>=bullet->get_cast_object()->get_range()){
            removedBullet(bullet);
            continue;
        }
        //如果子弹超过射程，移去
        if(distance(bullet->get_current_pos(),bullet->get_start_pos())>=bullet->get_cast_object()->get_range()){
            removedBullet(bullet);
            continue;
        }
    }
    //遍历防御塔
    foreach (Elf *elf, elf_list) {
        //如果防御塔被破坏
        if(elf->get_current_blood()<=0){
            removedElf(elf);
            continue;
        }
        foreach (Enemy *enemy, enemy_list){
            //如果敌人进入攻击范围，攻击锁定
            if(distance(elf->get_current_pos(),enemy->get_current_pos())<=elf->get_range()){
                //如果攻击者存在
                attack(elf,enemy);
            }
        }
    }
    //攻击性敌人确定攻击对象
    foreach (Enemy *enemy3, enemy3_list) {
        foreach (Elf *elf, elf_list) {
            if(distance(enemy3->get_current_pos(),elf->get_current_pos())<=enemy3->get_range()){
                attack(enemy3,elf);
            }
        }
    }
    //遍历敌人
    foreach (Enemy *enemy, enemy_list){
        //如果敌人已死亡
        if(enemy->get_current_blood()<=0){
            money_current += enemy->get_value();    //金钱增加
            removedEnemy(enemy);                    //移去敌人
            continue;               //检查下一个敌人
        }
        //如果敌人未死亡，则移动
        enemy->march();
    }
    update();
}
void Map::set_life_total(int n){
    life_total = n;
    life_current = n;
}
void Map::set_money_start(int n){
    money_start = n;
    money_current = n;
}
void Map::set_wave_total(int n){
    wave_total = n;
    wave_current = 0;
}
void Map::set_enemy_load(vector<vector<int>> e1,
                         vector<vector<int>> e2,
                         vector<vector<int>> e3,
                         vector<vector<int>> e4){
    enemy1_load=e1;
    enemy2_load=e2;
    enemy3_load=e3;
    enemy4_load=e4;
}
//虚函数
void Map::addPlaces(){}
void Map::addWayPoints(){}

//怪物进入基地
void Map::deal_damage(Enemy* e){
    removedEnemy(e);
    money_current += e->get_value();
    life_current--;
    //如果生命小于等于0，游戏失败
    if(life_current <= 0){
        game_win = false;
        game_result();
    }
}
//移去防御塔
void Map::removedElf(Elf *elf){
    Q_ASSERT(elf);
    elf->get_button()->show();
    elf_list.removeOne(elf);
    object_list.removeOne(elf);
    delete elf;
}
//敌人死亡，移去
void Map::removedEnemy(Enemy* enemy){
    Q_ASSERT(enemy);
    player->setMedia(QUrl("qrc:/sound/sound/money.mp3"));
    player->setVolume(30);
    player->play();
    enemy_list.removeOne(enemy);
    object_list.removeOne(enemy);
    if(enemy3_list.indexOf(enemy) != -1)enemy3_list.removeOne(enemy);
    delete enemy;
}
//子弹击中，移去
void Map::removedBullet(Bullet* bullet){
    Q_ASSERT(bullet);
    if(bullet->get_ice()){
        player->setMedia(QUrl("qrc:/sound/sound/bullet/ice_broken.mp3"));
        player->setVolume(30);
        player->play();
    }
    bullet_list.removeOne(bullet);
    delete bullet;
}
//创建一类防御塔
void Map::build_rock(Place* p,QPushButton* b){
    int x = p->x();
    int y = p->y();
    Rock* rock;
    rock = new Rock;
    //如果金钱不够
    if(money_current < rock->get_cost()){
        delete rock;
        b->show();
        return;
    }
    rock->set_button(b);
    money_current -= rock->get_cost();
    rock->set_current_pos(QPoint(x+55,y+50));
    rock->move(QPoint(x+55,y+50));
    elf_list.push_back(rock);
    object_list.push_back(rock);
    //关联防御塔出售
    connect(rock,SIGNAL(sell_signal(Elf*)),this,SLOT(sell_elf(Elf*)));
    //关联防御塔升级
    connect(rock,SIGNAL(up_signal(Elf*)),this,SLOT(up_elf(Elf*)));
    rock->setParent(this);
    rock->show();
}
//创建二类防御塔
void Map::build_ice(Place* p,QPushButton* b){
    int x = p->x();
    int y = p->y();
    Ice* ice;
    ice = new Ice;
    //如果金钱不够
    if(money_current < ice->get_cost()){
        delete ice;
        b->show();
        return;
    }
    ice->set_button(b);
    money_current -= ice->get_cost();
    ice->set_current_pos(QPoint(x+55,y+50));
    ice->move(QPoint(x+55,y+50));
    elf_list.push_back(ice);
    object_list.push_back(ice);
    //关联防御塔出售
    connect(ice,SIGNAL(sell_signal(Elf*)),this,SLOT(sell_elf(Elf*)));
    //关联防御塔升级
    connect(ice,SIGNAL(up_signal(Elf*)),this,SLOT(up_elf(Elf*)));
    ice->setParent(this);
    ice->show();
}
//创建三类防御塔
void Map::build_grass(Place* p,QPushButton* b){
    int x = p->x();
    int y = p->y();
    Grass* grass;
    grass = new Grass;
    //如果金钱不够
    if(money_current < grass->get_cost()){
        delete grass;
        b->show();
        return;
    }
    grass->set_button(b);
    money_current -= grass->get_cost();
    grass->set_current_pos(QPoint(x+55,y+50));
    grass->move(QPoint(x+55,y+50));
    elf_list.push_back(grass);
    object_list.push_back(grass);
    //关联防御塔出售
    connect(grass,SIGNAL(sell_signal(Elf*)),this,SLOT(sell_elf(Elf*)));
    //关联防御塔升级
    connect(grass,SIGNAL(up_signal(Elf*)),this,SLOT(up_elf(Elf*)));
    grass->setParent(this);
    grass->show();
}
//售卖防御塔
void Map::sell_elf(Elf *e){
    money_current += e->get_cost()*0.9;
    removedElf(e);
}
//防御塔升级
void Map::up_elf(Elf *e){
    //如果金币不够
    if(money_current < e->get_cost() + 20){
        return;
    }else{
        //金钱足够
        money_current -= e->get_cost() + 20;
        e->set_cost(e->get_cost()+20);
        e->up();//升级
        return;
    }
}
//加载波次
void Map::loadWave(){
    if(wave_current == wave_total){
        //如果是最后一波，检查敌人是否被完全消灭
        connect(timer2,SIGNAL(timeout()),this,SLOT(check_enemy()));
        timer2->start(200);
        return;
    }
    //游戏未结束
    //生成一类敌人
    for(int i=0;i<6;i++){
        //如果第n波第i个一类敌人不存在
        if(enemy1_load[wave_current][i] == 0){
            break;
        }
        //如果存在，生成第n波第i个一类敌人
        Enemy1 *enemy1 = new Enemy1;
        if(map3)enemy1->set_max_blood(enemy1->get_current_blood()*5);
        enemy1->setParent(this);
        //移至第一航点
        enemy1->set_current_pos(waypoint_list[0]->pos());
        //设置第二行点为目标点
        enemy1->set_des(waypoint_list[0]);
        enemy_list.push_back(enemy1);
        object_list.push_back(enemy1);
        QTimer::singleShot(enemy1_load[wave_current][i], enemy1, SLOT(change_act_ablt()));    //定时
    }
    //生成二类敌人
    for(int i=0;i<6;i++ ){
        //如果第n波第i个二类敌人不存在
        if(enemy2_load[wave_current][i] == 0){
            break;
        }
        //如果存在，生成第n波第i个二类敌人
        Enemy2 *enemy2 = new Enemy2;
        if(map3)enemy2->set_max_blood(enemy2->get_current_blood()*5);
        enemy2->setParent(this);
        //移至第一航点
        enemy2->set_current_pos(waypoint_list[0]->pos());
        //设置第二行点为目标点
        enemy2->set_des(waypoint_list.last());
        enemy_list.push_back(enemy2);
        object_list.push_back(enemy2);
        QTimer::singleShot(enemy2_load[wave_current][i], enemy2, SLOT(change_act_ablt()));    //定时
    }
    //生成三类敌人（可攻击）
    for(int i=0;i<6;i++ ){
        //如果第n波第i个二类敌人不存在
        if(enemy3_load[wave_current][i] == 0){
            break;
        }
        //如果存在，生成第n波第i个二类敌人
        Enemy3 *enemy3 = new Enemy3;
        if(map3)enemy3->set_max_blood(enemy3->get_current_blood()*5);
        enemy3->setParent(this);
        //移至第一航点
        enemy3->set_current_pos(waypoint_list[0]->pos());
        //设置第二行点为目标点
        enemy3->set_des(waypoint_list[0]);
        enemy_list.push_back(enemy3);
        object_list.push_back(enemy3);
        enemy3_list.push_back(enemy3);
        QTimer::singleShot(enemy3_load[wave_current][i], enemy3, SLOT(change_act_ablt()));    //定时
    }
    //生成四类敌人
    for(int i=0;i<6;i++ ){
        //如果第n波第i个二类敌人不存在
        if(enemy4_load[wave_current][i] == 0){
            break;
        }
        //如果存在，生成第n波第i个二类敌人
        Enemy4 *enemy4 = new Enemy4;
        if(map3)enemy4->set_max_blood(enemy4->get_current_blood()*5);
        enemy4->setParent(this);
        //移至第一航点
        enemy4->set_current_pos(waypoint_list[0]->pos());
        //设置第二行点为目标点
        enemy4->set_des(waypoint_list[0]);
        enemy_list.push_back(enemy4);
        object_list.push_back(enemy4);
        QTimer::singleShot(enemy4_load[wave_current][i], enemy4, SLOT(change_act_ablt()));    //定时
    }
    //如果不是最后一波，当前波次+1
    wave_current++;
    return;
}
//攻击
void Map::attack(Object *attacker,Object *target){
    connect(attacker,&Object::timer_ptr,this,delete_ptr);
    //如果在冷却中
    if(!attacker->get_attack_ablt())return;
    //如果冷却结束
    Bullet *bullet = new Bullet;

    player->setMedia(QUrl("qrc:/sound/sound/bullet/shoot.mp3"));
    player->setVolume(30);
    player->play();

    bullet->setParent(this);
    //如果攻击者有冰属性，则子弹有冰属性

    if(attacker->get_ice())bullet->set_ice();
    bullet->set_damage(attacker->get_damage());
    bullet->set_cast_object(attacker);
    bullet->set_pixmap(attacker->get_bullet_pix());
    bullet->set_current_pos(attacker->get_current_pos());
    bullet->set_target_object(target);
    bullet_list.push_back(bullet);
    //攻击者冷却
    attacker->change_attack_ablt();
    attacker->cooldown();

}
//判定游戏结果
void Map::game_result(){
    timer1->stop();
    delete timer1;
    foreach (Bullet *bullet, bullet_list) {
        removedBullet(bullet);
    }
    foreach (Enemy *enemy, enemy_list) {
        enemy->change_act_ablt();
    }
    foreach (Elf *elf, elf_list) {
        elf->set_CD_time(3600000);
    }

    connect(res,&Result::restart,this,&Map::deal_restart);
    connect(res,&Result::quit,this,&Map::deal_quit);
    res->setParent(this);
    res->resize(420,260);
    res->move(0,0);
    if(game_win){
        //游戏胜利，弹出胜利界面
        res->set_pix(pix1);
        res->win();
        res->show();
    }else{
        //游戏失败，弹出失败界面
        res->set_pix(pix2);
        res->fail();
        res->show();
    }
}
//重新开始游戏
void Map::deal_restart(){
    life_current = life_total;
    money_current = money_start;
    wave_current = 0;
    foreach (Elf *elf, elf_list) {
        removedElf(elf);
    }
    foreach (Enemy *enemy, enemy_list) {
        removedEnemy(enemy);
    }
    delete res;
    ui->start->show();
}
//退回关卡选择页面
void Map::deal_quit(){
    emit Backsub(this);
}
//返回关卡选择页面
void Map::on_backsub_clicked()
{
    emit Backsub(this);
}

//开始游戏
void Map::on_start_clicked()
{
    //音效
    player->setMedia(QUrl("qrc:/sound/sound/click.mp3"));
    player->setVolume(30);
    player->play();

    addPlaces();        //添加防御点
    addWayPoints();     //添加航点

    //开始第一波
    loadWave();
    //每30秒进行下一波
    timer1 = new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(loadWave()));
    timer1->start(30000);
    ui->start->hide();
}
void Map::check_enemy(){
    if(enemy_list.empty()){
        game_win = true;
        delete timer2;
        game_result();
        return;
    }
    return;
}
void Map::delete_ptr(QTimer *t){
    delete t;
}
//地图1
Map1::Map1(Map *parent) :
    Map(parent)
{

    set_map(QPixmap("images/maps/map1.jpg"));   //载入地图
    set_life_total(5);                          //总生命为5
    set_money_start(500);                       //初始金币210
    set_wave_total(5);                          //总波数为5
    pix1 = QPixmap(":/images/images/maps/res2.png");
    pix2 = QPixmap(":/images/images/maps/res1.png");
    //设定怪物数量
    vector<vector<int>> e1 = {
        {100, 0, 0, 0, 0, 0},
        {100, 3000, 5000, 0, 0, 0},
        {100, 3000, 5000, 0, 0, 0},
        {100, 3000, 5000, 7000, 9000, 0},
        {100, 3000, 5000, 7000, 9000, 0}
    };
    vector<vector<int>> e2 = {
        {3000, 0, 0, 0, 0, 0},
        {3000, 0, 0, 0, 0, 0},
        {3000, 0, 0, 0, 0, 0},
        {3000, 5000, 0, 0, 0, 0},
        {3000, 5000, 0, 0, 0, 0}
    };
    vector<vector<int>> e3 = {
        {6000, 0, 0, 0, 0, 0},
        {6000, 0, 0, 0, 0, 0},
        {6000, 0, 0, 0, 0, 0},
        {6000, 8000, 0, 0, 0, 0},
        {6000, 8000, 0, 0, 0, 0}
    };
    vector<vector<int>> e4 = {
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0}
    };
    set_enemy_load(e1,e2,e3,e4);

    //背景音乐

    playlist->addMedia(QUrl("qrc:/sound/sound/BGM/StudioEIM - 神木村龙林音乐.mp3"));
    player_bgm->setPlaylist(playlist);
    player_bgm->setVolume(20);
    player_bgm->play();
}
Map1::~Map1(){

}

//添加防御塔位置
void Map1::addPlaces(){
    Place *b1 = new Place(this);
    b1->move(650,95);
    place_list.push_back(b1);
    Place *b2 = new Place(this);
    b2->move(450,110);
    place_list.push_back(b2);
    Place *b3 = new Place(this);
    b3->move(360,280);
    place_list.push_back(b3);
    Place *b4 = new Place(this);
    b4->move(540,260);
    place_list.push_back(b4);
    Place *b5 = new Place(this);
    b5->move(570,420);
    place_list.push_back(b5);
    for(int i=0;i<5;i++){
        connect(place_list[i],SIGNAL(build_rock(Place*,QPushButton*)),this,SLOT(build_rock(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_ice(Place*,QPushButton*)),this,SLOT(build_ice(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_grass(Place*,QPushButton*)),this,SLOT(build_grass(Place*,QPushButton*)));
    }
}
void Map1::addWayPoints(){
    WayPoint *waypoint1 = new WayPoint(QPoint(1130,240));
    waypoint_list.push_back(waypoint1);

    WayPoint *waypoint2 = new WayPoint(QPoint(830,220));
    waypoint_list.push_back(waypoint2);
    waypoint1->setNext(waypoint2);

    WayPoint *waypoint3 = new WayPoint(QPoint(770,90));
    waypoint_list.push_back(waypoint3);
    waypoint2->setNext(waypoint3);

    WayPoint *waypoint4 = new WayPoint(QPoint(620,100));
    waypoint_list.push_back(waypoint4);
    waypoint3->setNext(waypoint4);

    WayPoint *waypoint5 = new WayPoint(QPoint(570,240));
    waypoint_list.push_back(waypoint5);
    waypoint4->setNext(waypoint5);

    WayPoint *waypoint6 = new WayPoint(QPoint(320,290));
    waypoint_list.push_back(waypoint6);
    waypoint5->setNext(waypoint6);

    WayPoint *waypoint7 = new WayPoint(QPoint(320,400));
    waypoint_list.push_back(waypoint7);
    waypoint6->setNext(waypoint7);

    WayPoint *waypoint8 = new WayPoint(QPoint(720,430));
    waypoint_list.push_back(waypoint8);
    waypoint7->setNext(waypoint8);

    WayPoint *waypoint9 = new WayPoint(QPoint(710,550));
    waypoint_list.push_back(waypoint9);
    waypoint8->setNext(waypoint9);

    WayPoint *waypoint10 = new WayPoint(QPoint(520,590));
    waypoint_list.push_back(waypoint10);
    waypoint9->setNext(waypoint10);

    WayPoint *waypoint11 = new WayPoint(QPoint(500,720));
    waypoint_list.push_back(waypoint11);
    waypoint10->setNext(waypoint11);
}
//地图2
Map2::Map2(Map *parent) :
    Map(parent)
{
    //载入地图
    set_map(QPixmap("images/maps/map2.jpg"));
    set_life_total(6);//总生命为6
    set_money_start(700);//初始金币700
    set_wave_total(6);//总波数为6
    addPlaces();
    addWayPoints();
    pix1 = QPixmap(":/images/images/maps/res2.png");
    pix2 = QPixmap(":/images/images/maps/res1.png");
    //设定怪物数量
    vector<vector<int>> e1 = {
        {100, 0, 0, 0, 0, 0},
        {100, 3000, 5000, 0, 0, 0},
        {100, 3000, 5000, 0, 0, 0},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000}
    };
    vector<vector<int>> e2 = {
        {3000, 0, 0, 0, 0, 0},
        {3000, 0, 0, 0, 0, 0},
        {3000, 0, 0, 0, 0, 0},
        {3000, 5000, 0, 0, 0, 0},
        {3000, 5000, 0, 0, 0, 0},
        {3000, 5000, 8000, 0, 0, 0}
    };
    vector<vector<int>> e3 = {
        {6000, 0, 0, 0, 0, 0},
        {6000, 0, 0, 0, 0, 0},
        {6000, 0, 0, 0, 0, 0},
        {6000, 8000, 0, 0, 0, 0},
        {6000, 8000, 0, 0, 0, 0},
        {6000, 8000, 10000, 0, 0, 0}
    };
    vector<vector<int>> e4 = {
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 0, 0, 0, 0, 0},
        {7000, 11000, 0, 0, 0, 0},
        {7000, 11000, 0, 0, 0, 0}
    };
    set_enemy_load(e1,e2,e3,e4);

    playlist->addMedia(QUrl("qrc:/sound/sound/BGM/StudioEIM - 鱼王 boss.mp3"));
    player_bgm->setPlaylist(playlist);
    player_bgm->setVolume(20);
    player_bgm->play();
}
Map2::~Map2(){

}

//添加防御塔位置
void Map2::addPlaces(){
    Place *b1 = new Place(this);
    b1->move(685,130);
    place_list.push_back(b1);
    Place *b2 = new Place(this);
    b2->move(515,130);
    place_list.push_back(b2);
    Place *b3 = new Place(this);
    b3->move(360,125);
    place_list.push_back(b3);
    Place *b4 = new Place(this);
    b4->move(680,300);
    place_list.push_back(b4);
    Place *b5 = new Place(this);
    b5->move(520,300);
    place_list.push_back(b5);
    Place *b6 = new Place(this);
    b6->move(350,300);
    place_list.push_back(b6);
    Place *b7 = new Place(this);
    b7->move(460,470);
    place_list.push_back(b7);
    Place *b8 = new Place(this);
    b8->move(645,475);
    place_list.push_back(b8);
    Place *b9 = new Place(this);
    b9->move(840,540);
    place_list.push_back(b9);
    for(int i=0;i<9;i++){
        connect(place_list[i],SIGNAL(build_rock(Place*,QPushButton*)),this,SLOT(build_rock(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_ice(Place*,QPushButton*)),this,SLOT(build_ice(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_grass(Place*,QPushButton*)),this,SLOT(build_grass(Place*,QPushButton*)));
    }
}
void Map2::addWayPoints(){
    WayPoint *waypoint1 = new WayPoint(QPoint(740,0));
    waypoint_list.push_back(waypoint1);

    WayPoint *waypoint2 = new WayPoint(QPoint(700,100));
    waypoint_list.push_back(waypoint2);
    waypoint1->setNext(waypoint2);

    WayPoint *waypoint3 = new WayPoint(QPoint(340,120));
    waypoint_list.push_back(waypoint3);
    waypoint2->setNext(waypoint3);

    WayPoint *waypoint4 = new WayPoint(QPoint(350,270));
    waypoint_list.push_back(waypoint4);
    waypoint3->setNext(waypoint4);

    WayPoint *waypoint5 = new WayPoint(QPoint(880,340));
    waypoint_list.push_back(waypoint5);
    waypoint4->setNext(waypoint5);

    WayPoint *waypoint6 = new WayPoint(QPoint(820,450));
    waypoint_list.push_back(waypoint6);
    waypoint5->setNext(waypoint6);

    WayPoint *waypoint7 = new WayPoint(QPoint(420,500));
    waypoint_list.push_back(waypoint7);
    waypoint6->setNext(waypoint7);

    WayPoint *waypoint8 = new WayPoint(QPoint(430,610));
    waypoint_list.push_back(waypoint8);
    waypoint7->setNext(waypoint8);

    WayPoint *waypoint9 = new WayPoint(QPoint(770,640));
    waypoint_list.push_back(waypoint9);
    waypoint8->setNext(waypoint9);

    WayPoint *waypoint10 = new WayPoint(QPoint(760,710));
    waypoint_list.push_back(waypoint10);
    waypoint9->setNext(waypoint10);

}
//地图3

Map3::Map3(Map *parent) :
    Map(parent)
{
    map3 = true;
    //载入地图
    set_map(QPixmap("images/maps/map3.jpg"));
    set_life_total(10);//总生命为10
    set_money_start(100000);//初始金币450
    set_wave_total(7);//总波数为7
    addPlaces();
    addWayPoints();
    pix1 = QPixmap(":/images/images/maps/res3.png");
    pix2 = QPixmap(":/images/images/maps/res1.png");
    //设定怪物数量
    vector<vector<int>> e1 = {
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000},
        {100, 3000, 5000, 7000, 9000, 11000}
    };
    vector<vector<int>> e2 = {
        {3000, 4000, 5000, 0, 0, 0},
        {3000, 4000, 5000, 0, 0, 0},
        {3000, 4000, 5000, 0, 0, 0},
        {3000, 4000, 5000, 8000, 9000, 10000},
        {3000, 4000, 5000, 8000, 9000, 10000},
        {3000, 4000, 5000, 8000, 9000, 10000},
        {3000, 4000, 5000, 8000, 9000, 10000}
    };
    vector<vector<int>> e3 = {
        {2000, 4000, 6000, 0, 0, 0},
        {2000, 4000, 6000, 0, 0, 0},
        {2000, 4000, 6000, 0, 0, 0},
        {2000, 4000, 6000, 0, 0, 0},
        {2000, 4000, 6000, 8000, 10000, 0},
        {2000, 4000, 6000, 8000, 10000, 0},
        {2000, 4000, 6000, 8000, 10000, 12000}
    };
    vector<vector<int>> e4 = {
        {7000, 9000, 11000, 0, 0, 0},
        {7000, 9000, 11000, 0, 0, 0},
        {7000, 9000, 11000, 0, 0, 0},
        {7000, 9000, 11000, 0, 0, 0},
        {7000, 9000, 11000, 0, 0, 0},
        {7000, 9000, 11000, 12000, 13000, 14000},
        {7000, 9000, 11000, 12000, 13000, 14000}
    };
    set_enemy_load(e1,e2,e3,e4);

    playlist->addMedia(QUrl("qrc:/sound/sound/BGM/StudioEIM - 神木村生命的洞窟.mp3"));
    player_bgm->setPlaylist(playlist);
    player_bgm->setVolume(20);
    player_bgm->play();

    res->last_map();
}
Map3::~Map3(){

}

//添加防御塔位置
void Map3::addPlaces(){
    Place *b1 = new Place(this);
    b1->move(870,430+10);
    place_list.push_back(b1);
    Place *b2 = new Place(this);
    b2->move(605,440+10);
    place_list.push_back(b2);
    Place *b3 = new Place(this);
    b3->move(860,290+10);
    place_list.push_back(b3);
    Place *b4 = new Place(this);
    b4->move(620,225+10);
    place_list.push_back(b4);
    Place *b5 = new Place(this);
    b5->move(755,150+5);
    place_list.push_back(b5);
    Place *b6 = new Place(this);
    b6->move(615,85+5);
    place_list.push_back(b6);
    Place *b7 = new Place(this);
    b7->move(400,100+5);
    place_list.push_back(b7);
    Place *b8 = new Place(this);
    b8->move(330,270+10);
    place_list.push_back(b8);
    Place *b9 = new Place(this);
    b9->move(470+10,330);
    place_list.push_back(b9);
    Place *b10 = new Place(this);
    b10->move(280,430+10);
    place_list.push_back(b10);
    for(int i=0;i<10;i++){
        connect(place_list[i],SIGNAL(build_rock(Place*,QPushButton*)),this,SLOT(build_rock(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_ice(Place*,QPushButton*)),this,SLOT(build_ice(Place*,QPushButton*)));
        connect(place_list[i],SIGNAL(build_grass(Place*,QPushButton*)),this,SLOT(build_grass(Place*,QPushButton*)));
    }
}
void Map3::addWayPoints(){
    WayPoint *waypoint1 = new WayPoint(QPoint(1140,580));
    waypoint_list.push_back(waypoint1);

    WayPoint *waypoint2 = new WayPoint(QPoint(815,570));
    waypoint_list.push_back(waypoint2);
    waypoint1->setNext(waypoint2);

    WayPoint *waypoint3 = new WayPoint(QPoint(810,320));
    waypoint_list.push_back(waypoint3);
    waypoint2->setNext(waypoint3);

    WayPoint *waypoint3_5 = new WayPoint(QPoint(910,200));
    waypoint_list.push_back(waypoint3_5);
    waypoint3->setNext(waypoint3_5);

    WayPoint *waypoint4 = new WayPoint(QPoint(910,90));
    waypoint_list.push_back(waypoint4);
    waypoint3_5->setNext(waypoint4);

    WayPoint *waypoint5 = new WayPoint(QPoint(590,100));
    waypoint_list.push_back(waypoint5);
    waypoint4->setNext(waypoint5);

    WayPoint *waypoint6 = new WayPoint(QPoint(540,260));
    waypoint_list.push_back(waypoint6);
    waypoint5->setNext(waypoint6);

    WayPoint *waypoint7 = new WayPoint(QPoint(280,280));
    waypoint_list.push_back(waypoint7);
    waypoint6->setNext(waypoint7);

    WayPoint *waypoint8 = new WayPoint(QPoint(290,410));
    waypoint_list.push_back(waypoint8);
    waypoint7->setNext(waypoint8);

    WayPoint *waypoint9 = new WayPoint(QPoint(430,460));
    waypoint_list.push_back(waypoint9);
    waypoint8->setNext(waypoint9);

    WayPoint *waypoint10 = new WayPoint(QPoint(400,590));
    waypoint_list.push_back(waypoint10);
    waypoint9->setNext(waypoint10);

    WayPoint *waypoint11 = new WayPoint(QPoint(0,590));
    waypoint_list.push_back(waypoint11);
    waypoint10->setNext(waypoint11);
}

//结果界面
Result::Result(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    //鼠标变手
    ui->restart->setCursor(QCursor(Qt::PointingHandCursor));
    ui->quit->setCursor(QCursor(Qt::PointingHandCursor));
    last = false;
}

Result::~Result(){
    delete ui;
}
//游戏胜利
void Result::win(){
    //如果是第三关
    if(last)ui->image->setStyleSheet(tr("image: url(:/images/images/maps/res3.png);"));
    else ui->image->setStyleSheet(tr("image: url(:/images/images/maps/res2.png);"));

    ui->widget->setStyleSheet(tr("border-image: url(:/images/images/maps/win.png);"));
}
//游戏失败
void Result::fail(){
    ui->image->setStyleSheet(tr("image: url(:/images/images/maps/res1.png);"));
    ui->widget->setStyleSheet(tr("border-image: url(:/images/images/maps/fail.png);"));
}
void Result::on_restart_clicked()
{
    emit restart();
}
void Result::on_quit_clicked()
{
    emit quit();
}


