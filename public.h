#ifndef PUBLIC_H
#define PUBLIC_H
#include <QPoint>
#include <math.h>

inline bool collision(QPoint point1,int r1,QPoint point2,int r2){
    const int xdif = point1.x()-point2.x();
    const int ydif = point1.y()-point2.y();
    const int distance = sqrt(xdif*xdif+ydif*ydif);
    if(distance <= r1+r2)return true;
    else return false;
}
inline int distance(QPoint point1,QPoint point2){
    const int xdif = point1.x()-point2.x();
    const int ydif = point1.y()-point2.y();
    const int distance = sqrt(xdif*xdif+ydif*ydif);
    return distance;
}
#endif // PUBLIC_H
