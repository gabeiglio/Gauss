#include <stdio.h>
#include "gauss.h"

int main(int argc, char* argv[]) {
    
    matrix* mat1 = initMatrixRandomized(1, 1);
    printMatrix(mat1);

    printf("\n");

    matrix* mat2 = initMatrixRandomized(1, 1);
    printMatrix(mat2);

    printf("\n");

    matrix* result = concatenate(mat1, mat2);
    printMatrix(result);

    freeMatrix(mat1);
    freeMatrix(mat2);
    freeMatrix(result);
    
}