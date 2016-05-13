// Program outputs 4 different shapes, with options available in both filled and hollow: Square, diamond, pyramid, and triangle.

#ifndef SHAPES_H
#define SHAPES_H
#include <fstream>
#include <iostream>

using namespace std;

enum Shape_Type {SQUARE, DIAMOND, PYRAMID, TRIANGLE};

// Base class for all shapes, defaults to be a square
class Shape
{
private:
    int shape_size;
    bool isFilled;
    Shape_Type shape_type;
public:
    void defineFill();
    void defineSize();
    int getSize();
    void setSize(int size);
    bool getIsFilled();
    void printFilledShape(ofstream& out_stream);
    void printHollowShape(ofstream& out_stream);
    
    // Constructors
    Shape();
    Shape(Shape_Type shape);
};

// Represents a square shape, which is default for the Shape class
class Square: public Shape
{
public:
    Square(); // Default constructor
};

// Represents a diamond shape
class Diamond: public Shape
{
public:
    Diamond();  // Default constructor
    void defineSize();
    void printFilledShape(ofstream& out_stream);
    void printHollowShape(ofstream& out_stream);
};

// Represents a pyramid shape
class Pyramid: public Shape
{
public:
    Pyramid(); // Default constructor
    void defineSize();
    void printFilledShape(ofstream& out_stream);
    void printHollowShape(ofstream& out_stream);
};

// Represents a triangle shape
class Triangle: public Shape
{
public:
    Triangle(); // Default constructor
    void defineSize();
    void printFilledShape(ofstream& out_stream);
    void printHollowShape(ofstream& out_stream);
};

#endif
