#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "getword.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        htable h = htable_new(atoi(argv[1]));
        char word[256];
        while (getword(word, sizeof word, stdin) != EOF) {
            htable_insert(h, word);
        }
        /*18143 = length for test*/
        htable_print(h, stdout);
        if (argc > 2) {
            printf("%s occured %d times\n", argv[2], htable_search(h, argv[2]));
        }
        htable_free(h);
        free(h);
    } else {
        fprintf(stderr, "Error: Usage <table length> [Search word]\n");
    }
    return EXIT_SUCCESS;
}

