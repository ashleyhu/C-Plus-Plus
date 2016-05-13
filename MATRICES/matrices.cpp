// The program multiplies two matrices and writes the result to a file

#include <iostream>
#include <fstream>
#include "matrixmath.h" // Includes header file with function declaration

int main ()
{
    ifstream in_stream;
    
    int matrix1Row; // Row of matrix 1
    int matrix1Column; // Column of matrix 1
    
    matrix matrix1;
    
    int matrix2Row; // Row of matrix 2
    int matrix2Column; // Column of matrix 2
    
    matrix matrix2;
    
    // Opens the input file
    in_stream.open ("input.txt");
    
    // Checks if the file exists/is valid
    if (in_stream.fail ())
    {
        cout << "Input file opening failed.\n";
        exit (1);
    }
    
    // Reads in the dimension and values of the maxtrix in input.txt
    tryReadMatrix (in_stream, matrix1Row, matrix1Column, &matrix1); // Gets value of matrix 1
    tryReadMatrix (in_stream, matrix2Row, matrix2Column, &matrix2); // Gets value of matrix 2
    
    // Echos the matrices to console
    cout << "Echoing matrices:\n";
    printMatrix (matrix1, matrix1Row, matrix1Column);
    printMatrix (matrix2, matrix2Row, matrix2Column);
    
    matrix result;
    int resultRow; // Row resultant of matrix multiplication
    int resultColumn; // Column resultant of matrix multiplication
    
    // Multiplies matrix 1 and matrix 2
    bool succeeded = multiplyMatrices (matrix1, matrix1Row, matrix1Column, matrix2, matrix2Row, matrix2Column, &result, resultRow, resultColumn);
    
    // If the multiplication goes through, returns true
    if (!succeeded)
    {
        // If false, it means that there is an error with the multiplication (due to invalid dimensions)
        return -1;
    }
    
    // Prints out the product onto console
    cout << "Result matrix:" << endl;
    printMatrix (result, resultRow, resultColumn);
    
    // Opens output.txt
    ofstream out_stream;
    out_stream.open ("output.txt");
    
    // Writes the result to output.txt
    saveMatrixToFile (out_stream, result, resultRow, resultColumn);
    
    // Clears up dynamic array
    delete matrix1;
    delete matrix2;
    delete result;
    
    return 0;
}