#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <cstddef>
#include "DSString.h"

DSString str;
const char* input = "Hello";

TEST_CASE("Check that Default Constructor Works", "[DSString]") 
{
    REQUIRE(str.length() == 0);
    REQUIRE(str.c_str()[0] == '\0');
}

TEST_CASE("DSString Constructor with C-string", "[DSString]") {
    DSString str(input);
    REQUIRE(str.length() == 5);
    REQUIRE(std::strcmp(str.c_str(), input) == 0);
}

TEST_CASE("DSString Copy Constructor", "[DSString]") {
    DSString str1("Hello");
    DSString str2(str1);
    REQUIRE(str2.length() == 5);
    REQUIRE(std::strcmp(str2.c_str(), str1.c_str()) == 0);
}

TEST_CASE("DSString Assignment Operator", "[DSString]") {
    DSString str1("Hello");
    DSString str2;
    str2 = str1;
    REQUIRE(str2.length() == 5);
    REQUIRE(std::strcmp(str2.c_str(), str1.c_str()) == 0);
}

TEST_CASE("DSString Concatenation Operator", "[DSString]") {
    DSString str1("Hello");
    DSString str2(" World");
    DSString result = str1 + str2;
    REQUIRE(result.length() == 11);
    REQUIRE(std::strcmp(result.c_str(), "Hello World") == 0);
}

TEST_CASE("DSString Equality Operator", "[DSString]") {
    DSString str1("Hello");
    DSString str2("Hello");
    DSString str3("World");
    REQUIRE(str1 == str2);
    REQUIRE(!(str1 == str3));
}

TEST_CASE("DSString Comparison Operators", "[DSString]") {
    DSString str1("Hello");
    DSString str2("World");
    REQUIRE(str1 < str2);
    REQUIRE(!(str2 < str1));
    REQUIRE(str2 > str1);
    REQUIRE(!(str1 > str2));
}

TEST_CASE("DSString Substring", "[DSString]") {
    DSString str("Hello World");
    DSString substr = str.substring(6, 5);
    REQUIRE(substr.length() == 5);
    REQUIRE(std::strcmp(substr.c_str(), "World") == 0);
}

TEST_CASE("DSString toLower", "[DSString]") {
    DSString str("Hello");
    DSString lower = str.toLower();
    REQUIRE(lower.length() == 5);
    REQUIRE(std::strcmp(lower.c_str(), "hello") == 0);
}
