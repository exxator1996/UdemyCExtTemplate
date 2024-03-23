#include "Timer.h"
#include <time.h>

double get_timing_milliseconds(const clock_t *time_start, const clock_t *time_end)
{
    return 1000.0 * (double)(*time_end - *time_start) / (double)CLOCKS_PER_SEC;
}

double get_timing_microseconds(const clock_t *time_start, const clock_t *time_end)
{
    return 1000.0 * get_timing_milliseconds(time_start, time_end);
}
double get_timing_nanoseconds(const clock_t *time_start, const clock_t *time_end)
{
    return 1000.0 * get_timing_microseconds(time_start, time_end);
}
