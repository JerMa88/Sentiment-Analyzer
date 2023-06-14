#include <iostream>

#include "DSString.h"
#include "SentimentClassifier.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 6) {
        cout << "REMEMBER to run with command line from terminal\n";
        cout << "run with command line\n../build/sentiment ../data/train_dataset_20k.csv ../data/test_dataset_10k.csv ../data/tested_output.csv ../data/tested_output.csv ../data/test_dataset_sentiment_10k.csv";
        return 1;
    }

    DSString trainFile = argv[1];
    DSString testFile = argv[2];
    DSString resultsFile = argv[3];
    DSString answerFile = argv[4];
    DSString keyFile = argv[5];

    SentimentClassifier sentimentAnalysis;
    sentimentAnalysis.train(trainFile);
    // sentimentAnalysis.printAllWords();
    sentimentAnalysis.test(testFile, resultsFile);
    double accuracy = sentimentAnalysis.accuracy(answerFile, keyFile);
    cout << "Accuracy: " << accuracy << "%\n";

    return 0;
}