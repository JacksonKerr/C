#include <stdio.h>
#include <stdlib.h>

int isPrime(int i) {
    int x;
    for (x = 2; x <= i/2; x++) {
        if (i % x == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    int i = 2;
    int shown = 0;
    
    while (shown < 200) {
        if (1 == isPrime(i)) {
            printf("%5d", i);
            shown++;
       
            if (shown % 10 == 0) {
                printf("\n");
            }
        }
        i++;
    }
    
    return EXIT_SUCCESS;
}
