#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rbt.h"


void print_key(char* s) {
    printf("%s\n", s);
}

int main() {
    rbt b = rbt_insert(NULL, "test5");
    b = rbt_insert(b, "h");
    b = rbt_insert(b, "l");
    b = rbt_insert(b, "i");
    b = rbt_insert(b, "f");
    b = rbt_insert(b, "j");
    b = rbt_insert(b, "g");
    b = rbt_insert(b, "k");
    b = rbt_insert(b, "d");
    b = rbt_insert(b, "a");
    b = rbt_insert(b, "e");
    b = rbt_insert(b, "b");
    b = rbt_insert(b, "c");
    rbt_preorder(b, print_key);
    return EXIT_SUCCESS;
}
