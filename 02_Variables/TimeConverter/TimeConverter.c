#include <stdio.h>

int main()
{
    float millisconds = 0.0F;
    float seconds, minutes, hours, days;

    printf("Please enter a millisecond value: ");
    scanf("%f", &millisconds);

    seconds = millisconds / 1000.0F;
    minutes = seconds / 60.0F;
    hours = minutes / 60.0F;
    days = hours / 24.0F;

    printf("seconds: %f\n", seconds);
    printf("minutes: %f\n", minutes);
    printf("hours: %f\n", hours);
    printf("days: %f\n", days);

    return 0;
}
