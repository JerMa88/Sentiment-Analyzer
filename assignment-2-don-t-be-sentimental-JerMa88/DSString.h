/*
 * This file should help you to create a minimal interface for your string class based on
 * a dynamically allocated char array. Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-sting.
 */

#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>

class DSString
{

private:
    int len;                                    // the length of the string
    char *data;                                 // a pointer to a character array containing the string with a `\0` terminator
                                                // Note: we keep the terminator only so we can return a c-string version in function c_str().
public:
    DSString();                                 // default constructor               
    DSString(const char *);                     // constructor that converts a cstring

    // rule-of-three
    DSString(const DSString &);                 // copy constructor
    ~DSString();                                // destructor
    DSString &operator=(const DSString &);      // assignment operator

    int length() const;                         // returns the length of the string

    char &operator[](int);                      // returns a reference to the character at the given index

    DSString operator+(const DSString &) const; //overload + operator
    bool operator==(const DSString &) const;    //overload == operator
    bool operator<(const DSString &) const;     //overload < operator
    bool operator>(const DSString &) const;     //overload > operator

    DSString substring(int start, int numChars) const;

    DSString toLower() const;                   // look at the ASCII table for this!

    char *c_str() const;

    std::string toString() const;               // conversion to std::string

    friend std::ostream &operator<<(std::ostream &, const DSString &);
    friend std::istream &operator>>(std::istream &in, DSString &c);

                                                // You are free to add more functionality to the class.  For example,
                                                // you may want to add a find(...) function that will search for a
                                                // substring within a string or a function that breaks a string into words.
};

#endif
