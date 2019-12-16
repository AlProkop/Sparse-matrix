/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fi.lamk.smatrix;

/**
 *
 * @author Alexey Prokopenko
 *
 */
public class Point implements Comparable<Point> {
    private int x;
    private int y;

    public Point(){
        this(0,0);
    }
    public Point(int x, int y){
        this.setCoord(x,y);
    }

    @Override
    public String toString() {
        return "("+getX()+","+getY()+")"; //just to check what we have
    }
    
    /**
     * @return the x
     */
    public int getX() {
        return x;
    }

    public boolean setCoord(int x, int y) {//set x and y in the one function
       if(x>=0 && y>=0){ //x and y must be greater then 0 
           this.x = x;
           this.y = y;          
           return true;
       }
       else return false;
    }

    /**
     * @return the y
     */
    public int getY() {
        return y;
    }

    @Override
    public int compareTo(Point o) { // first x, then y
        if(this.getX() < o.getX()) return -1;
        if(this.getX() > o.getX()) return 1;
        if(this.getY() < o.getY()) return -1;  // if x-values are equal compare y-values
        if(this.getY() > o.getY()) return 1;
        return 0;
    }
}