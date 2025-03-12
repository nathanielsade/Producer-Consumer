#ifndef EX3_COEDITORS_H
#define EX3_COEDITORS_H
#include "boundedQueue.h"
#include "unboundedQueue.h"
#include "string.h"
#include "unistd.h"

typedef struct coEditor{
    UnboundedQueue* unboundedQueue;
    boundedQueue* mainQueue;
}coEditor;

void* coEditorThread(void* args);
void initCoEditor(coEditor* pCoEditor, boundedQueue* mainQueue, UnboundedQueue* unboundedQueue);

#endif //EX3_COEDITORS_H
