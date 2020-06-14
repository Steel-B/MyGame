#include "map.h"
#include "ui_map1.h"
//#include "ui_map2.h"
//#include "ui_map3.h"
#include "elf.h"
#include "ui_result.h"

Map::Map(QWidget *parent) : QWidget(parent)
{
    money = 200;//初始金币为200
    round_now=0;//当前为第0波
    //painter.begin(this);
    //将所有敌人的damage信号遍历并处理
    for(int i=0;i<enemy_list.length();i++)
        connect(enemy_list[i],&Enemy::damage_base,this,&Map::deal_damage);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
    timer->start(10);
}
Map::~Map(){
}
void Map::set_round_total(int n){
    this->round_total = n;
}
//绘制敌人
void Map::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    foreach (Enemy* enemy, enemy_list) {
        //enemy->draw(&painter);
    }
}
//更新画面
void Map::updateMap()
{
    QPainter painter(this);
    foreach (Enemy *enemy, enemy_list){
        //enemy->draw(&painter);
        enemy->march();
    }
    update();
}
//怪物进入基地
void Map::deal_damage(){
    life--;
    if(life == 0)game_win = false;
}
//判定游戏结果
void Map::game_result(){
    Result *result;
    result = new Result;
    result->setParent(this);
    result->resize(420,260);
    result->move(400,300);
    if(game_win){
        //游戏胜利，弹出胜利界面
        result->setStyleSheet(tr("image: url(:/images/images/maps/win.png);"));
    }else{
        //游戏失败，弹出失败界面
        result->setStyleSheet(tr("image: url(:/images/images/maps/fail.png);"));
    }
}
//敌人死亡，移去
void Map::removedEnemy(Enemy* enemy){
    Q_ASSERT(enemy);
    enemy_list.removeOne(enemy);
    delete enemy;
    if(enemy_list.empty()){
        round_now++;
        int e[]={ 100, 500, 600, 1000, 3000, 6000 };
        if(!loadWave(e)){
            game_win = true;
        }
    }
}
//子弹击中，移去
void Map::removedBullet(Bullet* bullet){
    delete bullet;
}
//创建小石头
void Map::build_rock(int x,int y){
    Rock* rock;
    rock = new Rock;
    rock->resize(80,80);
    rock->setParent(this);
    rock->getopt()->setParent(this);
    rock->getopt()->move(x-90,y-100);
    rock->show();
    rock->move(x,y);
}
bool Map::loadWave(int *enemyStartInterval){
    //最后波结束
    if(round_now>round_total)
        return false;
    //每波6个敌人
    for(int i=0;i<6;i++){
        Enemy *enemy = new Enemy;
        //enemy->setParent(this);
        //移至第一航点
        enemy->set_current_pos(waypoint_list[0]->pos());
        //设置第二行点为目标点
        enemy->setdes(waypoint_list[0]);
        enemy_list.push_back(enemy);
        QTimer::singleShot(enemyStartInterval[i], enemy, SLOT(doActiate()));
    }

}
QList<Enemy*> Map::get_enemy_list(){
    return enemy_list;
}

/*QPainter* Map::get_painter(){
    return &painter;
}*/

//结果界面
Result::Result(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
    this->show();
}
Result::~Result(){
    delete ui;
}

//地图1
Map1::Map1(Map *parent) :
    Map(parent),
    ui(new Ui::Map1)
{
    ui->setupUi(this);
    set_round_total(5);//总波数为5
    addPlaces();
    addWayPoints();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap1()));
    timer->start(30);
}
Map1::~Map1(){}
void Map1::paintEvent(QPaintEvent *){
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap("images/maps/map1.jpg"));
    foreach (Enemy* enemy, get_enemy_list()) {
        enemy->setParent(this);
        enemy->draw(&painter);
        enemy->march();
    }
}
void Map1::updateMap1(){
    QPainter painter;
    painter.begin(this);
    foreach (Enemy* enemy, get_enemy_list()) {
        //enemy->draw(&painter);
    }
    update();
}
//添加防御塔位置
void Map1::addPlaces(){
    Place *b1 = new Place(this);
    b1->move(400,70);
    place_list.push_back(b1);
    Place *b2 = new Place(this);
    b2->move(610,50);
    place_list.push_back(b2);
    Place *b3 = new Place(this);
    b3->move(310,230);
    place_list.push_back(b3);
    Place *b4 = new Place(this);
    b4->move(520,380);
    place_list.push_back(b4);
    for(int i=0;i<4;i++){
        connect(place_list[i],SIGNAL(build_rock(int,int)),this,SLOT(build_rock(int,int)));
    }
}
void Map1::addWayPoints(){
    WayPoint *waypoint1 = new WayPoint(QPoint(1170,280));
    waypoint_list.push_back(waypoint1);

    WayPoint *waypoint2 = new WayPoint(QPoint(850,260));
    waypoint_list.push_back(waypoint2);
    waypoint1->setNext(waypoint2);

    WayPoint *waypoint3 = new WayPoint(QPoint(790,110));
    waypoint_list.push_back(waypoint3);
    waypoint2->setNext(waypoint3);

    WayPoint *waypoint4 = new WayPoint(QPoint(660,120));
    waypoint_list.push_back(waypoint4);
    waypoint3->setNext(waypoint4);

    WayPoint *waypoint5 = new WayPoint(QPoint(610,260));
    waypoint_list.push_back(waypoint5);
    waypoint4->setNext(waypoint5);

    WayPoint *waypoint6 = new WayPoint(QPoint(360,310));
    waypoint_list.push_back(waypoint6);
    waypoint5->setNext(waypoint6);

    WayPoint *waypoint7 = new WayPoint(QPoint(360,420));
    waypoint_list.push_back(waypoint7);
    waypoint6->setNext(waypoint7);

    WayPoint *waypoint8 = new WayPoint(QPoint(710,450));
    waypoint_list.push_back(waypoint8);
    waypoint7->setNext(waypoint8);

    WayPoint *waypoint9 = new WayPoint(QPoint(730,570));
    waypoint_list.push_back(waypoint9);
    waypoint8->setNext(waypoint9);

    WayPoint *waypoint10 = new WayPoint(QPoint(560,610));
    waypoint_list.push_back(waypoint10);
    waypoint9->setNext(waypoint10);

    WayPoint *waypoint11 = new WayPoint(QPoint(540,740));
    waypoint_list.push_back(waypoint11);
    waypoint10->setNext(waypoint11);
}
//返回关卡选择页面
void Map1::on_backsub_clicked()
{
    emit Backsub();
    this->hide();
}
//点击位置一
void Map1::on_b_1_clicked()
{
    Place *p;
    p = new Place(this);
    p->move(ui->b_1->x()-81,ui->b_1->y()-101);
}

void Map1::on_start_clicked()
{
    int e[]={ 100, 1000, 2000, 3000, 4500, 6000 };
    loadWave(e);
    ui->start->hide();
}
