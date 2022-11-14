#include "gauss.h"

matrix* allocateMatrix(unsigned int rows, unsigned int cols) {
    // Check that rows and cols are bigger than 0
    //TODO: Diagnostic
    if (rows == 0 || cols == 0) {
        fprintf(stderr, "[ERROR] Cannot allocate a matrix of dimension 0 by 0\n");
        return NULL;
    }

    matrix* mat = (matrix*)malloc(sizeof(*mat));

    // Allocate matrix data    
    double** tempData = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++)
        tempData[i] = (double*)malloc(cols * sizeof(double));

    // TODO: Diagnostic
    if (tempData == NULL) {
        fprintf(stderr, "[ERROR] Error allocating matrix, possible due to available space\n");
        return NULL;
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

matrix* getCol(matrix* mat, unsigned int col) {
    if (col > mat->cols) { return NULL; }

    matrix* ptr = allocateMatrix(mat->rows, 1);

    for (int i = 0; i < mat->rows; i++)
        ptr->data[i][0] = mat->data[i][col - 1];

    return ptr;
}

matrix* getRow(matrix* mat, unsigned int row) {
    if (row > mat->rows) { return NULL; }

    matrix* ptr = allocateMatrix(1, mat->cols);

    for (int i = 0; i < mat->cols; i++)
        ptr->data[0][i] = mat->data[row - 1][i];

    return ptr;
}

void setCol(matrix* mat, unsigned int col, double value) {
    if (col > mat->cols) {
        fprintf(stderr, "[ERROR] Trying to set a value in column: %i, but the matrix has %i columns\n", col, mat->cols);
        return;
    }

    for (int i = 0; i < mat->rows; i++)
        mat->data[i][col] = value;

}

void setRow(matrix* mat, unsigned int row, double value) {
    if (row > mat->rows) {
        fprintf(stderr, "[ERROR] Trying to set a value in row: %i, but the matrix has %i columns\n", row, mat->cols);
        return;
    }

    for (int i = 0; i < mat->cols; i++)
        mat->data[row][i] = value;

}

void setDiagonal(matrix* mat, double value) {
    unsigned int index = 0;

    while (index < mat->rows && index < mat->cols) {
        mat->data[index][index] = value;
        index++;
    }
}

matrix* deleteRow(matrix* mat, unsigned int row) {
    if (row > mat->rows) {
        fprintf(stderr, "[ERROR] Trying to delete a row: %i, but the matrix has %i rows\n", row, mat->rows);
        return NULL;
    }

    matrix* result = allocateMatrix(mat->rows - 1, mat->cols);
    
    unsigned int result_index = 0;
    unsigned int mat_index = 0;

    while (mat_index != mat->rows) {
        if (mat_index != row - 1) {
            for (int i = 0; i < mat->cols; i++)
                result->data[result_index][i] = mat->data[mat_index][i];

            result_index++;
            mat_index++;
        } else {
            mat_index++;
        }
    }

    return result;
}

matrix* deleteCol(matrix* mat, unsigned int col) {

}

void scalarOperation(matrix* mat, double scalar, operation op) {
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            switch (op) {
                case add: mat->data[i][j] += scalar; break;
                case multiply: mat->data[i][j] *= scalar; break;
            }
}

void rowSwap(matrix* mat, unsigned int row1, unsigned int row2) {
    if (row1 > mat->rows || row2 > mat->rows) {
        fprintf(stderr, "[ERROR] Cannot acces the row since matrix has %i rows\n", mat->rows);
        return;
    }
        

    double* tmp = mat->data[row1 - 1];
    mat->data[row1 - 1] = mat->data[row2 - 1];
    mat->data[row2 - 1] = tmp;
}

void colSwap(matrix* mat, unsigned int col1, unsigned int col2) {
    if (col1 > mat->cols || col2 > mat->cols) {
        fprintf(stderr, "[ERROR] Cannot acces the row since matrix has %i rows\n", mat->rows);
        return;
    }

    for (int i = 0; i < mat->rows; i++) {
        double tmp = mat->data[i][col1 - 1];
        mat->data[i][col1 - 1] = mat->data[i][col2 - 1];
        mat->data[i][col2 - 1] = tmp;
    }
}

matrix* transpose(matrix* mat) {
    matrix* result = allocateMatrix(mat->cols, mat->rows);

    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->cols; j++)
            result->data[j][i] = mat->data[i][j];

    return result;
}

double calculateMatrixProduct(unsigned int row, unsigned int col, matrix* mat1, matrix* mat2) {
    double result = 0;

    for (int i = 0; i < mat1->cols; i++)
        result += mat1->data[row][i] * mat2->data[i][col];

    return result;
}

matrix* mulMatrix(matrix* mat1, matrix* mat2) {
    if (mat1->cols != mat2->rows) return NULL;
    
    matrix* ptr = allocateMatrix(mat1->rows, mat2->cols);

    for (int i = 0; i < ptr->rows; i++)
        for (int j = 0; j < ptr->cols; j++)
            ptr->data[i][j] = calculateMatrixProduct(i, j, mat1, mat2);

    return ptr;
}

matrix* addMatrix(matrix* mat1, matrix* mat2) {
    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) return NULL;

    matrix* ptr = allocateMatrix(mat1->rows, mat1->cols);
    for (int i = 0; i < ptr->rows; i++)
        for (int j = 0; j < ptr->cols; j++)
            ptr->data[i][j] = mat1->data[i][j] + mat2->data[i][j];

    return ptr;
}

double determinant(matrix* mat) {
    return 0;
}

matrix* inverse(matrix* mat) {
    if (mat->cols != mat->rows) return NULL;
    return NULL;
}