#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"
#include <string>

using namespace std;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
	int checkLength(string str1, string str2)
	{
		return checker.checkLength(str1.size(), str2.size());
	}
	int checkAlpha(string str1, string str2)
	{
		return checker.checkAlpha(str1, str2);
	}
};

TEST_F(SimilarityCheckerFixture, checkLength_SameLength) {
	int expected_score = 60;
	int actual_score = checkLength("ABCDE", "ABCDE");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkLength_LongerThanOrEqaulTo2Times) {
	int expected_score = 0;
	int actual_score = checkLength("A", "BB");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkLength_PartialScoreStr1Longer) {
	int expected_score = 20;
	int actual_score = checkLength("AAABB", "BAA");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkLength_PartialScoreStr2Longer) {
	int expected_score = 30;
	int actual_score = checkLength("AA", "AAE");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkAlpha_AllSameAlphaBet) {
	int expected_score = 40;
	int actual_score = checkAlpha("ASD", "DSA");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkAlpha_AllSameAlphaBetWithDiffLen) {
	int expected_score = 40;
	int actual_score = checkAlpha("AAABB", "BA");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkAlpha_AllDifferentAlphaBet) {
	int expected_score = 0;
	int actual_score = checkAlpha("A", "BB");
	EXPECT_EQ(expected_score, actual_score);
}

TEST_F(SimilarityCheckerFixture, checkAlpha_PartialSameAlphaBet) {
	int expected_score = 20;
	int actual_score = checkAlpha("AA", "AAE");
	EXPECT_EQ(expected_score, actual_score);
}
