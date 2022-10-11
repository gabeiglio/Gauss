#include "gauss.h"

void allocateMatrix(matrix* mat, unsigned int rows, unsigned int cols) {
    // Check that rows and cols are bigger than 0
    //TODO: Diagnostic
    if (rows == 0 || cols == 0) {
        //return NULL;
    }

    // Allocate matrix data    
    double** tempData = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++)
        tempData[i] = (double*)malloc(cols * sizeof(double));

    // TODO: Diagnostic
    if (tempData == NULL) {
        //return NULL;
    }
    
    mat->rows = rows;
    mat->cols = cols;
    mat->data = tempData;
}

void initMatrixFromInput(matrix* mat, unsigned int rows, unsigned int cols) {
    allocateMatrix(mat, rows, cols);


}

void initMatrixRandomized(matrix* mat, unsigned int rows, unsigned int cols) {
    allocateMatrix(mat, rows, cols);

    srand(time(0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat->data[i][j] = (rand() % (101));

}

void initMatrixFromArray(matrix* mat, unsigned int rows, unsigned int cols, double* arr) {
    allocateMatrix(mat, rows, cols);

    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            mat->data[i][j] = arr[(i * cols) + j];

}

void initMatrixWithValue(matrix* mat, unsigned int rows, unsigned int cols, double value) {
    allocateMatrix(mat, rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat->data[i][j] = value;

}

void initMatrixFromFilepath(matrix* mat, unsigned int rows, unsigned int cols, const char* filepath) {
    allocateMatrix(mat, rows, cols);

    FILE* inputFile = fopen(filepath, "r");

    if (!inputFile) {
        //TODO: Diagnostic
    }

    fclose(inputFile);
}

void freeMatrix(matrix* mat) {
    mat->rows = 0;
    mat->cols = 0;

    for (int i = 0; i < mat->rows; i++)
        free(mat->data[i]);

    free(mat->data);
}

void printMatrix(matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%f ", mat->data[i][j]);
        }
        printf("\n");
    }
}