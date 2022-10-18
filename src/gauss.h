#ifndef gauss_h
#define gauss_h


#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    unsigned int rows, cols;
    double** data;
} matrix;

typedef enum {
    add,
    substract,
    multiply,
    divide
} operation;

// All initializers of matrix
matrix* initMatrixFromInput();
matrix* initMatrixFromFilepath(const char* filepath);
matrix* initMatrixRandomized(unsigned int rows, unsigned int cols);
matrix* initMatrixFromArray(unsigned int rows, unsigned int cols, double* arr);
matrix* initMatrixWithValue(unsigned int rows, unsigned int cols, double value);

// Matrix destructor
void freeMatrix(matrix* mat); 

// Outputting matrix
void printMatrix(matrix* mat);
void writeMatrix(matrix* mat, const char* filepath);

// Getters and Setters
matrix* getCol(matrix* mat, unsigned int col);
matrix* getRow(matrix* mat, unsigned int row);

// Scalar operations
void scalarOperation(matrix* mat, double scalar, operation op);

// Basic matrix operations
void rowSwap(matrix* mat, unsigned int row1, unsigned int row2);
void colSwap(matrix* mat, unsigned int col1, unsigned int col2);

matrix* transpose(matrix* mat);
matrix* addMatrix(matrix* mat1, matrix* mat2);
matrix* multiplyMatrix(matrix* mat1, matrix* mat2);

#endif