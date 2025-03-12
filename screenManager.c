#include "screenManager.h"

void* screenFunc(void* args){
        boundedQueue* mainQueue = (boundedQueue*) args;
        int counter = 0;
        while(1){
            article* article = BoundedDequeue(mainQueue);
            if(strcmp(article->category, "DONE") == 0){
                free(article);
                counter++;
                if(counter == 3){
                    printf("DONE\n");
                    return NULL;;
                }
                continue;
            }
            printf("Producer %d %s %d\n", article->producerNum, article->category, article->counter);
            free(article);
        }
}