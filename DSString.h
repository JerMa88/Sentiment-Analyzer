/*
 * This file should help you to create a minimal interface for your string class based on
 * a dynamically allocated char array. Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-sting.
 */

#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <string.h>
#include <vector>

class DSString
{

private:
    size_t len;    // the length of the string
    char *data; // a pointer to a character array containing the string with a `\0` terminator
    int sentiment;
    // Note: we keep the terminator only so we can return a c-string version in function c_str().
public:
    DSString();                  // default constructor
    DSString(const char *input); // constructor that converts a cstring

    // rule-of-three
    DSString(const DSString &rhs);         // copy constructor
    ~DSString();                           // destructor
    DSString &operator=(const DSString &); // assignment operator

    size_t length() const; // returns the length of the string
    size_t size() const;

    char &operator[](size_t index); // returns a reference to the character at the given index
    const char& operator[](size_t index) const;
    DSString operator+(const DSString &rhs) const; // overload + operator
    DSString operator+(char rhs) const;            // Concatenation operator with char
    bool operator==(const DSString &rhs) const;    // overload == operator
    bool operator<(const DSString &rhs) const;     // overload < operator
    bool operator>(const DSString &rhs) const;     // overload > operator

    DSString substring(size_t start, size_t numChars) const;

    DSString toLower() const; // look at the ASCII table for this!

    char *c_str() const;

    std::string toString() const; // conversion to std::string

    int getSentiment();

    void positive();

    void negative();

    std::vector<DSString> split(char dlm = ' ') const;


    std::vector<DSString> split(char dlm, size_t limit) const;


    DSString& remove_punctuation() ;


    DSString remove_word_after_char(char indicator = '@');


    DSString remove_repeat_chars();

    // Remove element at index
    void remove(size_t index);

    // Resize the string to a new size
    void resize(size_t newSize);

    // Remove the last element
    void pop_back();

    friend std::ostream &operator<<(std::ostream &output, const DSString &x) {
        for (size_t i = 0; i < x.len; ++i) {
            output << x.data[i];
        }
        return output;
    }
    friend std::istream &operator>>(std::istream &input, DSString &add) {
        char *buffer;
        buffer = new char[16000];
        input.getline(buffer, 16000);
        add = DSString(buffer);
        delete [] buffer;
        return input;
    }
    friend std::istream &getline(std::istream &input, DSString &add)
    {
        char buffer[16000];
        input.getline(buffer, 16000);
        add = DSString(buffer);
        return input;
    }

};

#endif
