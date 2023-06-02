#include "pch.h"
#include "../TDD_Baseball/Baseball.cpp"

using namespace std;

TEST(TestCaseName, InvalidArgument) {
    Baseball cBaseball("123");
    
    EXPECT_THROW(cBaseball.Guess("") , invalid_argument);
    EXPECT_THROW(cBaseball.Guess("1234"), invalid_argument);
    EXPECT_THROW(cBaseball.Guess("12V"), invalid_argument);
    EXPECT_THROW(cBaseball.Guess("121"), invalid_argument);
}

TEST(TestCaseName, AllStrikes) {
    Baseball cBaseball("123");

    Result stResult = cBaseball.Guess("123");
 
    EXPECT_EQ(true, stResult.bSolved);
    EXPECT_EQ(3, stResult.nStrikes);
    EXPECT_EQ(0, stResult.nBalls);
}

TEST(TestCaseName, AllMiss) {
    Baseball cBaseball("123");

    Result stResult = cBaseball.Guess("789");

    EXPECT_EQ(false, stResult.bSolved);
    EXPECT_EQ(0, stResult.nStrikes);
    EXPECT_EQ(0, stResult.nBalls);
}

TEST(TestCaseName, AllBall) {
    Baseball cBaseball("123");

    Result stResult = cBaseball.Guess("312");

    EXPECT_EQ(false, stResult.bSolved);
    EXPECT_EQ(0, stResult.nStrikes);
    EXPECT_EQ(3, stResult.nBalls);
}

TEST(TestCaseName, 1Strikes_2Ball) {
    Baseball cBaseball("123");

    Result stResult = cBaseball.Guess("321");

    EXPECT_EQ(false, stResult.bSolved);
    EXPECT_EQ(1, stResult.nStrikes);
    EXPECT_EQ(2, stResult.nBalls);
}