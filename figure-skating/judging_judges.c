#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(void) {
    double j1[ARRAY_SIZE];
    double j1_mean;
    double j1_sd;
    double j2[ARRAY_SIZE];
    double j2_mean;
    double j2_sd;
    double j3[ARRAY_SIZE];
    double j3_mean;
    double j3_sd;
    int lines_read = 0;
    int ent_num = 0;
    int dummy;
    double dist_sq = 0;
    int i = 0;
    double subtotal = 0;
    while (4 == scanf("%d%lg%lg%lg", &dummy , &j1[ent_num], &j2[ent_num], &j3[ent_num])) {
        lines_read++;
        ent_num++;
    }
    for (i = 0; i < lines_read; i++) {
        subtotal += j1[i];
    }
    j1_mean = subtotal/lines_read;
    
    /* Printing */
    printf("Marks Distance from average Distance  squared\n");
    printf("----- --------------------- -----------------\n");
    for (i = 0; i < lines_read; i++) {
        dist_sq += (j1[i]-j1_mean)*(j1[i]-j1_mean);
        printf("%2.1f   %2.2f - %2.2f = %2.2f    sq(%2.2f) = %2.2f \n", j1[i], j1[i], j1_mean, j1[i]-j1_mean, j1[i]-j1_mean, (j1[i]-j1_mean)*(j1[i]-j1_mean) );
    }
    printf("---------------------------------------------\n");
    printf("%2.1f / %d = %2.2f (mean)        %2.3f / %1.0f = %2.3f\n", subtotal, lines_read, j1_mean, dist_sq, j1_mean, dist_sq / j1_mean);
    return EXIT_SUCCESS;
}
