// Program outputs 4 different shapes, with options available in both filled and hollow: Square, diamond, pyramid, and triangle.

#include "shape.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Base class default constructor - defaults to be a square shape
Shape::Shape()
{
    shape_type = SQUARE;
}

// Base class overloaded constructor, which accepts the type of shape
Shape::Shape(Shape_Type shape)
{
    shape_type = shape;
}

// Base class - Asks the user for the type of shape (hollow or filled)
void Shape::defineFill()
{
    int input;
    cout << "Enter the type of the shape (0 = hollow, 1 = filled): ";
    cin >> input;
    
    while(input != 0 && input != 1)
    {
        // Invalid input, ask the user again.
        cout << "Enter the type of the shape (0 = hollow, 1 = filled): ";
        cin >> input;
    }
    cout << endl;
    
    if (input == 0)
    {
        isFilled = false;
    }
    else
    {
        isFilled = true;
    }
}

// Base class - Gets the size of the shape
int Shape::getSize()
{
    return shape_size;
}

// Base class - Gets the size of the shape
void Shape::setSize(int size)
{
    shape_size = size;
}

// Base class - Checks whether the shape is filled
bool Shape::getIsFilled()
{
    return isFilled;
}

// Base class - by default, defines square size
void Shape::defineSize()
{
    int tempSize;
    cout << "Enter an integer from 1 - 20 for the size of the square's side length: ";
    cin >> tempSize;

    while(tempSize <= 0 || tempSize > 20) // Repeats until correct input is entered
    {
        cout << endl << "Enter an integer from 1 - 20 for the size of the square's side length: ";
        cin >> tempSize;
    }
    
    setSize(tempSize);
}

// Square class - by default, prints a filled square
void Shape::printFilledShape(ofstream& out_stream)
{
    for(int row = 0; row < getSize(); row++)
    {
        for(int column = 0; column < getSize(); column++) // Prints a '*' for every index of rows and columns
        {
            out_stream << "*";
        }
        out_stream << endl;
    }
}

// Shape class - by default, prints a hollow square
void Shape::printHollowShape(ofstream& out_stream)
{
    for(int row = 0; row < getSize(); row++)
    {
        for(int column = 0; column < getSize(); column++)
        {
            if (column == 0 || column == getSize() - 1 || row == 0 || row == getSize() - 1) // Same procedure as filled shaped except that the '*' at the center of shape are restricted by if statement
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        out_stream << endl;
    }
}

// Square class - default constructor
Square::Square() : Shape(SQUARE)
{
}
// Diamond class - default constructor
Diamond::Diamond() : Shape(DIAMOND)
{
}

// Diamond class - defines the dimond size
void Diamond::defineSize()
{
    int tempSize;
    cout << "Enter an odd integer from 1 - 19 for the rows of the diamond: ";
    cin >> tempSize;
    
    while(tempSize % 2 == 0 || tempSize < 1 || tempSize > 19) // Repeats until correct input is entered
    {
        cout << endl << "Enter an odd integer from 1 - 19 for the rows of the diamond: ";
        cin >> tempSize;
    }
    
    setSize(tempSize);
}

// Diamond class - prints a filled diamond
void Diamond::printFilledShape(ofstream& out_stream)
{
    for(int row = -getSize() / 2; row <= getSize() / 2; row++)
    {
        for(int column = -getSize() / 2; column <= getSize() / 2; column++)
        {
            if(abs(row) + abs(column) <= getSize() / 2) // Outputs '*' from the centre of the first row, and consecutively adds diamonds to both sides as the rows increment
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        out_stream << endl;
    }
}

// Diamond class - prints a hollow diamond
void Diamond::printHollowShape(ofstream& out_stream)
{
    for(int row = -getSize() / 2; row <= getSize() / 2; row++)
    {
        for(int column = -getSize() / 2; column <= getSize() / 2; column++)
        {
            if(abs(row) + abs(column) == getSize() / 2) // Same procedure as filled shaped except that the '*' at the center of shape are restricted by if statement
            {
                out_stream << "*";
            }
            else
                out_stream << " ";
        }
        out_stream << endl;
    }
}

// Pyramid class - default constructor
Pyramid::Pyramid() : Shape(PYRAMID)
{
}

// Pyramid class - defines the size of the pyramid
void Pyramid::defineSize()
{
    int tempSize;
    cout << "Enter an odd integer from 1 - 19 for the size of the pyramid base: ";
    cin >> tempSize;

    while (tempSize % 2 == 0 || tempSize < 1 || tempSize > 19) // Repeats until correct input is entered
    {
        cout << endl << "Enter an odd integer from 1 - 19 for the size of the pyramid base: ";
        cin >> tempSize;
    }
    
    setSize(tempSize);
}

// Pyramid class - prints a filled pyramid
void Pyramid::printFilledShape(ofstream& out_stream)
{
    int sum = 0;
    
    for(int row = 0; row < getSize() / 2 + 1; row++)
    {
        for(int column = 0; column < getSize(); column++)
        {
            if((column >= getSize() / 2 - sum) && (column <= getSize() / 2 + sum)) // Outputs '*' from the centre of the first row, and consecutively adds diamonds to both sides as the rows increment
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        out_stream << endl;
        sum++;
    }
}

// Pyramid class - prints a hollow pyramid
void Pyramid::printHollowShape(ofstream& out_stream)
{
    int sum = 0;
    
    for(int row = 0; row < getSize() / 2 + 1; row++)
    {
        for(int column = 0; column < getSize(); column++)
        {
            if((column == getSize() / 2 - sum) || (column == getSize() / 2 + sum) || (row == getSize() / 2)) // Same procedure as filled shaped except that the '*' at the center of shape are restricted by if statement
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        out_stream << endl;
        sum++;
    }
}

// Triangle class - default constructor
Triangle::Triangle() : Shape(TRIANGLE)
{
}

// Triangle class - defines the size of the triangle
void Triangle::defineSize()
{
    int tempSize;
    
    cout << "Enter an integer from 0 - 20 for the size of the triangle base: ";
    cin >> tempSize;
    
    while (tempSize <= 0 || tempSize > 20) // Repeats until correct input is entered
    {
        cout << endl << "Enter an integer from 0 - 20 for the size of the triangle base: ";
        cin >> tempSize;
    }
    
    setSize(tempSize);
}

// Triangle class - prints a filled triangle
void Triangle::printFilledShape(ofstream& out_stream)
{
    int index = getSize() - 1;
    
    for(int row = 0; row < getSize(); row++)
    {
        for (int column = 0; column < getSize(); column++) // Begins output at the first column index of getSize(), and consecutively adds '*' as the rows increment
        {
            if (column >= index)
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        index--;
        out_stream << endl;
    }
}

// Triangle class - print a hollow triangle
void Triangle::printHollowShape(ofstream& out_stream)
{
    int index = getSize() - 1;
    
    for(int row = 0; row < getSize(); row++)
    {
        for(int column = 0; column < getSize(); column++)
        {
            if(column == index || column == getSize() - 1 || row == getSize() - 1) // Same procedure as filled shaped except that the '*' at the center of shape are restricted by if statement
            {
                out_stream << "*";
            }
            else
            {
                out_stream << " ";
            }
        }
        index--;
        out_stream << endl;
    }
}
