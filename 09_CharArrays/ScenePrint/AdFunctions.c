#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdConstants.h"
#include "AdFunctions.h"
#include "AdTypes.h"


void print_scene(float speed_mps, uint32_t lane_idx)
{

    char rowTop[] = "\t\t  L   C   R";

    char rowWithoutVehicle[] = "\t|   |   |   |";
    char rowWithVehicleLeft[] = "\t| V |   |   |";
    char rowWithVehicleCenter[] = "\t|   | V |   |";
    char rowWithVehicleRight[] = "\t|   |   | V |";

    char street[11][15];

    for (int i = 0; i < 11; i++)
    {
        strcpy(street[i], rowWithoutVehicle);
    }


    switch (lane_idx)
    {
    case LANE_ASSOCIATION_TYPE_LEFT:
        strcpy(street[5], rowWithVehicleLeft);
        break;
    case LANE_ASSOCIATION_TYPE_CENTER:
        strcpy(street[5], rowWithVehicleCenter);
        break;
    case LANE_ASSOCIATION_TYPE_RIGHT:
        strcpy(street[5], rowWithVehicleRight);
        break;
    case LANE_ASSOCIATION_TYPE_NONE:
    default:
        strcpy(street[5], rowWithoutVehicle);
        break;
    }

    printf("%s\n", rowTop);

    for (int j = 0; j < 11; j++)
    {
        printf("%d\t%s\n", (100 - j * 20),street[j]);
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
