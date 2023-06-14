//
// Created by Yirmiyahu on 2/28/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_TWEET_H
#define ASSIGNMENT2_SENTIMENT_TWEET_H

#include <vector>
#include "DSString.h"

class tweet : public DSString 
{
private:
    DSString ID;
    DSString content;
    int score = 0; //negative # means neg tweet, pos # means pos
    bool sentiment;
    std::vector <DSString> tokens;
public:
    
    void setLine(int numChars, int len);

    DSString getContent();

    void setID();

    DSString getID();

    void tokenize();

    void print();

    void setContent(DSString tweet, DSString x);

    DSString getID() const;

    DSString getContent() const;

 };

#endif //ASSIGNMENT2_SENTIMENT_TWEET_H
