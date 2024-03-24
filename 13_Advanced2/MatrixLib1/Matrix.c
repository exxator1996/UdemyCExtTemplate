#include "Matrix.h"
#include <stdarg.h>

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value)
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));

    if (NULL == matrix)
    {
        return NULL;
    }

    matrix->data = createArray((unsigned int)(num_cols * num_rows), value);

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

void setMatrixValues(Matrix *matrix, size_t count, ...){
    va_list args;
    va_start(args, count);

    size_t num_elements = matrixNumElements(matrix);

    size_t range = (count > num_elements) ? num_elements: count;

    for (size_t i = 0; i < range; i++)
    {
        matrix->data[i] = (float)va_arg(args, double);
    }

    va_end(args);
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

Vector *minMatrix(const Matrix *matrix, const Axis axis)
{
    if (matrix == NULL)
    {
        return NULL;
    }

    Vector *vector;

    int previous_value = 0;

    if (axis == AXIS_0)
    {
        vector = createVector((unsigned int)(matrix->num_cols), 0);
        if (vector == NULL)
        {
            return NULL;
        }


        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            previous_value = matrix->data[matrixIndex(matrix->num_cols, 0, j)];

            for (size_t i = 1; i < matrix->num_rows; i++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] < previous_value)
                {
                    previous_value = matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[j] = previous_value;
        }
    }
    else if (axis == AXIS_1)
    {
        vector = createVector(matrix->num_rows, 0);
        if (vector == NULL)
        {
            return NULL;
        }
        for (size_t i = 0; i < matrix->num_rows; i++)
        {
            previous_value = matrix->data[matrixIndex(matrix->num_cols, i, 0)];
            for (size_t j = 0; j < matrix->num_cols; j++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] < previous_value)
                {
                    previous_value = matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[i] = previous_value;
        }
    }
    return vector;
}

Vector *maxMatrix(const Matrix *matrix, const Axis axis)
{
    if (matrix == NULL)
    {
        return NULL;
    }

    Vector *vector;

    int previous_value = 0;

    if (axis == AXIS_0)
    {
        vector = createVector(matrix->num_cols, 0);
        if (vector == NULL)
        {
            return NULL;
        }


        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            previous_value = matrix->data[matrixIndex(matrix->num_cols, 0, j)];

            for (size_t i = 1; i < matrix->num_rows; i++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] > previous_value)
                {
                    previous_value = matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[j] = previous_value;
        }
    }
    else if (axis == AXIS_1)
    {
        vector = createVector(matrix->num_rows, 0);
        if (vector == NULL)
        {
            return NULL;
        }
        for (size_t i = 0; i < matrix->num_rows; i++)
        {
            previous_value = matrix->data[matrixIndex(matrix->num_cols, i, 0)];
            for (size_t j = 0; j < matrix->num_cols; j++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] > previous_value)
                {
                    previous_value = matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[i] = previous_value;
        }
    }
    return vector;
}

Vector *meanMatrix(const Matrix *matrix, const Axis axis)
{
    if (matrix == NULL)
    {
        return NULL;
    }

    Vector *vector;

    int mean = 0;

    if (axis == AXIS_0)
    {
        vector = createVector(matrix->num_cols, 0);
        if (vector == NULL)
        {
            return NULL;
        }


        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            mean = matrix->data[matrixIndex(matrix->num_cols, 0, j)];

            for (size_t i = 1; i < matrix->num_rows; i++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] > mean)
                {
                    mean += matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[j] = mean / (float)matrix->num_rows;
        }
    }
    else if (axis == AXIS_1)
    {
        vector = createVector(matrix->num_rows, 0);
        if (vector == NULL)
        {
            return NULL;
        }
        for (size_t i = 0; i < matrix->num_rows; i++)
        {
            mean = matrix->data[matrixIndex(matrix->num_cols, i, 0)];
            for (size_t j = 0; j < matrix->num_cols; j++)
            {
                if (matrix->data[matrixIndex(matrix->num_cols, i, j)] > mean)
                {
                    mean += matrix->data[matrixIndex(matrix->num_cols, i, j)];
                }
            }
            vector->data[i] = mean / (float)matrix->num_cols;
        }
    }
    return vector;
}

Matrix *matrixTranspose(const Matrix *matrix)
{
    Matrix *transposedMatrix = createMatrix(matrix->num_cols, matrix->num_rows, 1);

    for (int i = 0; i < matrix->num_rows; i++)
    {
        for (int j = 0; j < matrix->num_cols; j++)
        {
            transposedMatrix->data[matrixIndex(transposedMatrix->num_cols, j, i)] =
                matrix->data[matrixIndex(matrix->num_cols, i, j)];
        }
    }

    return transposedMatrix;
}

bool matrixMultiplyByVectorPossible(const Matrix *matrix, const Vector *vector)
{
    if (matrix->num_cols == vector->length)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Vector *multiplyMatrixByVector(const Matrix *matrix, const Vector *vector)
{
    if (!matrixMultiplyByVectorPossible(matrix, vector))
    {
        return NULL;
    }

    Vector *resultVector = createVector(matrix->num_rows, 0);

    for (int i = 0; i < matrix->num_rows; i++)
    {
        for (int j = 0; j < matrix->num_cols; j++)
        {
            resultVector->data[i] += vector->data[j] * matrix->data[matrixIndex(matrix->num_cols, i, j)];
        }
    }
    return resultVector;
}
