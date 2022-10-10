#ifndef gauss_h
#define gauss_h

#include <stdio.h>

typedef struct {
    unsigned int rows, cols;
    double** data;
} matrix;

// All initializers of matrix
void initMatrixFromInput(matrix* mat, unsigned int rows, unsigned int cols);
void initMatrixRandomized(matrix* mat, unsigned int rows, unsigned int cols);
void initMatrixFromArray(matrix* mat, unsigned int rows, unsigned int cols, double* arr);
void initMatrixWithValue(matrix* mat, unsigned int rows, unsigned int cols, double value);
void initMatrixFromFile(matrix* mat, unsigned int rows, unsigned int cols, const char* filepath);

// matrix destructor
void freeMatrix(matrix* mat);

// outputting matrix
void printMatrix(matrix* mat);
void writeMatrix(matrix* mat, const char* filepath);



#endif