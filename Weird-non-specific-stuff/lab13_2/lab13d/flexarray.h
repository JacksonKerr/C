#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarraydef *flexarray;

extern flexarray flex_new();
extern void flex_add(flexarray f);
extern void flex_free(flexarray f);
extern void flex_sort(flexarray f);
extern void flex_print(flexarray f);

#endif
