#include "Matrix.h"

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value)
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));

    if (NULL == matrix)
    {
        return NULL;
    }

    matrix->data = createArray(num_cols * num_rows, value);

    if (matrix->data == NULL)
    {
        free(matrix);
        return NULL;
    }

    matrix->num_cols = num_cols;
    matrix->num_rows = num_rows;

    return matrix;
}

Matrix *freeMatrix(Matrix *matrix)
{
    if (NULL == matrix)
    {
        return NULL;
    }

    if (matrix->data != NULL)
    {
        free(matrix->data);
        matrix->data = NULL;
    }

    free(matrix);
    return NULL;
}

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)
{
    return ((num_cols * i) + j);
}

size_t matrixNumElements(const Matrix *matrix)
{
    return matrix->num_cols * matrix->num_rows;
}

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)
{
    return ((matrix1->num_rows) == matrix2->num_rows && (matrix1->num_cols == matrix2->num_cols));
}

void printMatrix(const Matrix *matrix)
{
    if (matrix->data == NULL)
    {
        return;
    }


    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            printf("%.6f, ", matrix->data[matrixIndex(matrix->num_cols, i, j)]);
        }
        printf("\n");
    }
    printf("\n");
}

bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2)
{
    return (matrix1->num_cols == matrix2->num_rows);
}

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (!matrixSameSize(matrix1, matrix2) || matrix1 == NULL || matrix2 == NULL)
    {
        printf("Unmatching Dimensions addition imposible! \n");
        return NULL;
    }

    Matrix *matrix = createMatrix(matrix1->num_rows, matrix2->num_cols, 0);

    if (matrix == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            matrix->data[matrixIndex(matrix->num_cols, i, j)] =
                matrix1->data[matrixIndex(matrix->num_cols, i, j)] + matrix2->data[matrixIndex(matrix->num_cols, i, j)];
        }
    }
    return matrix;
}

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (!matrixSameSize(matrix1, matrix2) || matrix1 == NULL || matrix2 == NULL)
    {
        printf("Unmatching Dimensions subtraction imposible! \n");
        return NULL;
    }

    Matrix *matrix = createMatrix(matrix1->num_rows, matrix2->num_cols, 0);

    if (matrix == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            matrix->data[matrixIndex(matrix->num_cols, i, j)] =
                matrix1->data[matrixIndex(matrix->num_cols, i, j)] - matrix2->data[matrixIndex(matrix->num_cols, i, j)];
        }
    }
    return matrix;
}

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (!matrixMultiplyPossible(matrix1, matrix2))
    {
        printf("Unmatching Dimensions multiplikation imposible! \n");
        return NULL;
    }

    Matrix *matrix = createMatrix(matrix1->num_rows, matrix1->num_cols, 0);

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            for (size_t k = 0; k < matrix1->num_cols; k++)
            {
                matrix->data[matrixIndex(matrix->num_cols, i, j)] +=
                    matrix1->data[matrixIndex(matrix1->num_cols, i, k)] *
                    matrix2->data[matrixIndex(matrix2->num_cols, k, j)];
            }
        }
    }
    return matrix;
}

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if (matrix == NULL)
    {
        printf("Empty Matrix \n");
        return NULL;
    }

    Matrix *resultMatrix = createMatrix(matrix->num_rows, matrix->num_cols, 0);

    if (matrix == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            matrix->data[matrixIndex(matrix->num_cols, i, j)] =
                matrix->data[matrixIndex(matrix->num_cols, i, j)] * scalar;
        }
    }

    return resultMatrix;
}

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if (matrix == NULL)
    {
        printf("Empty Matrix \n");
        return NULL;
    }
    if (scalar == 0)
    {
        printf("Division by zero !\n");
        return NULL;
    }

    Matrix *resultMatrix = createMatrix(matrix->num_rows, matrix->num_cols, 0);
    if (matrix == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            resultMatrix->data[matrixIndex(matrix->num_cols, i, j)] =
                matrix->data[matrixIndex(matrix->num_cols, i, j)] / scalar;
        }
    }

    return resultMatrix;
}
