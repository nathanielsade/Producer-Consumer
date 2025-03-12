#ifndef EX3_DISPATCHER_H
#define EX3_DISPATCHER_H
#include "boundedQueue.h"
#include "unboundedQueue.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"

typedef struct dispatcher{
    int producerNum;
    boundedQueue** pBoundedQueue;
    UnboundedQueue** pUnboundedQueue;
}dispatcher;

void dispatcherInit(dispatcher* dp, UnboundedQueue** uq, boundedQueue** bq, int prodNum);
void* dispatcherThread(void* args);

#endif //EX3_DISPATCHER_H
