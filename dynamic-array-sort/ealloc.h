#ifndef EALLOC_H_
#define EALLOC_H_

#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);

#endif
