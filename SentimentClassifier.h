//
// Created by Yirmiyahu on 3/2/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H
#define ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "DSString.h"
#include "tweet.h"
#include "Stemmer.h"

using namespace std;

class SentimentClassifier
{
private:
public:
    bool isStopWord(const DSString& word);
    DSString stemWord(const DSString& word);
    int train(DSString file);
    void printAllWords();
    int test(DSString test_file, DSString result_file);
    double accuracy(DSString answer_file, DSString key_file);

};
#endif // ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H
