//
// Created by Yirmiyahu on 2/28/23.
//

#include "tweet.h"
#include <algorithm>
#include <iostream>

using namespace std;

void tweet::setID()
{
    ID = this->substring(0, 10);
}

DSString tweet::getID()
{
    return ID;
}

void tweet::setLine(int numChars, int len)
{
    content = this->substring(numChars, len);
}

DSString tweet::getContent()
{
    return content;
}

void tweet::tokenize()
{
    int numChars = 1;
    for (size_t currentIndex = 0; currentIndex < content.length(); ++currentIndex)
    { // cuts off first character
        if (content[currentIndex] == ' ')
        {
            int start = (currentIndex + 1) - numChars;
            DSString token = content.substring(start, numChars);
            numChars = 1;
            // cout << token << endl;
            tokens.push_back(token);
        }
        numChars++;
    }
}

void tweet::print()
{
    for (auto x : tokens)
    {
        cout << x; // PRINTS ELEMTNS AND SENTIMENT
    }
    cout << endl;
}

void tweet::setContent(DSString tweet, DSString x)
{
    content = tweet;
    ID = x;
}

DSString tweet::getID() const
{
    return ID;
}

DSString tweet::getContent() const
{
    return content;
}
