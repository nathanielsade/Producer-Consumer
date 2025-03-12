#include "coEditors.h"

void initCoEditor(coEditor* pCoEditor, boundedQueue* mainQueue, UnboundedQueue* unboundedQueue){
    pCoEditor->unboundedQueue = unboundedQueue;
    pCoEditor->mainQueue = mainQueue;
}

void* coEditorThread(void* args){
    /*
     * iterate unbounded queue until reaching sentinal value
     * for each element in queue 'edit' it and pass it to main queue.
     */
    coEditor* co_editor = (coEditor*) args;
    while(1){
        article* extractedArticle = unboundedDequeue(co_editor->unboundedQueue);
        if(strcmp(extractedArticle->category, "DONE") == 0){
            boundedEnqueue(co_editor->mainQueue, extractedArticle);
            return NULL;
        } else {
            // edit and insert in main queue
            boundedEnqueue(co_editor->mainQueue, extractedArticle);
        }
        usleep(100000);
    }
}
