#include <stdio.h>
#include <stdlib.h>

int  repeated(int *a, int size);

int main(void) {
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;printf("Enter the size of the array: ");
    scanf("%d", &array_size);
    
    /* initialise the array to the appropriate size */
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    
    for (i = 0; i < array_size; i++) {
        my_dynamic_array[i] = rand() % array_size;
    }
    
    printf("\nBefore:           ");
    for (i = 0; i < array_size; i++) {
        printf("%d", my_dynamic_array[i]);
    }
    
    
    repeated(my_dynamic_array, array_size);

    printf("\nAfter:            ");
    for (i = 0; i < array_size; i++) {
        printf("%d", my_dynamic_array[i]);
    }
    free(my_dynamic_array);
    return EXIT_SUCCESS;
}
int  repeated(int *a, int size) {
    int *array;
    int i = 0;
    array = malloc(size * sizeof array[0]);
    for (i = 0; i < size; i++) {
        array[i] = 0;
    }

    for (i = 0; i < size; i++) {
        array[a[i]] += 1;
    }

    printf("\nHow many of each: ");
    for (i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    return 1;
}
