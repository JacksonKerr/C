#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern flexarray flex_new();
extern void      flex_add(flexarray f, int num);
extern void      flex_print(flexarray f);
extern void      flex_sort(flexarray f);
extern void      flex_free(flexarray f);

#endif
