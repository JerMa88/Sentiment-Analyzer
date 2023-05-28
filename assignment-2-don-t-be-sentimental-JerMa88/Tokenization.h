//
// Created by Yirmiyahu on 3/2/23.
//

#ifndef ASSIGNMENT2_SENTIMENT_TOKENIZATION_H
#define ASSIGNMENT2_SENTIMENT_TOKENIZATION_H

#include "DSString.h"
#include "Word.h"
#include "Tweet.h"

class Tokenization {
private:

public:
    Tokenization(const Tweet *input); // constructor that converts a cstring
    // you can also provide  DSString(const string &); for std::string
    Tokenization &operator=(Word &&);

    // rule-of-three
    Tokenization(const DSString &other);            // copy constructor
    ~Tokenization();                           // destructor
    Tokenization &operator=(const DSString &other); // assignment operator


    // Function to preprocess a tweet into a vector
    std::vector<std::string> preprocess(const std::string& tweet)
    {
        std::vector<std::string> words;
        std::stringstream ss(tweet);
        std::string word;

        while (ss >> word) {
            // Remove URLs, hashtags, and mentions
            if (word.find("http") == std::string::npos && word.find("#") == std::string::npos && word.find("@") == std::string::npos)
            {
                // Remove punctuation marks
                word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return std::ispunct(c); }), word.end());
                // Convert to lowercase
                std::transform(word.begin(), word.end(), word.begin(), [](char c) { return std::tolower(c); });
                words.push_back(word);
            }
        }

        return words;
    }

    //Lemmatization/stemming — Transforming a word to its root word

};


#endif //ASSIGNMENT2_SENTIMENT_TOKENIZATION_H
