#ifndef MATRIX_H
#define MATRIX_H


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include"Vector.h"

/**********************/
/* DEFINES AND TYPES  */
/**********************/
typedef struct
{
    float *data;
    size_t num_rows;
    size_t num_cols;
} Matrix;

typedef enum
{
    AXIS_0,
    AXIS_1,
} Axis;


/**********************/
/*   MAIN FUNCTIONS   */
/**********************/
Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);

Matrix *freeMatrix(Matrix *matrix);

/**********************/
/*  HELPER FUNCTIONS     */
/**********************/

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);

size_t matrixNumElements(const Matrix *matrix);

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2);

bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2);

/**********************/
/*  MATH FUNCTIONS   */
/**********************/

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);

Vector *minMatrix(const Matrix *matrix, const Axis axis);

Vector *maxMatrix(const Matrix *matrix, const Axis axis);

Vector *meanMatrix(const Matrix *matrix, const Axis axis);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/
void printMatrix(const Matrix *matrix);
#endif
