#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_SIZE 25

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
void printArr(char **a, int n) {
    if (n > 0) {
        printf("%s\n", a[0]);
        printArr(a + 1, n - 1);
    }
}
int main(void) {
    /*For sorting*/
    int p;
    char key[MAX_WORD_SIZE];
    char word[MAX_WORD_SIZE];
    char *wordList[MAX_WORDS];
    int num_words = 0;
    while (num_words < MAX_WORDS && 1 == scanf("%24s", word)) {
        wordList[num_words] = emalloc(strlen(word)+1 * sizeof wordList[0][0]);
        strcpy(wordList[num_words], word);
        num_words++;
    };
    for (p = 1; p < num_words; p++) {
        strcpy(key, wordList[p]);
        while (p > 0 && 0 > strcmp(key, wordList[p-1])) {
            strcpy(wordList[p], wordList[p-1]);
            p--;
        }
        strcpy(wordList[p], key);
    }
    /* TESTING */
    printf("Sorted:\n");
    printArr(wordList, num_words);
    printf("\nExit_Success\n");
    return EXIT_SUCCESS;
}
