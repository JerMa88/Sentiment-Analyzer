//
// Created by Yirmiyahu on 3/1/23.
//

#include "Word.h"

Word::Word() {
    aWord = "";
    rating = 1;
}

Word::Word(const char *input) {
    aWord = x; 
    rating = 1;
}

Word::Word(DSString aWord, int rating) {
    this->aWord = aWord;
    this->rating = rating;
}


const DSString &Word::getAWord() const {
    return aWord;
}

// Getters and Setters

void Word::setAWord(const DSString aWord) {
    Word::aWord = aWord;
}

int Word::getRating() const {
    return rating;
}

void Word::setRating(int rating) {
    Word::rating = rating;
}

bool Word::operator==(const Word &other) const {
    return (this->word == other.word);
}