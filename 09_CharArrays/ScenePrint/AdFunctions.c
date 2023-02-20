#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"


void print_scene(float speed_mps, uint32_t lane_idx)
{
    printf("\n\n");
    printf("\t  L   C   R\n");

    float offset_m = 20.0f;

    for (int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        char left_string[] = "   ";
        char center_string[] = "   ";
        char right_string[] = "   ";

        if (i == 0)
        {
            switch (lane_idx)
            {
            case LANE_ASSOCIATION_TYPE_LEFT:
            {
                strncpy(left_string, " V ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_CENTER:
            {
                strncpy(center_string, " V ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_RIGHT:
            {
                strncpy(right_string, " V ", 4);
                break;
            }
            case LANE_ASSOCIATION_TYPE_NONE:
            default:
            {
                break;
            }
            }
        }

        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }

    printf("\n");
    printf("Speed: %f\n", speed_mps);
    printf("\n");
}

void get_user_input(float *speed_mps, uint32_t *lane_idx)
{
    int8_t longitudinal_action, lateral_action;

    printf("LongitudinalAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longitudinal_action);

    printf("LateralAction (a=Left, d=right): ");
    scanf(" %c", &lateral_action);

    handle_longitudinal_user_input(speed_mps, &longitudinal_action);
    handle_lateral_user_input(lane_idx, &lateral_action);
}

void handle_lateral_user_input(uint32_t *lane_idx, int8_t *lateral_action)
{
    switch (*lateral_action)
    {
    case LATERAL_ACTION_LEFT:
        if (*lane_idx == LANE_ASSOCIATION_TYPE_LEFT)
            *lane_idx = *lane_idx;
        else
            *lane_idx -= 1;
        break;

    case LATERAL_ACTION_RIGHT:
        if (*lane_idx == LANE_ASSOCIATION_TYPE_RIGHT)
            *lane_idx = *lane_idx;
        else
            *lane_idx += 1;
        break;
    default:
        break;
    }
}

void handle_longitudinal_user_input(float *speed_mps, int8_t *longitudinal_action)
{
    switch (*longitudinal_action)
    {
    case LONGITUDINAL_ACTION_DECREASE:
        *speed_mps -= *speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        if (*speed_mps < 0)
            *speed_mps = 0;
        break;

    case LONGITUDINAL_ACTION_INCREASE:
        *speed_mps += *speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;
        break;
    default:
        break;
    }


}
