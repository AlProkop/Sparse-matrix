/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fi.lamk.smatrix;

import java.util.Scanner;

/**
 *
 * @author Alexey Prokopenko
 *
 */
public class SMatrixApp {

    /**
     * @param args the command line arguments
     */
    
    public static int menu()
{
    int choice;
    String s;
    
    Scanner in = new Scanner(System.in);
    s = in.nextLine(); //input string
    
    if(s.matches("\\d")) choice = Integer.valueOf(s); // check if input data is digit
    else choice = -1;
    return choice;
}
       
    public static void main(String[] args) {
        Matrix m1 = new Matrix();
        Matrix m2 = new Matrix();
   
	int x;
	int y;
	int coef;
	int value;
        boolean exit = true;
        int choice;
        Scanner in = new Scanner(System.in); // create scanner to get a data
	
        System.out.println("Make your choice");
        System.out.println("1. set/delete an element into/from Matrix1");
        System.out.println("2. set/delete an element into/from Matrix2");
        System.out.println( "3. get an element from Matrix1");
        System.out.println( "4. get an element from Matrix2");
        System.out.println( "5. print Matrix1");
        System.out.println( "6. print Matrix2");
        System.out.println( "7. multiply Matrix1 by coefficient");
        System.out.println( "8. multiply Matrix2 by coefficient");
        System.out.println( "9. sum the Matrix1's values to the Matrix2's values");
        System.out.println( "0. exit");
        System.out.println(); 
        System.out.print( ">>> ");
        
        
        while(exit){    // main cycle
            choice = menu();
            switch (choice) {
        case 1:
           // Scanner in = new Scanner(System.in);
            System.out.println( "Matrix1. Add/erase data");
            System.out.print( "Input x: ");
            x = in.nextInt();
            System.out.print( "Input y: ");
            y = in.nextInt();
            System.out.print( "Input value: ");
            value = in.nextInt();
            m1.set(x,y,value);
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;
        
        case 2:        
            System.out.println( "Matrix2. Add/erase data");
            System.out.print( "Input x: ");
            x = in.nextInt();
            System.out.print( "Input y: ");
            y = in.nextInt();
            System.out.print( "Input value: ");
            value = in.nextInt();
            m2.set(x,y,value);
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;
            
        case 3: 
            System.out.println( "Matrix1. Get value");
            System.out.print( "Input x: ");
            x = in.nextInt();
            System.out.print( "Input y: ");
            y = in.nextInt();
            System.out.println("Value: " + m1.get(x,y));
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;   
            
        case 4: 
            System.out.println( "Matrix2. Get value");
            System.out.print( "Input x: ");
            x = in.nextInt();
            System.out.print( "Input y: ");
            y = in.nextInt();
            System.out.println("Value: " + m2.get(x,y));
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;   
            
        case 5:
            System.out.println( "Matrix1:");
            if (m1.getColCount()!=0) // no columns - no data
                m1.print();
            else  System.out.println("Matrix1 is empty");
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;

        case 6:
            System.out.println( "Matrix2:");
            if (m2.getColCount()!=0) // no columns - no data
                m2.print();
            else  System.out.println("Matrix2 is empty");
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;

        case 7:
            System.out.println( "Matrix1. Product.");
            if (m1.getColCount()!=0){ // no columns - no data
                System.out.print( "Input coefficient: ");
                coef = in.nextInt();
                m1.product(coef);
                System.out.println("Product was done");
            }
            else  System.out.println("Matrix1 is empty");
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;
            
        case 8:
            System.out.println( "Matrix2. Product.");
            if (m2.getColCount()!=0){ // no columns - no data
                System.out.print( "Input coefficient: ");
                coef = in.nextInt();
                m2.product(coef);
                System.out.println("Product was done");
            }
            else  System.out.println("Matrix2 is empty");
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;
                        
	case 9:
            System.out.println("Sum both Matrixes... ");
            if(!m1.sum(m2))
                System.out.println("dimentions don't match");
            else System.out.println("successful operation");
            System.out.println(); 
            System.out.print( "Make your next choice >>> ");
            break;
            
	case 0:
            System.out.println("Exit...");
            exit = false;
            break;
            
        default:
            System.out.println("Unsupported choice\n");
            System.out.print( "Make your next choice >>> ");
            break;
            
            }	//--switch end
        }   //--- while end
    }
}
