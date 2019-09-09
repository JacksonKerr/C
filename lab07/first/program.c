#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 80

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }
    return result;
}

void printSmol(char **a, int len, double ave) {
    if (len < 1) {
        return;
    }
    if (strlen(a[0]) > ave) {
        fprintf(stdout, "%s\n", a[0]);
    }
    printSmol(&a[1], len-1, ave);
}

int main() {
    double average_length;
    int i = 0;
    char word[MAX_LENGTH];
    char *words[MAX_WORDS];
    int len = 0;

    /*Loading array of words*/
    while (len < MAX_WORDS && 1 == scanf("%79s\n", word)) {
        words[len] = emalloc(strlen(word)*sizeof words[0][0]);
        average_length += strlen(word);
        strcpy(words[len], word);
        len++;
    }
    average_length /= len;

    printSmol(words, len, average_length);
    
    fprintf(stderr, "%.2f\n", average_length);
    
    for (i = 0; i < len; i++) {
        free(words[i]);
    }
    return EXIT_SUCCESS;
}
