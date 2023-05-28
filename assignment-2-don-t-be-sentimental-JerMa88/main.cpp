#include <iostream>

#include "DSString.h"
#include "SentimentClassifier.h"

using namespace std;

int main(int argc, char** argv) {
    DSString trainingFile = argv[1];
    DSString testingFile = argv[2];
    DSString resultsFile = argv[3];
    DSString predictionsTitle = argv[4];
    DSString resultsTitle = argv[5];

    SentimentClassifier sentimentAnalysis;
    sentimentAnalysis.train(trainingFile);
    sentimentAnalysis.test(testingFile, resultsFile);
    sentimentAnalysis.check_results(predictionsTitle, resultsTitle);


    return 0;
}