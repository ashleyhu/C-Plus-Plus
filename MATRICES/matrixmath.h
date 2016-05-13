// The program multiplies two matrices and writes the result to a file

#include <iostream>
#include <fstream>
using namespace std;

#ifndef matricemath_h
#define matricemath_h

typedef int** matrix;

void tryReadMatrix (ifstream& inputStream, int& row, int& column, matrix* array); // Reads in the dimensions and values of the maxtrices in input.txt

void printMatrix (matrix array, int row, int column); // Uses a for loop to print matrix that has been read in

bool multiplyMatrices (matrix matrix1, int matrix1Row, int matrix1Column, matrix matrix2, int matrix2Row, int matrix2Column, matrix* result, int& resultRow, int& resultColumn); // Performs multiplication if the 2 matrices are multiplicable

void saveMatrixToFile (ostream& outputStream, matrix array, int row, int column); // Saves the product of the matrices to output.txt

#endif
