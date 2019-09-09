#include <stdlib.h>
#include <stdio.h>
#include "flexarray.h"

int main() {
    flexarray flex = flexarray_new();
    int scanned;
    while (1 == scanf("%d", &scanned)) {
        flexarray_append(flex, scanned);
    }
    flexarray_sort(flex);
    flexarray_print(flex);
    flexarray_free(flex);
    return EXIT_SUCCESS;
}
