#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "htable.h"

struct htablerec {
    char** strings;
    int* occurences;
    unsigned int maxlen;
    unsigned int currlen;
};


void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}

htable htable_new(int len) {
    htable h = emalloc(sizeof *h);
    int i;
    h->strings = emalloc(len*sizeof h->strings[0]);
    h->occurences = emalloc(len*sizeof h->occurences[0]);
    for (i = 0; i < len; i++) {
        h->strings[i] = NULL;
        h->occurences[i] = 0;
    }
    h->maxlen = len;
    h->currlen = 0;
    return h;
}
int htable_insert(htable h, char* str) {
    unsigned int strHash = htable_word_to_int(str)%h->maxlen;
    unsigned int currIndex = strHash;    
    /* Search for next free space */
    while (h->strings[currIndex] != NULL) {
        /* If input = item at currIndex, Add one to occurences, and exit */
        if (0 == strcmp(h->strings[currIndex], str)) {
            h->occurences[currIndex]++;
            return 1;
        }
        currIndex++;
        /* If past end of table, go to start */
        if (currIndex == h->maxlen) {
            currIndex = 0;
        }        
        /* If whole table has been looped, exit*/
        if (currIndex == strHash) {
            break;
        }
    }
    /* Insert string into currIndex location */
    if (h->strings[currIndex] == NULL) {
        h->strings[currIndex] = emalloc((strlen(str)+1)*sizeof str[0]);
        strcpy(h->strings[currIndex], str);
        h->occurences[currIndex] = 1;
        h->currlen++;
        return 1;
    }
    return 0;
}
void htable_print(htable h, FILE* stream) {
    unsigned int i;
    fprintf(stream, "String:             Occurences:\n");
    for (i = 0; i < h->maxlen; i++) {
        /*if (h->occurences[i] != 0) {*/
            fprintf(stream, "%-20s%-20d\n", h->strings[i], h->occurences[i]);
            /*}*/
    }
}
int htable_search(htable h, char* str) {
    unsigned int strHash = htable_word_to_int(str)%h->maxlen;
    unsigned int currIndex = strHash;

    while (h->strings[currIndex] != NULL) {
        if (strcmp(h->strings[currIndex], str) != 0) {
            return h->occurences[currIndex-1];
        }
        currIndex++;
        /* If past end of table, go to start */
        if (currIndex == h->maxlen) {
            currIndex = 0;
        }        
        /* If whole table has been looped, exit*/
        if (currIndex == strHash) {
            break;
        }
    }
    return 0;
}
void htable_free(htable h) {
    unsigned int i;
    for (i = 0; i < h->maxlen; i++) {
        free(h->strings[i]);
    }
    free(h->strings);
    free(h->occurences);
}
