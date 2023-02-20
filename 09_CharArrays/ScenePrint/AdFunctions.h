#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H
#include <stdint.h>

void print_scene(float speed_mps, uint32_t lane_idx);

void get_user_input(float *speed_mps, uint32_t *lane_idx);

void handle_lateral_user_input(uint32_t *lane_idx, int8_t *lateral_action);

void handle_longitudinal_user_input(float *speed_mps, int8_t *longitudinal_action);

#endif
