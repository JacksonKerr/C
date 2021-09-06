#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"
int main(void) {
    int item;
    flexarray my_flexarray = flexarray_new();
    while (1 == scanf("%d", &item)) {
        flexarray_append(my_flexarray, item);
    }
    printf("Starting Sort\n");
    flexarray_sort(my_flexarray);
    printf("Sort Complete\n");
    printf("Starting Print\n");
    flexarray_print(my_flexarray);
    printf("Print Complete\n");
    flexarray_free(my_flexarray);
    printf("Freed Memory\n");
    return EXIT_SUCCESS;
}
