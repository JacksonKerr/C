#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_QUEUE_LENGTH 5

void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result != NULL) {
        return result;
    }
    fprintf(stderr, "Memory allocation failed");
    exit(EXIT_FAILURE);
}

struct queue {
    double* items;
    int head;
    int maxlen;
    int currlen;
};

queue queue_new() {
    queue result = malloc(sizeof *result);
    result->maxlen = MAX_QUEUE_LENGTH;
    result->items = emalloc(MAX_QUEUE_LENGTH * sizeof result->items[0]);
    result->currlen = 0;
    result->head = 0;
    return result;
}

void enqueue(queue q, double item) {
    if (q->currlen < q->maxlen) {
        q->items[(q->head + q->currlen) % q->maxlen] = item;
        q->currlen++;
    } else {
        fprintf(stderr, "Cannot insert into full queue\n");
    }
}

double dequeue(queue q) {
    double result = q->items[q->head];
    q->items[q->head] = 0.0;
    if (q->currlen == 0) {
        return 0;
    }
    q->head = (q->head + 1) % q->maxlen;
    q->currlen -= 1;
    return result;
}

void queue_print(queue q) {
    int i;
    for (i = 0; i < q->maxlen; i++) {
        printf("%d  %f\n", i, q->items[i]);
    }
}

int que_size(queue q) {
    return q->currlen;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}
