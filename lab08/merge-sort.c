#include <stdlib.h>
#include <stdio.h>

#define MAX_DIGITS 100000

void merge(int *a, int *w, int n) {
    int *left  =  a;
    int lIndex = 0;
    int *right = a+(n/2);
    int rIndex = 0;
    int wIndex = 0;
    while (lIndex < n/2 && rIndex < n-(n/2)) {
        if (left[lIndex] < right[rIndex]) {
            w[wIndex] =  left[lIndex];
            lIndex++;
        } else {
            w[wIndex] = right[rIndex];
            rIndex++;
        }
        wIndex++;
    }
    while (lIndex < n/2) {
        w[wIndex] = left[lIndex];
        lIndex++;
        wIndex++;
    }
    while (rIndex < n-(n/2)) {
        w[wIndex] = right[rIndex];
        rIndex++;
        wIndex++;
    }        
}
void mergeSort(int *a, int *w, int n) {
    int i;
    if (n < 2) {
        return;
    }
    mergeSort(a, w, n/2);
    mergeSort(a+(n/2), w+(n/2), n-(n/2));

    merge(a, w, n);
    for (i = 0; i < n; i++) {
        a[i] = w[i];
    }
}



int main() {
    int i;
    int w[10];
    int a[10] = {9,822,7,6,555,4,3,2,1,0};
    mergeSort(a, w, 10);
    for (i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return EXIT_FAILURE;
}
