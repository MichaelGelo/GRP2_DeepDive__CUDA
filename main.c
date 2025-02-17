#include <Stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <stdint.h>

#define NUM_BINS 10

void getHistogram(int* vector, int vectorSize, int* histogram) {
    for (int i = 0; i < vectorSize; i++) {
        int bIndex = vector[i] % 10;
        histogram[bIndex]++;
    }
}

int main() {
    const size_t ARRAY_SIZE = 1<<24;
    const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(double);

    int32_t *vector;
    vector = (int32_t*)malloc(ARRAY_BYTES);
    int histogram[NUM_BINS] = { 0 };
    const size_t loope = 100;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        vector[i] = i;
    }

    clock_t start, end;
    getHistogram(vector, ARRAY_SIZE, histogram);


    for (int i = 0; i < 10; i++) {
        histogram[i] = 0;
    }

    double elapse, time_taken;
    elapse = 0.0f;
    for (int i = 0; i < loope; i++) {
        for (int i = 0; i < 10; i++) {
            histogram[i] = 0;
        }
        start = clock();
        getHistogram(vector, ARRAY_SIZE, histogram);
        end = clock();
        time_taken = ((double)(end - start)) * 1E3 / CLOCKS_PER_SEC;
        elapse = elapse + time_taken;
    }
    printf("Function (in C) average time for %lu loops is %f milliseconds to execute an array size %lu \n", loope, elapse / loope, ARRAY_SIZE);

    size_t err_count = 0;
    int32_t  test[NUM_BINS] = { 0 };

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int bIndex = vector[i] % 10;
        test[bIndex]++;
    }
    for (int i = 0; i < 10; i++) {
        
        if (test[i] != histogram[i])
            err_count++;
    }
    printf("Error count (C program): %lu\n", err_count);

    for (int i = 0; i < NUM_BINS; i++) {
        printf("Bin %d: %d\n", i, histogram[i]);
    }
    
    free(vector);
	return 0;
}