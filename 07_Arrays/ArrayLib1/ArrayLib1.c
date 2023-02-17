#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

void unique_elements(int32_t *array, size_t length)
{
    int32_t currentElement = 0;
    int16_t counter = 0;

     if (array == NULL || length == 0)
    {
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        currentElement = array[i];
        counter = 0;
        for (size_t j = 0; j < length; j++)
        {
            if (currentElement == array[j])
            {
                counter++;
            }
        }
        if (counter == 1)
        {
            printf("%d\n", currentElement);
        }
    }
}

void remove_duplicates(int32_t *array, int32_t *length)
{
    if (array == NULL || length == 0)
    {
        return;
    }
    for (int32_t i = 0; i < *length; i++)
    {
        int32_t currentElement = array[i];
        int32_t duplicatePosition = -1;

        for (int32_t j = i + 1; j < *length; j++)
        {
            if (currentElement == array[j])
            {
                duplicatePosition = j;
                (*length)--;
                break;
            }
        }

        if (duplicatePosition == -1)
        {
            continue;
        }

        for (int32_t j = duplicatePosition; j < *length; j++)
        {
            array[j] = array[j + 1];
        }
    }
}

void rotate_left(int32_t *array, size_t length)
{
    if (array == NULL || length == 0)
    {
        return;
    }

    int32_t buffer = array[0];
    for (size_t i = 0; i < length - 1; i++)
    {
        array[i] = array[i + 1];
    }

    array[length - 1] = buffer;
}

void rotate_right(int32_t *array, size_t length)
{
    if (array == NULL || length == 0)
    {
        return;
    }
    int32_t buffer = array[length - 1];
    for (size_t i = length; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = buffer;
}

int main()
{
    int32_t array[] = {1, 1, 2, 3, 3, 4};
    int32_t length = 6;

    printf("unique_elements: \n");
    unique_elements(array, length);

    remove_duplicates(array, &length);
    print_int32_array(array, length);

    rotate_left(array, length);
    print_int32_array(array, length);

    rotate_right(array, length);
    print_int32_array(array, length);

    return 0;
}
