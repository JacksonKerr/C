#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "htable.h"

/* Returns a pointer to allocated memory of a given size (s) */
void* emalloc(size_t s) {
    void* result = malloc(s);
    /* If allocation fails, prints message to stderr, and exits */
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
/* htablerec struct, typedefed to htable in htable.h */
struct htablerec {
    /* An array containing the strings in the hash table */
    char** strings;
    /* An arrary storing how many times each of the words in strings
       have been added into the hash table */
    int* occurences;
    /* The maximum number of items the hash table can store */
    unsigned int maxlen;
    /* The current ammount of items in the hash table */
    unsigned int currlen;
};
/* Calculate, and return the step size for double hashing*/
static int htable_step(htable h, unsigned int i_key) {
    return 1 + (i_key % (h->maxlen -1));
}
/* Converts a string to an int */
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}
/* Creates a new htable with size len*/
htable htable_new(int len) {
    htable h = emalloc(sizeof *h);
    int i;
    /* Allocate space for arrays; strings, and occurences */
    h->strings = emalloc(len*sizeof h->strings[0]);
    h->occurences = emalloc(len*sizeof h->occurences[0]);
    /* Initialise all values in the arrays */
    for (i = 0; i < len; i++) {
        h->strings[i] = NULL;
        h->occurences[i] = 0;
    }
    /* Initialise other values */
    h->maxlen = len;
    h->currlen = 0;
    return h;
}
/* Inserts a new string (str) into hash table (h) */
int htable_insert(htable h, char* str) {
    unsigned int numCollisions = 0;
    unsigned int step = htable_step(h, htable_word_to_int(str)); 
    unsigned int stepLeft = step;
    unsigned int currIndex = htable_word_to_int(str)%h->maxlen;  
    /* While next hashed location is not free */
    while (h->strings[currIndex] != NULL) {
        numCollisions++;
        /* If input = item at currIndex, Add one to occurences, and exit */
        if (0 == strcmp(h->strings[currIndex], str)) {
            h->occurences[currIndex]++;
            return 1;
        }
        /* Doing step to next slot */
        stepLeft = step;
        while (stepLeft > 0) {
            currIndex++;
            stepLeft--;
            /* If past end of table, go to start */
            if (currIndex == h->maxlen) {
                currIndex = 0;
            }        
            /* If whole table has been looped, exit*/
            if (numCollisions == h->maxlen) {
                break;
            }
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
/* Prints the contents of the hash table (h), to a given stream (stream)*/
void htable_print(htable h, FILE* stream) {
    unsigned int i;
    fprintf(stream, "String:             Occurences:\n");
    for (i = 0; i < h->maxlen; i++) {
        /*if (h->occurences[i] != 0) {*/
        fprintf(stream, "%-20s%-20d\n", h->strings[i], h->occurences[i]);
        /*}*/
    }
}
/* Searches the hash table (h), for a given string (str), returns 1 if found */
int htable_search(htable h, char* str) {
    unsigned int numCollisions = 0;
    unsigned int step = htable_step(h, htable_word_to_int(str)); 
    unsigned int stepLeft = step;
    unsigned int currIndex = htable_word_to_int(str)%h->maxlen;
    while (h->strings[currIndex] != NULL) {
        numCollisions++;
        if (strcmp(h->strings[currIndex], str) == 0) {
            fflush(stderr);
            return h->occurences[currIndex];
        }
        /* Doing step to next slot */
        stepLeft = step;
        while (stepLeft > 0) {
            currIndex++;
            stepLeft--;
            /* If past end of table, go to start */
            if (currIndex == h->maxlen) {
                currIndex = 0;
            }        
            /* If whole table has been looped, exit*/
            if (numCollisions == h->maxlen) {
                break;
            }
        }
    }
    return 0;
}
/* Frees a hash table (h), and all it's data */
void htable_free(htable h) {
    unsigned int i;
    for (i = 0; i < h->maxlen; i++) {
        free(h->strings[i]);
    }
    free(h->strings);
    free(h->occurences);
}
