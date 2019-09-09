#include <stdio.h>
#include <stdlib.h>
void printRepeats(int* array, int len) {
    int occurences = 0;
    int cRepeat = 0;
    int i = 0;
    for (cRepeat = 0; cRepeat < len; cRepeat++) {
        for (i = 0; i < len; i++) {
            if (cRepeat == array[i]) {
                occurences++;
            }
        }
        if (occurences > 1) {
            printf("%d occurs %d times\n", cRepeat, occurences);
        }
        occurences = 0;
    }
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    printf("Enter the size of the array:");
    scanf("%d", &array_size);
    printf("\n");
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    printRepeats(my_array, array_size);
    free(my_array);
    return EXIT_SUCCESS;
}
