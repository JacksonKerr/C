#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
    if (num == 1) {
        return num;
    }
    return num*factorial(num-1);
}

int main() {
    int num;

    while (1 == scanf("%d", &num)) {
        printf("%d\n", factorial(num));
    }
    
    return EXIT_SUCCESS;
}
