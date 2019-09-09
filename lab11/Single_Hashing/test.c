#include <stdio.h>
#include <stdlib.h>
#include "htable.h"
#include "getword.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        htable h = htable_new(atoi(argv[1]));
        char word[256];
        while (getword(word, sizeof word, stdin) != EOF) {
            htable_insert(h, word);
        }
        
        htable_print(h, stdout);
        printf("5 occured %d times\n", htable_search(h, "5"));
        htable_free(h);
        free(h);
    } else {
        fprintf(stderr, "Error: Must inclde arg <table length>\n");
    }
    return EXIT_SUCCESS;
}
