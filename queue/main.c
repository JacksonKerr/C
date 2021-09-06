#include <stdio.h>
#include <stdlib.h>
#include "lqueue.h"

int main() {

    queue q = queue_new();
    enqueue(q, 3.3);
    printf("Queued:    %f\n", 3.3);

    queue_print(q);
    
    enqueue(q, 1.1);
    printf("Queued:    %f\n", 1.1);
    printf("De-queued: %f\n", dequeue(q));
    enqueue(q, 2.2);
    printf("Queued:    %f\n", 2.2);
    
    queue_print(q);
    
    printf("De-queued: %f\n", dequeue(q));
    printf("De-queued: %f\n", dequeue(q));
    printf("\n");

    
    enqueue(q, 1.0);
    printf("Queued:    %f\n", 1.0);
    queue_print(q);
    enqueue(q, 2.0);
    printf("Queued:    %f\n", 2.0);
    enqueue(q, 3.0);
    printf("Queued:    %f\n", 3.0);
    enqueue(q, 4.0);
    printf("Queued:    %f\n", 4.0);
    enqueue(q, 5.0);
    printf("Queued:    %f\n", 5.0);
    
    printf("De-queued: %f\n", dequeue(q));
    
    queue_print(q);

    
    return EXIT_SUCCESS;
}
