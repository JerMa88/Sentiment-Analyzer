#include "DSString.h"
#include <string>

DSString::DSString()
{
    len = 0;
    data = nullptr;
    sentiment = 0;
}

DSString::DSString(const char *input)
{
    int length = 0;
    for (int i = 0; input[i] != '\0'; ++i)
    {
        ++length;
    } // find length of input

    len = length;             // update len
    data = new char[len + 1]; // initialize array on heap same length as input
    data[len] = '\0';         // set last element to null terminator

    for (size_t i = 0; i < len; ++i)
    {
        data[i] = input[i];
    } // copy data as same as input
    sentiment = 0;
    data[len] = '\0';
}

DSString::DSString(const DSString &rhs)
{
    len = rhs.len; // set len to length of rhs

    data = new char[len + 1]; // initialize array on heap same length as other

    for (size_t i = 0; i < len; ++i)
        data[i] = rhs.data[i]; // copy data as same as other

    sentiment = rhs.sentiment;
    data[len] = '\0';
}

DSString::~DSString()
{
    delete[] data;
}

DSString &DSString::operator=(const DSString &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] data; // deallocate existing data

    len = rhs.len; // set len to length of other

    data = new char[len + 1]; // initialize array on heap same length as other

    for (size_t i = 0; i < len; ++i)
    {
        data[i] = rhs.c_str()[i];
    } // copy data as same as other

    data[len] = '\0'; // set last element to null terminator
    sentiment = rhs.sentiment;
    return *this;
}

size_t DSString::length() const
{
    return len;
}

size_t DSString::size() const
{
    return len;
}

char &DSString::operator[](size_t index)
{
    if (index >= len)
        throw std::invalid_argument("INVAID INDEX ACCESS");

    else
        return data[index];
}
const char &DSString::operator[](size_t index) const
{
    if (index < len)
    {
        return data[index];
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }
}

DSString DSString::operator+(const DSString &rhs) const
{
    size_t rhsChar = 0;
    DSString newString; // creates new string, update size, assign first string data then add second string ro end
    newString.len = rhs.len + len;
    newString.data = new char[newString.len + 1];

    for (size_t i = 0; i < len; ++i)
    {
        newString.data[i] = data[i];
    }
    for (size_t i = len; i < newString.len; ++i)
    { // can for sure nest a loop
        newString.data[i] = rhs.data[rhsChar];
        ++rhsChar;
    }

    newString.data[newString.len] = '\0';
    newString.sentiment = sentiment;
    return newString;
}

DSString DSString::operator+(char rhs) const
{
    size_t newLen = len + 1;
    char *newData = new char[newLen + 1];

    if (data != nullptr)
    {
        strcpy(newData, data);
    }

    newData[len] = rhs;
    newData[newLen] = '\0';

    DSString result(newData);
    delete[] newData;
    return result;
}

bool DSString::operator==(const DSString &rhs) const
{
    if (len != rhs.len)
        return false;
    for (size_t i = 0; i < len; ++i)
    {
        if (data[i] != rhs.data[i])
            return false;
    }
    return true;
}
bool DSString::operator<(const DSString &other) const
{
    int minLength = (len < other.len) ? len : other.len;
    for (int i = 0; i < minLength; ++i)
    {
        if (data[i] != other.data[i])
        {
            return data[i] < other.data[i]; // Compare characters lexicographically
        }
    }
    return (len < other.len);
}
bool DSString::operator>(const DSString &other) const
{
    return !(*this < other) && !(*this == other);
}

DSString DSString::substring(size_t start, size_t numChars) const
{
    if (start >= len || numChars <= 0)
    {
        return DSString(); // Return an empty string for out-of-bounds conditions
    }

    size_t endIndex = start + numChars;
    if (endIndex > len)
    {
        endIndex = len; // Adjust the end index if it exceeds the length of the string
    }

    int substringLength = endIndex - start;
    char *substringData = new char[substringLength + 1];
    substringData[substringLength] = '\0';

    for (int i = 0; i < substringLength; ++i)
    {
        substringData[i] = data[start + i]; // Copy characters to the substring
    }

    DSString substring(substringData);
    delete[] substringData;

    return substring;
}

DSString DSString::toLower() const
{
    char *lowChar = new char[len + 1];
    lowChar[len] = '\0';

    for (size_t i = 0; i < len; ++i)
    {
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

char *DSString::c_str() const
{
    return data;
}

std::string DSString::toString() const
{
    std::string convert(data);
    return convert;
}

int DSString::getSentiment()
{
    return sentiment;
}
void DSString::positive()
{
    ++sentiment;
}

void DSString::negative()
{
    --sentiment;
}

#include <vector>

std::vector<DSString> DSString::split(char dlm) const
{
    std::vector<DSString> tmpVector;

    // Start off this function by creating vectorIndex variable then
    DSString tmpString = "";
    size_t dlmCount = 0;

    for (size_t i = 0; i < this->size(); ++i)
    {
        if ((*this)[i] != dlm)
        {
            tmpString = tmpString + (*this)[i];
        }
        else
        {
            dlmCount++;                     // Add 1 every time program encounters a dlm so this will be subtracted later
            tmpVector.push_back(tmpString); // Push back std::vector with completed tmpString
            tmpString = DSString("");       // Restart tmpString
        }
    }

    return tmpVector;
}

std::vector<DSString> DSString::split(char dlm, size_t limit) const
{
    std::vector<DSString> tmpVector;

    // Start off this function by creating vectorIndex variable then
    DSString tmpString = "";
    size_t dlmCount = 0;

    size_t colNum = 1;

    for (size_t i = 0; i < this->size(); ++i)
    {
        // If statement used for case where column limit has been reached
        if (colNum >= limit)
        {
            for (i = i; i < this->size(); ++i)
            {
                tmpString = tmpString + (*this)[i];
            }
            tmpVector.push_back(tmpString);
            break;
        }

        // Normal iteration in search of dlm char
        if ((*this)[i] != dlm)
        {
            tmpString = tmpString + (*this)[i];
        }
        else
        {
            dlmCount++;                     // Add 1 every time program encounters a dlm so this will be subtracted later
            tmpVector.push_back(tmpString); // Push back std::vector with completed tmpString
            tmpString = DSString("");       // Restart tmpString
            colNum++;
        }
    }

    return tmpVector;
}

DSString &DSString::remove_punctuation()
{
    size_t i = 0;
    while (i < len)
    {
        char c = data[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        {
            for (size_t j = i; j < len - 1; ++j)
            {
                data[j] = data[j + 1];
            }
            --len;
        }
        else
        {
            ++i;
        }
    }
    data[len] = '\0'; // Null-terminate the string
    return *this;
}

DSString DSString::remove_word_after_char(char indicator)
{
    for (size_t i = 0; i < this->size(); ++i)
        if ((*this)[i] == indicator)
            resize(i);

    return *this;
}

DSString DSString::remove_repeat_chars()
{
    int totalIterations = size() - 1;
    for (int i = 0; i < totalIterations; ++i)
    {
        if ((*this)[i] == (*this)[i + 1])
        {
            this->remove(i);
            i--;
            totalIterations--;
        }
    }

    return *this;
}

// Remove element at index
void DSString::remove(size_t index)
{
    if (index < len)
    {
        memmove(data + index, data + index + 1, len - index);
        len--;
        data[len] = '\0';
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }
}

// Resize the string to a new size
void DSString::resize(size_t newSize)
{
    if (newSize < len)
    {
        len = newSize;
        data[len] = '\0';
    }
}

// Remove the last element
void DSString::pop_back()
{
    if (len > 0)
    {
        len--;
        data[len] = '\0';
    }
}