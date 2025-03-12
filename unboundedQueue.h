
#ifndef EX3_UNBOUNDEDQUEUE_H
#define EX3_UNBOUNDEDQUEUE_H

#include "semaphore.h"
#include "article.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    article* article;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
    sem_t empty;
    sem_t mutex;
} UnboundedQueue;

void destroyBuffer(UnboundedQueue* buffer);
void initBuffer(UnboundedQueue* buffer);
void unboundedEnqueue(UnboundedQueue* buffer, article* newArticle);
article* unboundedDequeue(UnboundedQueue* buffer);
void printUnboundedQueue(UnboundedQueue* uq);

#endif //EX3_UNBOUNDEDQUEUE_H
