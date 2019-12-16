/* 
 * File:   main.cpp
 * Author: Alexey Prokopenko
 *
 * Created on April 28, 2018, 17:53 PM
 */


#include <cstdlib>
#include <stdio.h>  
#include <iostream> 
#include "Point.h"
#include <iostream>
#include "Matrix.h"
using namespace std;

int menu()
{
    int choice;
    cout << "Make your choice\n" << endl;
    cout << "1. set/delete an element into/from Matrix1\n"
         << "2. set/delete an element into/from Matrix2\n"
         << "3. get an element from Matrix1\n"
         << "4. get an element from Matrix2\n"
         << "5. print Matrix1\n"
         << "6. print Matrix2\n"
	 << "7. multiply Matrix1 by coefficient\n"
	 << "8. multiply Matrix2 by coefficient\n"
	 << "9. sum the Matrix1's values to the Matrix2's values\n"
         << "10. exit\n" << endl;
    cout << ">>> ";
    
  //   if it is not a digit input
	while ( !(cin >> choice) )
	{
            cin.clear();
            while ( cin.get() != '\n' ) continue;
            cout << "It's not a digit! " << endl;
            cout << ">>> ";
            
	}
    return choice;
}

int main(int argc, char** argv) {
    Matrix m1;
    Matrix m2;
   
	int x;
	int y;
	int coef;
	int value;
        bool exit = true;
	
        while(exit){
            int choice = menu(); 
            switch (choice) {
        case 1:
        {
            cout << "Matrix1 - Input data (in the form of x,y/value): ";
            scanf("%d,%d%*c%d", &x, &y, &value);
            m1.set(x,y,value);
            break;
        }
        case 2:
            cout << "Matrix2 - Input data (in the form of x,y/value): ";
            scanf("%d,%d%*c%d", &x, &y, &value);
            m2.set(x,y,value);
            break;
	case 3:
            cout << "Matrix1 - Input coordinates (in the form of x,y): " << endl;
            scanf("%d,%d", &x, &y);
            value = m1.get(x,y);
            cout << value << endl;
            break;
	case 4:
            cout << "Matrix2 - Input coordinates (in the form of x,y): " << endl;
            scanf("%d,%d", &x, &y);
            value = m2.get(x,y);
            cout << value << endl;
            break;
        case 5:
            cout << "Matrix1:" << endl;
            if (m1.getColCount()!=0) // no columns - no data
                    m1.print();
            else cout << "Matrix1 is empty" << endl;
            cout<<endl;
            break;
        case 6:
            cout << "Matrix2:" << endl;
             if (m2.getColCount()!=0) // no columns - no data
                    m2.print();
            else cout << "Matrix2 is empty" << endl;
            cout<<endl;
            break;
        case 7:
            cout << "Matrix1 - Input coefficient: ";
            cin>>coef;
            m1.product(coef);
            cout << "Product was done"<<endl;
            break;
        case 8:
            cout << "Matrix2 - Input coefficient: ";
            cin>>coef;
            m2.product(coef);
            cout << "Product was done"<<endl;
            break; 
	case 9:
            cout << "Sum both Matrixes... ";
            if(!m1.sum(&m2))
                cout << "dimentions don't match"<<endl;
            else cout << "successful operation"<<endl;		
            break;
	case 10:
            cout << "Exit..." << endl;
            exit = false;
            break;
        default:
            cout << "Unsupported choice\n" << endl;
            break;
            
            }	//--switch end
        }   //--- while end
        
        return 0;
}

