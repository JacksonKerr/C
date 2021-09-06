#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void find(int *a, int **l, int **s) {
    int i = 0;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Index=%d ", i);
        if (a[i] > **l) {
            *l = &a[i];
            printf("isLarger ");
        }
        if (a[i] < **s) {
            *s = &a[i];
            printf("isSmaller ");
        }
    }
    printf("\nfind: Smallest = %d, Largest = %d\n", **s, **l);
    return;
}

int main(void) {
    int array[ARRAY_SIZE] = {3, 2, 1, 2, 2, 10, 2, 2, 2, 4};
    int *smallest = array;
    int *largest  = array;
    
    find(array, &largest, &smallest);
    printf("main: Smallest = %d, Largest = %d\n", *smallest, *largest);
    return EXIT_SUCCESS;
}
