#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"
#include <string>

using namespace std;

TEST(SimilarityChecker, checkLength_SameLength) {
	string str1 = "ABCDE";
	string str2 = "ABCDE";
	SimilarityChecker checker;
	int ret = checker.checkLength(str1, str2);
	
	EXPECT_EQ(60, ret);
}

TEST(SimilarityChecker, checkLength_LongerThanOrEqaulTo2Times) {
	string str1 = "A";
	string str2 = "BB";
	SimilarityChecker checker;
	int ret = checker.checkLength(str1, str2);

	EXPECT_EQ(0, ret);
}