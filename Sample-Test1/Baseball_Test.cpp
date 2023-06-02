#include "pch.h"
#include "../TDD_Baseball/Baseball.cpp"

using namespace std;

TEST(TestCaseName, Exception_InvalidArgument) {
    Baseball cBaseball;
    
    EXPECT_THROW(cBaseball.Guess("") , invalid_argument);
    EXPECT_THROW(cBaseball.Guess("1234"), invalid_argument);
    EXPECT_THROW(cBaseball.Guess("12V"), invalid_argument);
    EXPECT_THROW(cBaseball.Guess("121"), invalid_argument);
}