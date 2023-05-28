//
// Created by Yirmiyahu on 3/2/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H
#define ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H

#include <iostream>
#include <vector>
#include <fstream> // fileio
#include <filesystem> // fileio
#include <sstream> // Dr. Hahsler approved the use of stringstream library
#include <cmath> // For gradient_descent() linear algebra calculations

#include "DSString.h"
#include "DataFrame.h"
#include "Word.h"

using namespace std;

class SentimentClassifier
{
private:
    vector<Word> dataBase;
    vector<double> parameters;
    vector<DSString> testPredictions;
    vector<DSString> testIDs;
    vector<int> incorrectIndecies;
    double trainingAccuracy;
    double testingAccuracy;

public:
    SentimentClassifier();


    // rule-of-three
    SentimentClassifier(const SentimentClassifier &other) = default;            // copy constructor
    ~SentimentClassifier() = default;                              // destructor
    SentimentClassifier &operator=(const SentimentClassifier &other); // assignment operator

    DataFrame readTweets(DSString filename);
    void removeStopWords(vector<vector<DSString>> &tweets);
    vector<vector<DSString>> tokenizedTweets(DataFrame tweets);
    vector<DSString> sentimentLable(DataFrame tweets);
    //vector<Word> dataBase(vector<vector<DSString>> tweets, vector<DSString> sentiments);

    double training_accuracy(vector<double> parameters,
                             vector<vector<double>> data,
                             vector<DSString> sentiments);

    double testing_accuracy(vector<double> parameters,
                            vector<vector<double>> data,
                            vector<DSString> sentiments,
                            vector<DSString> IDs);

    void train(DSString trainingFile);
    void test(DSString testingFile, DSString resultsFile);
    void check_results(DSString predictionsTitle, DSString resultsTitle);


    // void train(std::string fileName)
    // {
    //     std::ifstream training_file(fileName, std::ios_base::in); // IMPORTANT NOTE: Notice using "../" to prefix the file name. You will need that to access files properly in CLION.
    //     std::cout << "Reading in Files..."
    //               << "\n";
    //     training_file.open("../data/train_dataset_20k.csv"); //(fileName);
    //     if (!training_file.is_open())
    //     {
    //         std::cout << "Could not open training file"
    //                   << "\n";
    //     }
        
    //     DSString ignore;
    //     getline(training_file, ignore); // ignore the first line
    //     while (!training_file.eof())
    //     {
    //         training_file >> sentiments; // get sentiment value
    //         getline(training_file, ignore, ',');
    //         getline(training_file, ignore, ',');
    //         getline(training_file, ignore, ',');
    //         getline(training_file, ignore, ',');
    //         getline(training_file, ignore, ',');
    //         getline(training_file, tweets); // get tweet

    //         transform(tweets.begin(), tweets.end(), tweets.begin(), ::tolower); // convert tweet to lowercase
    //         trainTweets.push_back(tweets);                                      // add tweet to trainTweets vector
    //         trainSentiments.push_back(sentiments);                              // add sentiment to trainSentiments vector
    //         trainSentimentAnalysis.push_back({sentiments, tweets});             // add sentiments and tweets to trainSentimentAnalysis vector

    //         training_file.close();
    //     }

    //     for (int i = 0; i < 220; i++)
    //     {
    //         sentimentOfWords[i] = 0; // initialize sentiment to be 0, if the overall value of sentimentOfWords[i] is negative, then the word is negative, otherwise it is positive
    //         for (size_t j = 0; j < trainTweets.size(); j++)
    //         {                                                             // look at every tweet
    //             size_t found = trainTweets.at(j).find(sentimentWords[i]); // see if a word from the sentimentWords array is found
    //             if (found != string::npos)
    //             {
    //                 if (trainSentiments.at(j) == 0)
    //                 { // if a word from the array is found from a negative tweet subtract 4
    //                     sentimentOfWords[i] -= 4;
    //                 }
    //                 else
    //                 {
    //                     sentimentOfWords[i] += 4; // if a word from the array is found from a positive tweet add 4
    //                 }
    //             }
    //         }
    //     }

    //     void predict(DSString fileName)
    //     {
    //         input.open("./data/test_dataset_10k.csv");
    //         if (input.is_open())
    //         {
    //             getline(input, ignore); // ignore the first line
    //             while (!input.eof())
    //             {
    //                 getline(input, ignore, ',');
    //                 getline(input, ignore, ',');
    //                 getline(input, ignore, ',');
    //                 getline(input, ignore, ',');
    //                 getline(input, tweets); // get tweet

    //                 testTweets.push_back(tweets);                                       // add tweet to testTweets vector
    //                 transform(tweets.begin(), tweets.end(), tweets.begin(), ::tolower); // convert tweet to lowercase
    //                 lowerTestTweets.push_back(tweets);                                  // add lowercase tweets to lowerTestTweets vector
    //             }
    //         }
    //         else if (!input)
    //         {
    //             cout << "File did not open!" << endl;
    //         }

    //         int goodCount[testTweets.size()]; // int array to store count of positive words
    //         int badCount[testTweets.size()];  // int array to store count of negative words

    //         for (int i = 0; i < 220; i++)
    //         { // while i is less than the total number of sentiment words
    //             for (size_t j = 0; j < lowerTestTweets.size(); j++)
    //             {
    //                 size_t found = lowerTestTweets.at(j).find(sentimentWords[i]);
    //                 if (found != string::npos)
    //                 {
    //                     if (sentimentOfWords[i] <= 0)
    //                     { // if you have a negative word
    //                         badCount[j] += 1;
    //                     }
    //                     else
    //                     {
    //                         goodCount[j] += 1;
    //                     }
    //                 }
    //             }
    //         }

    //         for (size_t i = 0; i < testTweets.size(); i++)
    //         {
    //             if (badCount[i] < goodCount[i])
    //             {                                                           // if there are more negative words than positive words
    //                 testSentimentAnalysis.push_back({0, testTweets.at(i)}); // sentiment is 0
    //             }
    //             else
    //             {
    //                 testSentimentAnalysis.push_back({4, testTweets.at(i)}); // otherwise sentiment is 4
    //             }
    //         }

    //         for (size_t i = 0; i < testSentimentAnalysis.size() - 1; i++)
    //         {
    //             cout << testSentimentAnalysis[i].first << " " << testSentimentAnalysis[i].second << endl;
    //         }

    //         return testSentimentAnalysis; // return vector containing test sentiments and tweets

    //         output.open("test.txt");
    //         for (int i = 0; i < testSentimentAnalysis.size(); i++)
    //         {
    //             output << testSentimentAnalysis[i].first << " " << testSentimentAnalysis[i].second << "\n";
    //         }
    //         output.close();
    //     }

    //     int evaluatePredictions()
    //     {
    //         for (int i = 0; i < getSize.AllTweets<Tweet>; ++i)
    //         {
    //             if (getRating.AllTweet.at(i) == getRating.AllEvaluatedTweet.at(i))
    //                 countTweetCorrect++;
    //         }
    //         accuracy = countTweetCorrect / countTweetTotal * 100;
    //         return accuracy;
    //     }
    // };
};
#endif // ASSIGNMENT2_SENTIMENT_SENTIMENTCLASSIFIER_H
