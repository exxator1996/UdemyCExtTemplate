#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    // calculate_pi
    uint32_t num_iterations = 1000000;
    double pi_calculated = 0.0;

    for (uint32_t i = 0; i <= num_iterations; i++)
    {
        pi_calculated += 1.0/(4.0*i+1.0) - 1.0/(4.0*i+3.0);
    }

    pi_calculated *= 4;

    double pi = 3.14159265358979323846;
    printf("pi (calculated): %.20lf\n", pi_calculated);
    printf("pi (correct):    %.20lf\n", pi);

    // print_dec_to_bin
    uint8_t dec = 43;
    uint8_t temp = dec;
    uint32_t temp2 = 1;
    uint16_t counter = 0.0;
    uint32_t bin = 0;
    while(temp > 0)
    {
        if(temp % 2 == 1){
            temp2 = 1;
            for (int i = 0; i < counter; i++)
            {
                temp2 *= 10;
            }
            bin += temp2;
        }
        temp /= 2;
        counter++;
    }

    printf("Bin: %d \n", bin);

    return 0;
}
