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