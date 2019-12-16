/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: Alexey Prokopenko
 * 
 * Created on 28. huhtikuuta 2018, 19:13
 */

#include "Matrix.h"
#include <iostream>
#include <map>
#include "Point.h"
using namespace std;

void Matrix::set(int x, int y, int value){ //set-method
    if (value == 0) 
        cout << "Data can not be saved because the value = 0" << endl;
    else{
        bool c;
        Point p;
        c = p.setCoord(x,y);
     
        if(!c) cout << "Negative coordinates!" << endl;
        else{
        map<Point,int>::iterator mi = cells.find(p);
        
        if(mi != cells.end()){ // if key exists
            cells.erase(mi);  // remove pair key-value
            printf("The key (%d,%d) was found. Data was removed.\n", x,y);
        }
        else cells[p] =  value;      //if else than save a new pair key-value
        }
    }
} //-----end of set

int Matrix::get(int x, int y){ //get-method
    int tmp;
    bool c;
        Point p;
        c = p.setCoord(x,y);				// create Point-object (coordinates)
        if(!c){
          cout << "Negative coordinates! Result... ";  // if one of input coordinates has a egative sign, return 0
          return 0;
        }          
        else{
        map<Point,int>::iterator mi = cells.find(p);
            if(mi != cells.end())		// if Point exists, return value
                return mi->second;
            else{						//If no such coordinates in the Matrix (element does not exist), then return 0	
                printf("The key (%d,%d) was not found. Result... ", x,y);
                return 0;
            }
        }   
}

void Matrix::product(int coefficient){
    for(
            map<Point,int>::iterator mi = cells.begin();    
            mi != cells.end() ;
            mi++    
            ){
                mi->second = mi->second*coefficient;  // multiply each element by coefficient
    }
}

bool Matrix::sum(Matrix *other){
    int sumValue;
    if (this->getColCount() == other->getColCount() && this->getRowCount() == other->getRowCount()){
        map<Point,int>::iterator mi2 = other->cells.begin();
        map<Point,int>::iterator mi1 = cells.begin();
    for(
            mi2;    
            mi2 != other->cells.end() ;
            mi2++    
            ){
        for(
            mi1 = cells.begin();    
            mi1 != cells.end() ;
            mi1++    
            ){
            if(mi1->first.getX() == mi2->first.getX()&& mi1->first.getY() == mi2->first.getY())
            { 
                sumValue = (other->cells[mi2->first]+cells[mi1->first]);
                other->cells[mi2->first] = sumValue;
                
                // the second variant
            //    other->set(mi2->first.getX(), mi2->first.getY(), 1); //delete element from the map
            //  other->set(mi2->first.getX(), mi2->first.getY(), sumValue);//insert new value
                return true;
            }
        }
    }
    }
   else return false;
}

int Matrix::getRowCount(){   
    int maxY=0;
    for(
            map<Point,int>::iterator mi = cells.begin();    
            mi != cells.end() ;
            mi++    
            ){
        if (maxY < mi->first.getY()){   //if current y greater previous x
            maxY = mi->first.getY();     // save it into maxY
        }
    }
    return maxY+1;
}

int Matrix::getColCount(){
    map<Point,int>::reverse_iterator mi = cells.rbegin(); //find the last pair
    if(cells.empty())
         return 0;
    else return mi->first.getX()+1;
    
}

void Matrix::print(){
    int xLength = this->getColCount(); //size of array - columns
    int yLength = this->getRowCount(); //size of array - rows
    int x;  // current x-position
    int y;  // current y-position
   
    int arr[yLength][xLength];          //create array 
    for(int i=0; i<yLength; i++){       // and fill it by 0
       for(int j=0; j<xLength; j++){
           arr[i][j]=0;
       }
    }
   
    for(   //array filling...
            map<Point,int>::iterator mi = cells.begin();    
            mi != cells.end() ;
            mi++    
            ){
                x = mi->first.getX();     
                y = mi->first.getY();		
                arr[y][x] = mi->second;  //fill cells in accordance with keys
    }
                
   for(int i=0; i<yLength; i++){        //print data in the matrix form
       for(int j=0; j<xLength; j++){
            printf("%d\t",arr[i][j]);
       }
       printf("\n");
   } 
}