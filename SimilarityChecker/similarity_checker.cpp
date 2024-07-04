#include <string>
using namespace std;

class SimilarityChecker
{
public:
	const int MAX_SCORE = 60;
	const int MIN_SCORE = 0;

	int checkLength(const int len1, const int len2) {
		if (isLengthSame(len1, len2))
			return MAX_SCORE;

		if (isLengthDouble(len1, len2))
			return MIN_SCORE;

		return getPartialScore(len1, len2);
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
};