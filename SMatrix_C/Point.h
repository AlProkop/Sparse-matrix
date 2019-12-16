/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: Alexey Prokopenko
 *
 * Created on 28. huhtikuuta 2018, 18:52
 */

#ifndef POINT_H
#define POINT_H
#include <string>
#include <stdio.h>
using namespace std;

class Point {
public:
    Point(int x=0, int y=0);
   
    bool setCoord(int x, int y);
    
    int getX()const {return x;}
    
    int getY()const {return y;}
   
    string toString();
    
private:
    int x;
    int y;
};

//--------comparator a < b
inline bool operator<(const Point& a, const Point& b){
    bool res;
    if (a.getX()<b.getX()){res = true;}	
    else if (a.getX()>b.getX()){res = false;}
    else { 
        res = (a.getX() == b.getX() && a.getY()<b.getY())? true : false;  //if x are equal we should compare y values
    }
    return res;
}
#endif /* POINT_H */

