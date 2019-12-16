/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.cpp
 * Author: Alexey Prokopenko
 * 
 * Created on 28. huhtikuuta 2018, 18:52
 */

#include "Point.h"
#include "iostream"

Point::Point(int x, int y){
    setCoord(x,y);         //it is even if Constructor gets negative coordinates
                           // because a basic verification is carried out
                            //in the body of the function Matrix::set()
 /*   if(!setCoord(x, y)){
      cout << "Wrong data -> default coordinates!" << endl;
      setCoord(0, 0);
    }*/
}

bool Point::setCoord(int x, int y){
    if(x >= 0 && y >= 0){
        this->x = x;
        this->y = y;
        return true;
    }
    else return false;  
}

string Point::toString(){
    char buf[256];
    sprintf(buf,"(%d,%d)",getX(),getY());
    return buf; 
}
