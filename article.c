#include "article.h"

article* generateArticle(int producerNum, int* categoryCounters){
    char* categories[] = {"NEWS", "WEATHER", "SPORTS"};
    article* newArticle = (article*) malloc(sizeof(article));

    // Set the producer number
    newArticle->producerNum = producerNum;

    // Generate a random category index
    int categoryIndex = rand() % 3;
    newArticle->category = categories[categoryIndex];

    // Increment the counter for the chosen category
    categoryCounters[categoryIndex]++;

    // Set the counter value for the article
    newArticle->counter = categoryCounters[categoryIndex];

    return newArticle;
}
