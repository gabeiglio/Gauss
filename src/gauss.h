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

// All initializers of matrix
void initMatrixFromInput(matrix* mat);
void initMatrixFromFilepath(matrix* mat, const char* filepath);
void initMatrixRandomized(matrix* mat, unsigned int rows, unsigned int cols);
void initMatrixFromArray(matrix* mat, unsigned int rows, unsigned int cols, double* arr);
void initMatrixWithValue(matrix* mat, unsigned int rows, unsigned int cols, double value);

// matrix destructor
void freeMatrix(matrix* mat); 

// outputting matrix
void printMatrix(matrix* mat);
void writeMatrix(matrix* mat, const char* filepath);

#endif