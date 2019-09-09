#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int curr_id;
    double e1;
    double e2;
    double e3;
    double curr_score;
    
    int win_id = 0;
    double  win_score = 0;
    fflush(stdout);
    while (4 == scanf("%d%lg%lg%lg", &curr_id, &e1, &e2, &e3)) {
        curr_score = (e1+e2+e3)/2;
        if (win_score < curr_score) {
            win_score = curr_score;
            win_id = curr_id;
        };
    }
    /* print the winner*/
    printf("%d is the winner with %f points\n", win_id, win_score);

    return EXIT_SUCCESS;
}

