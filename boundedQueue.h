
#ifndef EX3_BOUNDEDQUEUE_H
#define EX3_BOUNDEDQUEUE_H
#include "semaphore.h"
#include "stdio.h"
#include "pthread.h"
#include "article.h"
#include "stdlib.h"

typedef struct {
    int size, done, front, rear;
    sem_t empty, full;
    sem_t mutex;
    article** items;
} boundedQueue;

int initializeQueue(boundedQueue* queue, int size);
void boundedEnqueue(boundedQueue* queue,article* newArticle);
article* BoundedDequeue(boundedQueue* queue);
void destroyQueue(boundedQueue* queue);

#endif //EX3_BOUNDEDQUEUE_H