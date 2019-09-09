#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bst.h"


void print_key(char* s) {
    printf("%s\n", s);
}

int main() {
    bst b = bst_insert(NULL, "test5");
    b = bst_insert(b, "test9");
    b = bst_insert(b, "test2");
    bst_inorder(b, print_key);
    return EXIT_SUCCESS;
}
