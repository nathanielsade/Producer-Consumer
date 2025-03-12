
#ifndef EX3_PRODUCER_H
#define EX3_PRODUCER_H
#include "stdio.h"
#include "boundedQueue.h"
#include "article.h"
#include <stdlib.h>
#include "article.h"
#define CATEGORIES_NUM 3

typedef struct{
    int producerNum;
    int productsNum;
    int queueSize;
    boundedQueue* producerQueue;
} producer;

void* producerThread(void* args);

#endif //EX3_PRODUCER_H
