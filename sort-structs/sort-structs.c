#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;       /* grid-reference east-west                             */
    int y;       /* grid-reference north-south                           */
    double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};
void print_ocean_datum(struct ocean_datum *o) {
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}
int read_ocean_datum(struct ocean_datum *o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}
int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;
    double key;
    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }
    /* sort the data here */
    for (i = 1; i < num_items; i++) {
        key = ocean_data[i].conc;
        while (i > 0 && key < ocean_data[i-1].conc) {
            ocean_data[i].conc = ocean_data[i-1].conc;
            i--;
        }
        ocean_data[i].conc = key;
    }
    
    
    
    /* print out the array of structs */
    for (i = 0; i < num_items; i++) {
        print_ocean_datum(&ocean_data[i]);
    }
    return EXIT_SUCCESS;
}
