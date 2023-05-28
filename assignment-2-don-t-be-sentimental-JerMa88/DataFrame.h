#ifndef ASSIGNMENT2_SENTIMENT_DATAFRAME_H
#define ASSIGNMENT2_SENTIMENT_DATAFRAME_H

#include <vector>
#include "DSString.h"

class DataFrame : public std::vector<std::vector<DSString>> {
public:
    DataFrame() = default;
    
    DataFrame(const DataFrame &) = default;
    DataFrame(DataFrame &&rhs) = default;
    ~DataFrame() = default;

    DataFrame &operator=(const DataFrame &) = default;
    DataFrame &operator=(DataFrame &&) = default;

};


#endif //ASSIGNMENT2_SENTIMENT_DATAFRAME_H