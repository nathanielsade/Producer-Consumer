#ifndef EX3_ARTICLE_H
#define EX3_ARTICLE_H
#include "stdlib.h"

typedef struct {
    int producerNum;
    int counter;
    char* category;
} article;

article* generateArticle(int producerNum, int* categoryCounters);

#endif //EX3_ARTICLE_H
