#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

/* basic insertion sort*/
void insertion_sort(int *a, int n) {
    int p;
    int key;
    for (p = 1; p < n; p++) {
        key = a[p];
        while (p > 0 && a[p-1] > key) {
            a[p] = a[p-1];
            p--;
        }
        a[p] = key;
    }
}
void printArr(int *a, int len) {
    if (len == 0) {
        return;
    } else {
        printf("%d, ", a[0]);
        printArr(++a, --len);
    }
}
int binSearch(int *a, int len, int i) {
    int mid;
    if (len == 0) {
        printf("-\n");
        return 0;
    }
    mid = len/2;
    if (a[mid] == i) {
        printf("+\n");
        return 1;
    }
    if (a[mid] > i) {
        return binSearch(a, (len/2) - 1 , i);
    }
    return binSearch(&a[len/2], len/2, i);
}
int main(int argc, char **argv) {
    FILE *infile;
    int a[ARRAY_SIZE];
    int num_items;
    int i;
    printf("argc = %d\n", argc);
    if (NULL == (infile = fopen(argv[1], "r")) ) {
        fprintf(stderr, "Can't find requested file %s\n", argv[0]);
        return EXIT_FAILURE;
    }
    num_items = 0;
    while (num_items < ARRAY_SIZE && 1 == fscanf(infile, "%d", &a[num_items])) {
        num_items++;
    }
    fclose(infile);

    /*Sort items*/
    insertion_sort(a, num_items);

    /*Print Items
    printArr(a, num_items);
    printf("\n");*/

    /*Scan and compare*/
    while (1 == scanf("%d", &i)) {
        binSearch(a, num_items, i);
    }
    return EXIT_SUCCESS;
}
