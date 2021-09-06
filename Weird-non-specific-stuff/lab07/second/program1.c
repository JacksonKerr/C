#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 80
#define MAX_WORDS 100

void *emalloc(size_t s) {
    int *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return result;
}
void printArr(char **a, int len, double min) {
    if (len == 0) {
        return;
    }
    if (min < strlen(a[0])) {
        fprintf(stdout, "%s\n", a[0]);
    }
    printArr(&a[1], len-1, min);
}
int main() {
    double average_length = 0;
    
    char word[MAX_LENGTH];
    char *words[MAX_WORDS];
    int len = 0;
    while (len < MAX_WORDS && 1 == scanf("%s", word)) {
        words[len] = emalloc(strlen(word)* sizeof words[0][0]);
        average_length += strlen(word);
        strcpy(words[len], word);
        len++;
    }
    average_length /= len;
    printArr(words, len, average_length);
    fprintf(stderr, "%.2f\n", average_length);
    
    return EXIT_SUCCESS;
}
