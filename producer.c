
#include "producer.h"
// NEWS , SPORTS , WEATHER


void* producerThread(void* producer1){
    // args -> {producer number, number of articles, queue size}
    /*
     * 1 initialize queue
     * 2 loop that generates articles
     * 3 push elements to queue
     */
    producer* producerPtr = (producer*) producer1;
    // boundedEnqueue articles
    int categories[CATEGORIES_NUM] = {0};
    for(int i = 0; i < producerPtr->productsNum; i++){
        article* newArticle = generateArticle(producerPtr->producerNum, categories);
        boundedEnqueue(producerPtr->producerQueue, newArticle);
    }
    article* sentinal = (article*) malloc(sizeof(article));
    if(sentinal == NULL){
        printf("failed to allocate sentinal\n");
        free(sentinal);
    } else {
        sentinal->producerNum = producerPtr->producerNum;
        sentinal->category = "DONE";
        sentinal->counter = 0;
        boundedEnqueue(producerPtr->producerQueue, sentinal);
    }
    return NULL;
}
