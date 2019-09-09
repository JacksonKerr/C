#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
#include "ealloc.h"
#include "quicksort.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        /* do the old "double the capacity" trick */
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity*sizeof f->items[0]);
    }/* insert the item in the last free space */
    f->items[f->itemcount] = num;
    f->itemcount++;
}

void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i;
    for (i = 0; i < f->itemcount; i++) {
        fprintf(stdout, "%d\n", f->items[i]);
    }
}

void flexarray_sort(flexarray f) {;
    quickSort(f->items, f->itemcount);
    /* mergesort would be good */
}
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
}



