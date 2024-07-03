#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"
#include <string>

using namespace std;

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
	int checkLength(string str1, string str2)
	{
		return checker.checkLength(str1, str2);
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