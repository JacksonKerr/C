#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    return result;
}
void* erealloc(int* a, size_t s) {
    void* result = realloc(a, s);
    if (result == NULL) {
        fprintf(stderr, "MEMORY ALLOCATION FAILED");
        exit(EXIT_FAILURE);
    }
    return result;
}
struct flexarrayrec {
    int* a;
    int len;
    int maxLen;
};
void flex_print(flexarray f) {
    int i;
    for (i = 0; i < f->len; i++) {
        printf("%d\n", f->a[i]);
    }
}
flexarray flex_new() {
    flexarray result = emalloc(sizeof *result);
    result->maxLen = 2;
    result->len = 0;
    result->a = emalloc(result->maxLen * sizeof result->a[0]);
    return result;
}
void flex_add(flexarray f, int num) {
    if (f->len < f->maxLen) {
        f->a[f->len] = num;
        f->len += 1;
    } else {
        f->maxLen *= 2;
        f->a = erealloc(f->a, f->maxLen * sizeof f->a[0]);
        flex_add(f, num);
        return;
    }
}
void flex_sort(flexarray f) {
    int toMove = f->len;
    int x;
    int temp;
    for (toMove = 0; toMove > f->len-1; toMove++) {
        x = toMove;
        while (x > 0 && f->a[x] < f->a[x-1]) {
            temp = f->a[x];
            f->a[x] = f->a[x-1];
            f->a[x-1] = temp;
            x--;
        }
        /*
        if (toMove == f->len/2) {
            flex_print(f);
        }
        */
    }
} 
void flex_free(flexarray f) {
    free(f->a);
}
