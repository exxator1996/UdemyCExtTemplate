#include <stdint.h>
#include <stdio.h>

int main()
{
    uint32_t number = 0;
    uint32_t num_digits = 0, cross_sum = 0, temp = 0, temp2 = 0;

    printf("Please enter a unsinged integer: ");
    scanf("%u", &number);

    // sum_of_digits

    temp = number;

    while (temp > 0)
    {
        temp /= 10;
        num_digits++;
    }

    printf("sum_of_digits: %u\n", num_digits);

    // cross_sum

    temp2 = number;

    while(temp2 > 0)
    {
        cross_sum +=temp2 % 10;
        temp2 /= 10;
    }
    printf("cross_sum: %d\n", cross_sum);
}
