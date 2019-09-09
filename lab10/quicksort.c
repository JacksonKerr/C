#include <stdio.h>
void quickSort(int *a, int n) {
    int pivot = a[0];
    int lIndex = -1;
    int rIndex = n;
    int temp;
    
    if (n < 2) {
        return;
    }

    for (;;) {
        do {
            lIndex++;
        } while (a[lIndex] < pivot);
        do {
            rIndex--;
        } while (a[rIndex] > pivot);
        if (lIndex < rIndex) {
            temp = a[rIndex];
            a[rIndex] = a[lIndex];
            a[lIndex] = temp;
        } else {
            break;
        }
    }
    quickSort(a, rIndex+1);
    quickSort(&a[rIndex+1], n - rIndex-1);
}
