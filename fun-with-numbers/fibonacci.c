#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
    /* variable declarations */
    int last = 0;
    int prev = 1;
    int temp = 0;
    int g = 0;
    /* a familiar "for loop" */
    for (g = 0; g < 40; g++) {
        printf("%d\n", last+prev);
        temp = last+prev;
        prev = last;
        last = temp;
    }
    return EXIT_SUCCESS;
    /* defined in stdlib.h */
}
