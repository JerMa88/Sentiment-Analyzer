#include "DSString.h"
#include <string>

DSString::DSString()
{
    len = 0;
    data = new char[len];
}

DSString::DSString(const char *input)
{
    int length = 0;
    for (size_t i = 0; input[i] != '\0'; ++i)
    {
        length = length + 1;
    }                               //find length of input
    
    len = length;                    // update len
    data = new char[length + 1];   //initialize array on heap same length as input
    data[length] = '\0';           //set last element to null terminator

    for (int i = 0; i < length; ++i)
    {
        data[i] = input[i];
    }                               //copy data as same as input
}

DSString::DSString(const DSString &other)
{
    int length = 0;
    for (size_t i = 0; other.c_str()[i] != '\0'; ++i)
    {
        length = length + 1;
    }                               //find length of other

    data = new char[length + 1];    //initialize array on heap same length as other
    data[length] = '\0';           //set last element to null terminator

    for (int i = 0; i < length; i++) 
    {
        data[i] = other.c_str()[i];
    }                               //copy data as same as other

    len = other.len;                  // set len to length of rhs
}

DSString::~DSString()
{
    delete[] data;
} 


DSString &DSString::operator=(const DSString &other) 
{
    if (this != &other)
        delete[] data;                         // deallocate existing data

    len = other.len;                    //set len to length of other

    data = new char[len + 1];               //initialize array on heap same length as other
    data[len] = '\0';                       //set last element to null terminator
    
    for (int i = 0; i < len; ++i)
    {
        data[i] = other.c_str()[i];
    }                                           //copy data as same as other
    
    return *this;
}

int DSString::length() const
{
    return len;
}

char &DSString::operator[](int i)
{
    return data[i];
}

DSString DSString::operator+(const DSString &other) const
{
    char *c;                                          
    int length = len + other.len;                       

    c = new char[length + 1];                           // initialize temporary char array on heap
    c[length] = '\0';                                   // set last element to null terminator

    for (int i = 0; i < len; ++i) 
    {
        c[i] = data[i];
    }                                                   // add contents of data to the temporary char
    for (int i = 0; i < other.len; ++i) 
    {
        c[i + len] = other.c_str()[i];
    }                                                   // add contents of other to the temporary char
    return c;
}

bool DSString::operator==(const DSString & other) const
{
    if(len != other.len)
        return false;
    for (int i = 0; i < len; ++i) 
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}
bool DSString::operator<(const DSString &other) const
{
    int minLength = (len < other.len) ? len : other.len;
    for (int i = 0; i < minLength; ++i) {
        if (data[i] != other.data[i]) {
            return data[i] < other.data[i]; // Compare characters lexicographically
        }
    }
    return (len < other.len);
}
bool DSString::operator>(const DSString &other) const
{
    return !(*this < other) && !(*this == other);
}

DSString DSString::substring(int start, int numChars) const
{
    if (start < 0 || start >= len || numChars <= 0) {
        return DSString(); // Return an empty string for out-of-bounds conditions
    }

    int endIndex = start + numChars;
    if (endIndex > len) {
        endIndex = len;                         // Adjust the end index if it exceeds the length of the string
    }

    int substringLength = endIndex - start;
    char* substringData = new char[substringLength + 1];
    substringData[substringLength] = '\0';

    for (int i = 0; i < substringLength; ++i) {
        substringData[i] = data[start + i];     // Copy characters to the substring
    }

    DSString substring(substringData);
    delete[] substringData;

    return substring;
}

DSString DSString::toLower() const
{
    char *lowChar = new char[len + 1]; 
    lowChar[len] = '\0';

    for (int i = 0; i < len; ++i) {
        char currentChar = data[i];
        if (currentChar >= 'A' && currentChar <= 'Z')
        {
            lowChar[i] = currentChar + 32;
        }
        else
        {
            lowChar[i] = currentChar;
        }
    }

    DSString lowString(lowChar);
    delete[] lowChar;

    return lowString;
}

char *DSString::c_str() const {
    return data;
}

std::ostream &operator<<(std::ostream &out, const DSString &c) {                    
    out << c.c_str();                                   // output contents of x
    return out;
}

std::istream &operator>>(std::istream &in, DSString &s) {
    in >> s.data;
    return in;
}