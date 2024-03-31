#include <assert.h>
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 100000000
#define NUM_RUNS 10
#define THREAD_COUNT 10

void *threadRunner(void *arr_p)
{

    float *arr = (float *)(arr_p);

    double *result = (double *)malloc(sizeof(double));

    for (int i = 0; i < (LENGTH / THREAD_COUNT); i++)
    {
        *result += arr[i];
    }

    pthread_exit((void *)(result));
}

double serial_sum(float *arr, size_t arr_length)
{
    double result = 0;
    for (size_t i = 0; i < arr_length; i++)
    {
        result += arr[i];
    }

    return result;
}

double parallel_sum(float *arr, size_t arr_length)
{
    double result = 0;
    size_t threadCount = THREAD_COUNT;
    size_t threadLength = arr_length / threadCount;

    pthread_t threads[threadCount];
    double *results[threadCount];

    for (size_t i = 0; i < threadCount; ++i)
    {
        pthread_create(&threads[i], NULL, &threadRunner, (void *)(&arr[i * threadLength]));
    }

    for (size_t i = 0; i < threadCount; ++i)
    {
        pthread_join(threads[i], (void *)(&results[i]));
    }

    for (size_t i = 0; i < threadCount; ++i)
    {
        result += *results[i];
    }


    return result;
}

int main()
{
    double result_serial = 0;
    double result_parallel = 0;

    float *arr = (float *)malloc(LENGTH * sizeof(float));

    for (size_t i = 0; i < LENGTH; i++)
    {
        if ((i % 2) == 0)
        {
            arr[i] = 1.0F;
        }
        else
        {
            arr[i] = 2.0F;
        }
    }

    double total_time = 0.0;

    const time_t serial_start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        result_serial = serial_sum(arr, LENGTH);
    }
    const time_t serial_end = time(NULL);
    total_time = (difftime(serial_end, serial_start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Serial - Mean execution time: %.2lf ms\n", total_time);
    printf("Result Serial: %lf\n", result_serial);

    total_time = 0.0;

    const time_t parallel_start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        result_parallel = parallel_sum(arr, LENGTH);
    }
    const time_t parallel_end = time(NULL);
    total_time = (difftime(parallel_end, parallel_start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Parall - Mean execution time: %.2lf ms\n", total_time);
    printf("Result Parallel: %lf\n", result_parallel);

    free(arr);
    arr = NULL;

    return 0;
}
