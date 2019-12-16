/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: Alexey Prokopenko
 *
 * Created on 28. huhtikuuta 2018, 19:13
 */

#ifndef MATRIX_H
#define MATRIX_H
#include <string>  
#include <sstream>  
#include <map>  
#include "Point.h"
using namespace std;

class Matrix {
public:
    void set(int x, int y, int value);
    int get(int x, int y);
    void product(int coefficient);   
    bool sum(Matrix *other);
    int getRowCount();
    int getColCount();
    void list();
    void print();
  
private:
    map<Point, int> cells;
};

#endif /* MATRIX_H */

