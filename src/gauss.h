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
void initMatrixFromInput(matrix* mat);
void initMatrixFromFilepath(matrix* mat, const char* filepath);
void initMatrixRandomized(matrix* mat, unsigned int rows, unsigned int cols);
void initMatrixFromArray(matrix* mat, unsigned int rows, unsigned int cols, double* arr);
void initMatrixWithValue(matrix* mat, unsigned int rows, unsigned int cols, double value);

// Matrix destructor
void freeMatrix(matrix* mat); 

// Outputting matrix
void printMatrix(matrix* mat);
void writeMatrix(matrix* mat, const char* filepath);

// Scalar operations
void scalarOperation(matrix* mat, double scalar, );


// Basic matrix operations
void rowSwap(matrix* mat, unsigned int row1, unsigned int row2);
void colSwap(matrix* mat, unsigned int col1, unsigned int col2);
void transpose(matrix* output, matrix* input);
void addMatrix(matrix* result, matrix* mat1, matrix* mat2);
void multiplyMatrix(matrix* result, matrix* mat1, matrix* mat2);

#endif