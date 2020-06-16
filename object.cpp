#include "object.h"


Object::Object(QPushButton *parent) ://创建对象,设置血量，获得位置
    QPushButton(parent),
    center_pos(x()+width()/2,y()+height()*3/4),
    attack_range(0)
{
    attack_ablt = true;
    ice = false;
    freeze = false;
}
Object::~Object(){
}
//设置满血量
void Object::set_max_blood(int max){
    this->max_blood = max;
    this->current_blood = max;
}
//设置当前血量
void Object::set_current_blood(int n){
    this->current_blood = n;
}
//获取当前血量
int Object::get_current_blood(){
    return this->current_blood;
}
int Object::get_max_blood(){
    return this->max_blood;
}
//设置攻击范围
void Object::set_range(int r){
    attack_range = r;
}

//获取攻击范围
int Object::get_range(){
    return attack_range;
}
//对象受到伤害
void Object::getDamage(int damage,bool ice){
    current_blood-=damage;
    //qDebug()<<"";
    //如果子弹有减速属性,且该对象没有被冰冻
    if(ice&&!freeze){
        qDebug()<<"this object was freezed";
        change_state();
        freezed();
    }
}
void Object::change_attack_ablt(){
    attack_ablt = !attack_ablt;
}
bool Object::get_attack_ablt(){
    return attack_ablt;
}
void Object::set_CD_time(int t){
    CD_time = t;
}
void Object::cooldown(){
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(change_attack_ablt()));
    timer->start(CD_time);
}
void Object::set_bullet_pix(QPixmap p){
    bullet_pix = p;
}
QPixmap Object::get_bullet_pix(){
    return bullet_pix;
}
void Object::set_pixmap(QPixmap p){
    pixmap = p;
}
void Object::set_freezed_pix(QPixmap p){
    freezed_pix = p;
}
void Object::draw(QPainter *painter){
    // 血条的长度
    // 其实就是2个方框,红色方框表示总生命,固定大小不变
    // 绿色方框表示当前生命,受m_currentHp / m_maxHp的变化影响
    static const int Health_Bar_Width = 20;
    painter->save();
    painter->drawPixmap(get_current_pos(),pixmap);
    //qDebug()<<"the enemy's current position is"<<get_current_pos()<<endl;
    QPoint healthBarPoint = get_current_pos() + QPoint(15, -height() / 6);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);
    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)get_current_blood() / get_max_blood() * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);
    painter->restore();
}
void Object::set_speed(double sp){
    move_speed = sp;
    low_move_speed = sp/2.0;
}
double Object::get_speed(){
    return move_speed;
}
//对象被冷冻
void Object::freezed(){
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer,SIGNAL(timeout()),this,SLOT(change_state()));
    timer->start(4000);
}
//改变状态（正常/冷冻）
void Object::change_state(){
    QPixmap tmp1 = pixmap;
    pixmap = freezed_pix;
    freezed_pix = tmp1;
    double tmp2 = move_speed;
    move_speed = low_move_speed;
    low_move_speed = tmp2;
    freeze = !freeze;
}
void Object::set_ice(){
    ice = true;
}
bool Object::get_ice(){
    return ice;
}
void Object::set_damage(int d){
    damage = d;
}
int Object::get_damage(){
    return damage;
}
