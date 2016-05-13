// A program that reads in two positive integers that are 20 or fewer digits in length and then outputs the sum of the two numbers

#include "sumtwonums.h" // includes header file with function declarations
#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 20; // should be able to change the maximum length of the integers by changing only one globally defined constant

int main()
{
    int number1[SIZE]; // int value of first inputted char
    int number2[SIZE]; // int value of second inputted char
    int result[SIZE]; // sums up to the two int values
    bool succeeded = true; // checks if user wants to quit program
    
    while (true)
    {
        cout << "Enter numbers for adding ('q' to quit at anytime)" << endl;
        
        succeeded = getIntValue (number1, SIZE);
        
        // exit program if conditions are not met (stated in the sumtwonums.cpp file)
        if (!succeeded)
        {
            return 1;
        }

        succeeded = getIntValue (number2, SIZE);
        if (!succeeded)
        {
            // exit program
            return 1;
        }
        
        // prints int value of first inputted char
        cout << "First number: ";
        printDigitArray(number1, SIZE);
        cout << endl;
        
        // prints int value of second inputted char
        cout << "Second number: ";
        printDigitArray(number2, SIZE);
        cout << endl;
        
        succeeded = addNumbers(SIZE, number1, number2, result);
        
        // adds array if all conditions are met (stated in the sumtwonums.cpp file)
        if (succeeded)
        {
            cout << "Sum of both arrays: ";
            printDigitArray(result, SIZE);
            cout << endl;
        }
        
        cout << endl;
    }
    return 0;
}






