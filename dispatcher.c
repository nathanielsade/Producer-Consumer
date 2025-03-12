
#include "dispatcher.h"

void dispatcherInit(dispatcher* dp, UnboundedQueue** uq, boundedQueue** bq, int prodNum){
    dp->producerNum = prodNum;
    dp->pBoundedQueue = bq;
    dp->pUnboundedQueue = uq;
}

void* dispatcherThread(void* args) {
    dispatcher* dp = (dispatcher*) args;
    int queueDoneCount = 0;

    // Static array of categories (you can modify this array easily)
    const char* categories[] = {"NEWS", "WEATHER", "SPORTS"};
    int categoryCount = 3;  // Hardcoded number of categories

    while(1) {
        // Iterate through each producer's bounded queue
        for (int i = 0; i < dp->producerNum; i++) {
            if (dp->pBoundedQueue[i]->done) {
                continue;
            }

            // Dequeue an article from the current bounded queue
            article* extractedArticle = BoundedDequeue(dp->pBoundedQueue[i]);

            // If the category is "DONE", mark the queue as done
            if (strcmp(extractedArticle->category, "DONE") == 0) {
                free(extractedArticle);
                if (dp->pBoundedQueue[i]->done) {
                    continue;
                } else {
                    dp->pBoundedQueue[i]->done = 1;
                    queueDoneCount++;
                    continue;
                }
            }

            // Dynamically handle categories and enqueue to the correct unbounded queue
            for (int j = 0; j < categoryCount; j++) {
                if (strcmp(extractedArticle->category, categories[j]) == 0) {
                    unboundedEnqueue(dp->pUnboundedQueue[j], extractedArticle);
                    break;
                }
            }
        }

        // If all producer queues are done, enqueue sentinel values to unbounded queues
        if (queueDoneCount == dp->producerNum) {
            for (int i = 0; i < categoryCount; i++) {
                article* sentinal = (article*) malloc(sizeof(article));
                sentinal->category = "DONE";
                sentinal->producerNum = i;
                sentinal->counter = 0;
                unboundedEnqueue(dp->pUnboundedQueue[i], sentinal);
            }
            return NULL;
        }
    }
}