//
// Created by Yirmiyahu on 2/28/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_TWEET_H
#define ASSIGNMENT2_SENTIMENT_TWEET_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream> // fileio
#include <filesystem> // fileio
#include <sstream> // Dr. Hahsler approved the use of stringstream library
#include <cmath> // For gradient_descent() linear algebra calculations

#include "DSString.h"


class Tweet {
private:
    DSString tweet;
    int sentimentValue;
public:
    Tweet(DSString id, int sentiment);
};


#endif //ASSIGNMENT2_SENTIMENT_TWEET_H
