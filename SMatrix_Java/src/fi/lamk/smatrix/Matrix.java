/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fi.lamk.smatrix;

import java.util.Map;
import java.util.NavigableMap;
import java.util.TreeMap;
/**
 *
 * @author Alexey Prokopenko
 */
public class Matrix {
    private Map<Point,Integer> cells = new TreeMap<>();
    boolean c;
    
    public void set(int x, int y, int value){
        Point p = new Point();  // create Point object
        if (value == 0)         
            System.out.println("Data can not be saved because the value = 0");
        else{
            c = p.setCoord(x,y); //set coordinates and if x or y is negative c gets false
            if(!c) System.out.println(" Negative coordinates!");
            else{
                if(cells.remove(p)!=null){  //  remove if key exists
                   System.out.println("data was removed");
                }
                else {cells.put(p, value); //else save a new pair key-value
                    System.out.println("data was added");
                }
            }
        }
    } //-------set end
    
    
    public int get(int x, int y){  
        Point p = new Point();
        p.setCoord(x,y);   
        if(cells.get(p)==null) return 0; // if there is no key in the map return 0
        else return cells.get(p);        // else get the value
    } //-----get end
    
    public void product(int coefficient){
        for (Map.Entry<Point, Integer> entry : cells.entrySet()){ // go through the map
            entry.setValue(entry.getValue()*coefficient); //multiply by coefficient
        }
    } //----- product end
    
    
    
    //  variant with lastEntry() 
    //  but cells should be  private NavigableMap<Point,Integer> cells = new TreeMap<>();
   /* public int getColCount(){
       Map.Entry<Point, Integer> last = cells.lastEntry();    //get last pair
           if(cells.isEmpty()) return 0;
           else return last.getKey().getX()+1;
    }*/
    
    public int getRowCount(){
        int maxY=0;
        for (Map.Entry<Point, Integer> entry : cells.entrySet()){ // go through the map
            if (maxY<entry.getKey().getY()) maxY = entry.getKey().getY(); //if current y greater previous x
        }                                                                  // save it
        return maxY+1;
    }
    
    
    public int getColCount(){
        int maxX=0;
        if(cells.isEmpty()) return maxX; // no data - no columns
        else {
            for (Map.Entry<Point, Integer> entry : cells.entrySet()){// go through the map
            if (maxX<entry.getKey().getX()) maxX = entry.getKey().getX();//if current x greater previous x
            }                                                               // save it
            return maxX+1;
        }
    }
    
    boolean sum(Matrix other){
        int sumValue;
        if (this.getColCount() == other.getColCount() && this.getRowCount() == other.getRowCount()){ //check if dimensions are equal
            for (Map.Entry<Point, Integer> entry1 : other.cells.entrySet()){                // run loop in loop to find elements with the same coordinats
                for (Map.Entry<Point, Integer> entry2 : this.cells.entrySet()){             // to find elements with the same coordinats
                    if(entry1.getKey().getX() == entry2.getKey().getX()&& entry1.getKey().getY() == entry2.getKey().getY()){
                        sumValue = entry1.getValue()+entry2.getValue();             //sum values
                        other.cells.put(entry2.getKey(), sumValue);                 //rewrite value
                    }
                }
            }
        return true;
        }
        else return false;
    }
      
    public void print(){
        
        int xLength = this.getColCount(); //size of array - columns
        int yLength = this.getRowCount(); //size of array - rows
        int x;  // current x-position
        int y;  // current y-position

        int [][] arr = new int[yLength][xLength];          //create array 
        for(int i=0; i<yLength; i++){       // and fill it by 0
           for(int j=0; j<xLength; j++){
               arr[i][j]=0;
           }
        }
        
        //array filling...
        for (Map.Entry<Point, Integer> entry : cells.entrySet()){    
            x = entry.getKey().getX();
            y = entry.getKey().getY();
            arr[y][x] = entry.getValue();  //fill cells in accordance with keys
        }
        
        for(int i=0; i<yLength; i++){        //print data in the matrix form
            for(int j=0; j<xLength; j++){
                 System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        } 
        System.out.println();
    }
}
