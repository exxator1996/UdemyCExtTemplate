#include <stdio.h>
#include <stdint.h>

#include "AdFunctions.h"
#include "AdTypes.h"


void print_scene(float speed_mps, uint32_t lane_idx)
{

    switch (lane_idx)
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
    printf("Speed: %.6f\n", speed_mps);
}
