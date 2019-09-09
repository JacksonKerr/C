#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

int main() {
    flexarray f = flex_new();
    int num;
    while (1 == scanf("%d", &num)) {
        flex_add(f, num);
    }
    flex_sort(f);
    flex_print(f);
    return EXIT_SUCCESS;
}
