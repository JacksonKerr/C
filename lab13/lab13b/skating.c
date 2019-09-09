#include <stdio.h>
#include <stdlib.h>

int main() {
    int id;
    double s1;
    double s2;
    double s3;
    double smolScore;
    int winId = 0;
    double winScore = 0;
    
    while (4 == scanf("%d%lf%lf%lf", &id, &s1, &s2, &s3)) {
        if (s1 < s2 && s1 < s3) {
            smolScore = s1;
        } else if (s2 < s1 && s2 < s3) {
            smolScore = s2;
        } else {
            smolScore = s3;
        }
        if (winScore < (s1+s2+s3-smolScore)/2) {
            winScore = (s1+s2+s3-smolScore)/2;
            winId = id;
        }
    }
    printf("%d\n", winId);
    return EXIT_SUCCESS;
}
