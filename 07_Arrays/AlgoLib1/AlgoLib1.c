#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool all_of(int32_t *array, size_t length, int32_t value)
{
    bool is_true;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] != value)
        {
            is_true = false;
            return is_true;
        }
        else
        {
            is_true = true;
        }
    }

    return is_true;
}

bool any_of(int32_t *array, size_t length, int32_t value)
{
    bool is_true;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            is_true = true;
            return is_true;
        }
        else
        {
            is_true = false;
        }
    }

    return is_true;
}

bool none_of(int32_t *array, size_t length, int32_t value)
{
    bool is_true;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            is_true = false;
            return is_true;
        }
        else
        {
            is_true = true;
        }
    }

    return is_true;
}

size_t count(int32_t *array, size_t length, int32_t value)
{
    size_t count = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (array[i] == value)
        {
            count++;
        }
    }

    return count;
}


int main()
{
    int32_t array[] = {5,5,5,5};
    size_t length = 4;

    printf("all_of: %d\n", all_of(array, length, 6));
    printf("any_of: %d\n", any_of(array, length, 6));
    printf("none_of: %d\n", none_of(array, length, 6));
    printf("count of 1: %lu", count(array, length, 5));

    return 0;
}
