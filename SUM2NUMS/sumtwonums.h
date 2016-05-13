// A program that reads in two positive integers that are 20 or fewer digits in length and then outputs the sum of the two numbers

#ifndef sumtwonums_h
#define sumtwonums_h

bool getInput (char* array, int arrayLength); // collects char input from user, called twice to collect input twice
void newLine(); // allows for user input to be collected twice
bool getIntValue (int* digitArray, int arrayLength); // gets the integer values of the inputted char
bool convertCharArrayToIntArray(char* charArray, int* intArray, int arrayLength); // converts char array to int array
void printDigitArray(int* digitArray, int arrayLength); // function to print out the values of the first and second inputted char and the sum of both
bool addNumbers(int length, int* array1, int* array2, int* result); // sums the two values together

#endif // end of header file
