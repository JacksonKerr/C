#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void *emalloc(size_t s) {
    void* result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
void *erealloc(void* a, size_t s) {
    void* result = realloc(a, s);
    if (result == NULL) {
        fprintf(stderr, "Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};
flexarray flexarray_new() {
    /* initialise flexarray structure (including items array) */
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity*sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    /* add an item to the flexarray, expanding as necessary */
    if (f->itemcount < f->capacity) {
        f->items[f->itemcount] = num;
        f->itemcount += 1;
    } else {
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity*sizeof f->items[0]);
        flexarray_append(f, num);
    }
}
void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i = 0;
    for (i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    /* sort into ascending order */
    int toMove;
    int cLocal;
    int temp;
    for (toMove = 1; toMove < f->itemcount; toMove++) {
        cLocal = toMove;
        if (toMove == f->itemcount/2) {
            for (temp = 0; temp < f->itemcount; temp++) {
                fprintf(stderr, "%d\n", f->items[temp]);
            }
        }
        while (cLocal > 0 && f->items[cLocal] < f->items[cLocal-1]) {
            temp = f->items[cLocal];
            f->items[cLocal] = f->items[cLocal-1];
            f->items[cLocal-1] = temp;
            cLocal--;
        }
        
    }
}
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
}