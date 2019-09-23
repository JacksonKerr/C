#include <stdio.h>
#include <stdlib.h>
#include "lqueue.h"

void* emalloc(size_t s) {
    void* result = malloc(s);
    if (result != NULL) {
        return result;
    }
    fprintf(stderr, "Memory Allocation Failed");
    exit(EXIT_FAILURE);
}

struct q_item {
    double item;
    q_item nextItem;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue result = emalloc(sizeof *result);
    result->first = NULL;
    result->last = NULL;
    result->length = 0;
    return result;
}

void enqueue(queue q, double item) {
    q_item newNode = emalloc(sizeof *newNode);
    newNode->item = item;
    newNode->nextItem = NULL;
    if (q->last != NULL) {
        q->last->nextItem = newNode;
        q->last = q->last->nextItem;
        q->length++;
    } else {
        q->first = newNode;
        q->last = newNode;
        q->length = 1;
    }
}

double dequeue(queue q) {
    double returnValue;
    q_item oldNode;
    if (q->first == NULL) {
        return 0;
    }

    returnValue = q->first->item;
    oldNode = q->first;

    q->first = q->first->nextItem;
    if (q->first == NULL) {
        q->last = NULL;
    }
    free(oldNode);
    return returnValue;
    
}

void queue_print(queue q) {
    q_item i = q->first;
    printf("Queue:\n");
    while (i != NULL) {
        printf("%f\n", i->item);
        i = i->nextItem;
    }
}
