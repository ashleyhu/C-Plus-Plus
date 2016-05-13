// Program outputs 4 different shapes, with options available in both filled and hollow: Square, diamond, pyramid, and triangle.

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "shape.h"
using namespace std;

int main()
{
    // Shape object declarations
    Square my_square;
    Diamond my_diamond;
    Pyramid my_pyramid;
    Triangle my_triangle;
    
    // Open output stream and check for any errors
    ofstream fout;
    fout.open("output.txt");
    
    if(fout.fail())
    {
        cout << "Error occurred opening output.txt\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    
    // Initialize my_square and print to file
    my_square.defineSize();
    my_square.defineFill();
    
    if (my_square.getIsFilled() == true)
    {
        my_square.printFilledShape(fout);
    }
    else
    {
        my_square.printHollowShape(fout);
    }
    
    // Initialize my_diamond and print to file
    my_diamond.defineSize();
    my_diamond.defineFill();
    
    fout << endl << endl;
    
    if (my_diamond.getIsFilled() == true)
    {
        my_diamond.printFilledShape(fout);
    }
    else
    {
        my_diamond.printHollowShape(fout);
    }
    
    // Initialize my_pyramid and print to file
    my_pyramid.defineSize();
    my_pyramid.defineFill();
    
    fout << endl << endl;
    
    if (my_pyramid.getIsFilled() == true)
    {
        my_pyramid.printFilledShape(fout);
    }
    else
    {
        my_pyramid.printHollowShape(fout);
    }
    
    // Initialize my_triangle and print to file
    my_triangle.defineSize();
    my_triangle.defineFill();
    
    fout << endl << endl;
    
    if (my_triangle.getIsFilled() == true)
    {
        my_triangle.printFilledShape(fout);
    }
    else
    {
        my_triangle.printHollowShape(fout);
    }
    
    fout.close();
    
    system("pause");
    return 0;
}

