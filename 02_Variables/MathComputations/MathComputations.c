#include <stdio.h>

int main()
{
    float x = -2.0F;
    float y = -3.0F;
    float z1, z2, z3;

    z1 = x*x + y*y - (x*y) + 2.0F;
    z2 = (x-y) * (x-y) * (x-y) -3.0F;
    z3 = (2.0F*x*x*x-0.5F*x*x-x+4.0F) / (y);

    printf("z1 = %f \n", z1);
    printf("z2 = %f \n", z2);
    printf("z3 = %f \n", z3);



    return 0;
}
