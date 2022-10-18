#include "gauss.h"

matrix* allocateMatrix(unsigned int rows, unsigned int cols) {
    // Check that rows and cols are bigger than 0
    //TODO: Diagnostic
    if (rows == 0 || cols == 0) {
        //return NULL;
    }

    matrix* mat = (matrix*)malloc(sizeof(*mat));

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

    return mat;
}

matrix* initMatrixFromInput() {
    unsigned int rows, cols;

    fscanf(stdin, "%i %i", &rows, &cols);
    matrix* mat = allocateMatrix(rows, cols);


    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            fscanf(stdin, "%lf", &mat->data[i][j]);


    return mat;
}

matrix* initMatrixRandomized(unsigned int rows, unsigned int cols) {
    matrix* mat = allocateMatrix(rows, cols);

    srand(time(0));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat->data[i][j] = (rand() % (101));

    return mat;
}

matrix* initMatrixFromArray(unsigned int rows, unsigned int cols, double* arr) {
    matrix* mat = allocateMatrix(rows, cols);

    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            mat->data[i][j] = arr[(i * cols) + j];

    return mat;
}

matrix* initMatrixWithValue(unsigned int rows, unsigned int cols, double value) {
    matrix* mat = allocateMatrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat->data[i][j] = value;

    return mat;
}

matrix* initMatrixFromFilepath(const char* filepath) {
    FILE* inputFile = fopen(filepath, "r");

    if (!inputFile) {
        //TODO: Diagnostic
    }

    unsigned int rows, cols;
    fscanf(inputFile, "%i %i", &rows, &cols);

    matrix* mat = allocateMatrix(rows, cols);

    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            fscanf(inputFile, "%lf", &mat->data[i][j]);

    fclose(inputFile);
    return mat;
}

void freeMatrix(matrix* mat) {
    mat->rows = 0;
    mat->cols = 0;

    for (int i = 0; i < mat->rows; i++)
        free(mat->data[i]);

    free(mat->data);
    free(mat);
}

void printMatrix(matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void writeMatrix(matrix* mat, const char* filepath) {
    FILE* outputFile = fopen(filepath, "w");

    fputc('a', outputFile);

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            fputc(mat->data[i][j], outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(outputFile);
}

matrix* getColumn(matrix* mat, unsigned int col) {
    if (col > mat->cols) { return NULL; }

    matrix* ptr = allocateMatrix(mat->rows, 1);

    for (int i = 0; i < mat->rows; i++)
        ptr->data[i][0] = mat->data[i][col - 1];

    return ptr;
}

matrix* getRow(matrix* mat, unsigned int row) {

}