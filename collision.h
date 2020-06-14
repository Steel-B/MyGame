#ifndef COLLISION_H
#define COLLISION_H
#include <QPoint>
#include <math.h>

inline bool collision(QPoint point1,int r1,QPoint point2,int r2){
    const int xdif = point1.x()-point2.x();
    const int ydif = point1.y()-point2.y();
    const int distance = sqrt(xdif*xdif+ydif*ydif);
    if(distance <= r1+r2)return true;
    else return false;
}
#endif // COLLISION_H
