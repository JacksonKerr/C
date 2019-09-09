#include <stdio.h>
#include <stdlib.h>
int is_prime(int num) {
    int i = 1;
    for (i = 2; i < num; i++) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int candidate = 2;
    int num_printed = 0;
    while (num_printed < 100) {
        if (is_prime(candidate)) {
            printf("%d\n", candidate);
            num_printed++;
        }
        candidate++;
    }
    return 0;
}
