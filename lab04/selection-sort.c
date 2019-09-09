#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/*A basic selection sort*/
void insertion_sort(int *a, int n) {
    int i;
    int x;
    int *smallest;
    for (i = 0; i <= n; i++) {
        smallest = &a[i];
        for (x = i + 1; x <= n; x++) {
            if (a[x] < *smallest) {
                smallest = &a[x];
            }
        }
        x = a[i];
        a[i] = *smallest;
        *smallest = x;
    }
}

int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end; 
    int i, count = 0;

    /*Fill array*/
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    /*Sort while timer counts*/
    start = clock();
    insertion_sort(my_array, count);
    end = clock();
    
    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    
    /*Print array length*/
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
