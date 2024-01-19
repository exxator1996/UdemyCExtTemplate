#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdDataLoader.h"
#include "AdFunctions.h"
#include "AdTypes.h"

#include "utils.h"

const char datapath[128] = "/mnt/c/Users/niklas/Documents/CLernen/UdemyCExtTemplate/11_Files/DataLoader/data/";

int main(int argc, char const **argv)
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    preload_ego_vehicle_data(argv[1], atoi(argv[2]));
    preload_vehicle_data(argv[1], atoi(argv[2]));

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    for (uint32_t cycle = 0; cycle < NUM_CYCLES; cycle++)
    {
        clear_console();
        load_cycle(&vehicles, cycle);

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100F);

        const VehicleType *ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, &vehicles);
        longitudinal_control(&ego_lane_vehicles[0], &ego_vehicle);

        const LaneAssociationType lane_change_request = get_lane_change_request(&ego_vehicle, &vehicles);
        const bool lane_change_executed = lateral_control(lane_change_request, &ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        sleep_console(100);
    }


    return 0;
}
