#include <stdio.h>
#include <stdlib.h>
void printDupe(int* a, int len) {
    int tally = 0;
    int test;
    int i;
    for (test = 0; test < len; test++) {
        for (i = 0; i < len; i++) {
            if (test == a[i]) {
                tally++;
            }
        }
        if (tally > 1) {
            printf("%d occurs %d times\n", test, tally);
        }
        tally = 0;
    }
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    printf("Enter the size of the array:");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("\nWhat's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    printDupe(my_array, array_size);
    free(my_array);
    return EXIT_SUCCESS;
}
