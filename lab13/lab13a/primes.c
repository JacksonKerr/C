#include <stdio.h>
#include <stdlib.h>

int is_prime(int toTest) {
    int i = 0;
    for (i = 2; i <= toTest/2; i++) {
        if (toTest%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int colNum = 0;
    int toCheck = 2;
    int numPrinted = 0;
    while (numPrinted < 200) {
        if (is_prime(toCheck)) {
            colNum++;
            printf("%5d", toCheck);
            if (colNum > 9) {
                printf("\n");
                colNum = 0;
            }
            numPrinted++;
        }
        toCheck++;
    }
    return EXIT_SUCCESS;
}
