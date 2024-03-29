#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* basic insertion sort*/
void insertion_sort(int *a, int n) {
    int p;
    int key;
    for (p = 1; p <= n; p++) {
        key = a[p];
        while (p > 0 && a[p-1] > key) {
            a[p] = a[p-1];
            p--;
        }
        a[p] = key;
    }
}

int main(void) {
    int my_array[ARRAY_MAX];
    int i, count = 0;
    clock_t start, end;

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
    fprintf(stderr, "%d %f\n", count, (end - start)/(double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
