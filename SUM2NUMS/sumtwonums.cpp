// A program that reads in two positive integers that are 20 or fewer digits in length and then outputs the sum of the two numbers

#include "sumtwonums.h" // includes header file with function declarations
#include <iostream>
#include <cstdlib>
using namespace std;

// collects char input from user, called twice to collect input twice
bool getInput (char* array, int arrayLength)
{
    char input; // user input
    int index = 0;
    cin.get(input); // gets char input from user
    
    while (input != '\n') // '\n' signifies end of line (when user enters, the program moves on to the next put)
    {
        array[index] = input; // inputs the char values into array
        index++; // keeps track of entered digits
        
        // if character limit is exceeded, exit the program
        if (index >= arrayLength)
        {
            cout << "Exceeds the character limit." << endl;
            return false;
        }
        cin.get(input); // continues to get input until user presses enter
    }
    array[index] = '\0';
    
    return true;
}

// allows for user input to be collected twice
void newLine()
{
    char symbol;
    do
    {
        cin.get(symbol); // collects user input again
    } while (symbol != '\n'); // end of input marked by enter
}

// gets the integer values of the inputted char
bool getIntValue (int* digitArray, int arrayLength)
{
    // the raw number's length is 1 higher than the number array length that stores the null-character (end of the string)
    char rawNumber[arrayLength + 1];
    
    cout << "Enter positive integer number with up to 20 digits: ";
    
    bool succeeded = getInput (rawNumber, arrayLength + 1);
    
    // if digit count exceeds 20, program is exited
    if (!succeeded)
    {
        return false;
    }
    
    // searches for 'q' in the input, which indicates user's intention to quit
    for (int i = 0; i < arrayLength + 1; i++)
    {
        if (rawNumber[i] == '\0') // end of array marked by '\0'
        {
            break;
        }
        
        // if user input contains 'q', program is exited
        else if (rawNumber[i] == 'q')
        {
            cout << "Quitting." << endl;
            return false;
        }
    }
    
    // converts char to int if all conditions are met
    succeeded = convertCharArrayToIntArray (rawNumber, digitArray, arrayLength);
    
    // otherwise program is exited
    if (!succeeded)
    {
        return false;
    }
    
    return true;
}

// converts char array to int array
bool convertCharArrayToIntArray (char* charArray, int* digitArray, int arrayLength)
{
    // if input is 1234
    //
    // charArray[0] = '1'
    // charArray[1] = '2'
    // charArray[2] = '3'
    // charArray[3] = '4'
    // charArray[4] = '\0' // null-character
    //
    // digitArray[0] = 4
    // digitArray[1] = 3
    // digitArray[2] = 2
    // digitArray[3] = 1
    // digitArray[4] = 0
    // digitArray[5] = 0
    // digitArray[6] = 0
    // digitArray[7] = 0
    // digitArray[lastIndex] = 0
    
    
    int lastIndexOfChar = 0;
    
    while (charArray[lastIndexOfChar] != '\0') // checks for null character (signifies end of array)
    {
        lastIndexOfChar++;
    }
    
    // initialize all with zeros
    for (int i = 0; i < arrayLength; i++)
    {
        digitArray[i] = 0;
    }
    
    int digitArrayIndex = 0;
    
    for (int i = lastIndexOfChar - 1; i >= 0; i--) // exchanges the ASCII character with reference to the integer value until end of array
    {
        if (isdigit (charArray[i])) // checks if array only consists of digits (valid input)
        {
            // Converts char array to int array by performing ASCII value subtraction
            digitArray[digitArrayIndex] = (charArray[i] - '0');
            digitArrayIndex++;
        }
    }
    return true;
}

// function to print out the values of the first and second inputted char and the sum of both
void printDigitArray (int* digitArray, int arrayLength)
{
    int i = arrayLength - 1;
    
    // skip the leading zeros
    while (digitArray[i] == 0)
    {
        i--;
    }
    
    // prints a comma every three digits
    while (i >= 0)
    {
        cout << digitArray[i];
        if (i % 3 == 0 && i != 0)
        {
            cout << ",";
        }
        i--;
    }
}

// sums the two values together
bool addNumbers (int length, int* array1, int* array2, int* result)
{
    // Assume that all of the arrays have the same length
    // array1 = {4,3,2,1,0,0,0,0,0,0}      1234
    // array2 = {9,8,7,6,5,0,0,0,0,0}   + 56789
    // result = {3,2,0,8,5,0,0,0,0,0}   = 58023
    
    int sum = 0; // variable that carries the sum of array
    int carryOver = 0; // indicates the leftover value in each column addition of the array that will be added to the left column
    
    // i allows the sum to add the values in each respective column of the array
    for (int i = 0; i < length; i++)
    {
        sum = array1[i] + array2[i] + carryOver;
        result[i] = sum % 10; // the value of the addition in currenty coloumn
        carryOver = sum / 10; // the leftover value carried to next column
    }
    
    // overflow if there is numeric value in the final carryOver
    if (carryOver != 0)
    {
        cout << "Overflow error. Try again." << endl;
        return false;
    }
    
    return true;
}

