#include <stdint.h>
#include <stdio.h>

enum LaneAssociationType{
    LANE_ASSOCIATION_TYPE_NONE,
    LANE_ASSOCIATION_TYPE_LEFT,
    LANE_ASSOCIATION_TYPE_CENTER,
    LANE_ASSOCIATION_TYPE_RIGHT
};

int main()
{
    uint32_t lane;
    float speed;

    printf("Create the properties of a vehicle.\n");

    printf("Speed in m/s: ");
    scanf("%f",&speed);

    printf("Lane (1=Left, 2=Center, 3=Right): ");
    scanf("%u",&lane);

    switch (lane)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
        printf("| V |   |   |");
        break;
    case LANE_ASSOCIATION_TYPE_CENTER:
        printf("|   | V |   |");
        break;
    case LANE_ASSOCIATION_TYPE_RIGHT:
        printf("|   |   | V |");
        break;
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
        printf("|   |   |   |");
        break;
    }


    printf("\n\n");

    printf("Speed: %.6f\n", speed);


    return 0;
}
