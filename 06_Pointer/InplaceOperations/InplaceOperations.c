#include <stdint.h>
#include <stdio.h>

void clamp_value(float *value, float min_value, float max_value)
{
    if (*value < min_value)
        *value = min_value;
    else if (*value > max_value)
        *value = max_value;
}

void round_value(float *value, uint8_t num_digits)
{
    int temp;

    for (int i = 0; i < num_digits; i++)
    {
        *value *= 10;
    }

    temp = *value;
    *value = temp;

    for (int i = 0; i < num_digits; i++)
    {
        *value /= 10;
    }
}

int main()
{
    float value = 2.3456f;

    clamp_value(&value, -2.0, 2.0);
    printf("%f\n", value);

    round_value(&value, 4);
    printf("%f\n", value);

    return 0;
}
