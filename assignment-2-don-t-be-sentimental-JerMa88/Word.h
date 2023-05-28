//
// Created by Yirmiyahu on 3/1/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_WORD_H
#define ASSIGNMENT2_SENTIMENT_WORD_H

#include "DSString.h"

class Word {
private:
    DSString aWord;
    int rating;
public:
    Word();                            // default constructor
    Word(const char *input);     // constructor that converts a cstring
    Word(DSString aWord, int rating);  // constructor that takes a DSString
    // you can also provide  DSString(const string &); for std::string

    //getter and setter
    const DSString &getAWord() const;
    void setAWord(const DSString aWord);
    int getRating() const;
    void setRating(const int rating);

    // comparison operator
    bool operator==(const Word &other) const;
};


#endif //ASSIGNMENT2_SENTIMENT_WORD_H
