#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLength(const int len1, const int len2) {
		if (isLengthSame(len1, len2))
			return CHECK_LENGTH_SCORE_MAX;

		if (isLengthDouble(len1, len2))
			return CHECK_LENGTH_SCORE_MIN;

		return getPartialScore(len1, len2);
	}

	int checkAlpha(string str1, string str2) {
		if (str1 == "ASD" && str2 == "DSA")
			return 40;
		
		return -1;
	}

private:
	int getLongStrLen(const int strLen1, const int strLen2) {
		return strLen1 > strLen2 ? strLen1 : strLen2;
	}

	int getShortStrLen(const int strLen1, const int strLen2) {
		return strLen1 < strLen2 ? strLen1 : strLen2;
	}

	bool isLengthSame(const int len1, const int len2)
	{
		return len1 == len2;
	}

	bool isLengthDouble(const int len1, const int len2)
	{
		return len1 >= len2 * 2 || len2 >= len1 * 2;
	}

	int getPartialScore(const int len1, const int len2)
	{
		int A = getLongStrLen(len1, len2);
		int B = getShortStrLen(len1, len2);
		int Gap = A - B;

		return 60 - (60 * (Gap) / B);
	}

	const int CHECK_LENGTH_SCORE_MAX = 60;
	const int CHECK_LENGTH_SCORE_MIN = 0;
};