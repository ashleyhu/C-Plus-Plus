// The program multiplies two matrices and writes the result to a file

#include <iostream>
#include <fstream>
#include "matrixmath.h" // Includes header file with function declaration


// Reads in the dimensions and values of the maxtrices in input.txt
void tryReadMatrix (ifstream& inputStream, int& row, int& column, matrix* array)
{
    // Gets the dimensions of the matrix
    inputStream >> row >> column;

    // Creates the first dimension of the array (number of rows)
    *array = new int*[row];
    
    for (int i = 0; i < row; i++)
    {
        // Creates the second dimension of the array (number of columns)
        (*array)[i] = new int[column];
        
        for (int j = 0; j < column; j++) // Loops until each row* * column in the array is filled
        {
            inputStream >> (*array)[i][j];
        }
    }
}

// Uses a for loop to print matrix that has been read in
void printMatrix (matrix array, int row, int column)
{
    cout << "Dimension of matrix: " << row << " x " << column  << endl;
    
    for (int i = 0; i < row; i++) // Loops through each row of matrix
    {
        for (int j = 0; j < column; j++) // Prints the value in each column of each row
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// Performs multiplication if the 2 matrices are multiplicable
bool multiplyMatrices (matrix matrix1, int matrix1Row, int matrix1Column, matrix matrix2, int matrix2Row, int matrix2Column, matrix* result, int& resultRow, int& resultColumn)
{
    // Check if the two matrices are multiplicable (number of column of matrix 1 = number of rows of matrix 2)
    if (matrix1Column != matrix2Row)
    {
        cout << "Incompatible matrices for multiplication." << endl;
        return false;
    }
    
    resultRow = matrix1Row;
    resultColumn = matrix2Column;
    
    // Creates the resultant array as dynamic array of size resultRow x resultColumn
    *result = new int*[resultRow];
    
    for (int i = 0; i < resultRow; i++)
    {
        (*result)[i] = new int[resultColumn];
    }

    // Loops through each row and column and adds up the respective products
    for (int i = 0; i < resultRow; i++) // Loops through each row
    {
        for (int j = 0; j < resultColumn; j++) // Loops through each column
        {
            (*result)[i][j] = 0;
            
            // Adds the product of each of the entries
            for (int k = 0; k < matrix1Column; k++)
            {
                (*result)[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    return true;
}

// Saves the product of the matrices to output.txt
void saveMatrixToFile (ostream& outputStream, matrix array, int row, int column)
{
    outputStream << row << " " << column << endl;
    
    for (int i = 0; i < row; i++) // Loops through value of each row
    {
        for (int j = 0; j < column; j++) // Loops through value of each column within each row
        {
            outputStream << array[i][j] << " ";
        }
        outputStream << endl;
    }
}
