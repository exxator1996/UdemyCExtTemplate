#include <stdint.h>
#include <stdio.h>

#include "AdConstants.h"
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
    }
}
