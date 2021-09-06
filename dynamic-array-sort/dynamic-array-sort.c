#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
int main(void) {
    int item;
    flexarray my_flexarray = flexarray_new();
    while (1 == scanf("%d", &item)) {
        flexarray_append(my_flexarray, item);
    }
    flexarray_sort(my_flexarray);
    flexarray_print(my_flexarray);
    flexarray_free(my_flexarray);
    return EXIT_SUCCESS;
}
