// Program that displays the value and address of a circle's variable circumstance

#include <iostream>
#include <cmath>
using namespace std;

struct Circle
{
    int centre_x; // x value of circle centre
    int centre_y; // y value of circle centre
    int radius; // radius of circle
};

int getPositiveInteger (); // function that gets the x, y, and radius of circle

int main ()
{
    Circle theCircle; // declares theCircle as an instance in struct Circle
    Circle *pTheCircle = &theCircle; // pointer TheCircle equals to the address of the theCircle
    double circumference = 0; // circumference of circle
    double *pCircumference = &circumference; // pointer pCircumference equals to the address of the circumference
    
    cout << "Please enter the centre point and radius of the circle" << endl
         << "(format: x y radius, in positive integers.)" << endl;
    
    theCircle.centre_x = getPositiveInteger (); // gets x value of circle
    theCircle.centre_y = getPositiveInteger (); // gets y value of circle
    theCircle.radius = getPositiveInteger (); // gets radius of circle
    
    cout << endl;
    
    circumference = 2 * M_PI * theCircle.radius; // calculates circumference of circle
    
    cout << "The value of the variable circumference is: " << circumference << endl;
    cout << "The address of the variable circumference is: " << pCircumference << endl << endl;
    
    cout << "The circle's location is (" << theCircle.centre_x << ", " << theCircle.centre_y << ")" << endl;
    cout << "The circle's radius is " << theCircle.radius << endl;
    cout << "The address of the circle struct is: " << pTheCircle << endl;
    
    return 0;
}

int getPositiveInteger () // ensures that value entered are positive, integer numbers only
{
    do
    {
        int input;
        cin >> input;
        
        if (cin.good () == 0)
        {
            cout << "Invalid input! Only number inputs are allowed.\n";
            cin.clear ();
            cin.ignore (80,'\n');
            continue;
        }
        
        else if (input <= 0)
        {
            cout << "Invalid input! Only positive number inputs allowed\n";
            continue;
        }
        return input;
        
    } while (true);
}