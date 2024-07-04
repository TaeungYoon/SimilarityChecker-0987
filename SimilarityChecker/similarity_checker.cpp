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

		return getPartialScoreForLenCheck(len1, len2);
	}

	int checkAlpha(string str1, string str2) {
		countAlphabet(str1, str2);
		
		int TotalCnt = getTotalCnt();
		int SameCnt = getSameCnt();

		if (isAllAlphaSame(TotalCnt, SameCnt))
			return CHECK_ALPHA_SCORE_MAX;

		if (isAllAlphaDifferent(SameCnt))
			return CHECK_ALPHA_SCORE_MIN;
		
		return getPartialScoreForAlphaCheck(TotalCnt, SameCnt);;
	}

private:
	int getPartialScoreForLenCheck(const int len1, const int len2)
	{
		int A = getLongStrLen(len1, len2);
		int B = getShortStrLen(len1, len2);
		int Gap = A - B;

		return 60 - (60 * (Gap) / B);
	}

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

	int getPartialScoreForAlphaCheck(int totalCnt, int sameCnt)
	{
		return (40 * sameCnt) / totalCnt;
	}

	bool isAllAlphaDifferent(int SameCnt)
	{
		return SameCnt == 0;
	}

	bool isAllAlphaSame(int TotalCnt, int SameCnt)
	{
		return TotalCnt == SameCnt;
	}

	int getSameCnt(void)
	{
		int SameCnt = 0;
		for (int i = 0; i < ALPHA_LETTER_MAX; i++) {

			if (str1Alpha[i] == 1 && str2Alpha[i] == 1)
				SameCnt++;
		}
		return SameCnt;
	}

	int getTotalCnt(void)
	{
		int TotalCnt = 0;
		for (int i = 0; i < ALPHA_LETTER_MAX; i++) {
			if (str1Alpha[i] == 1 || str2Alpha[i] == 1)
				TotalCnt++;
		}
		return TotalCnt;
	}

	void countAlphabet(std::string& str1, std::string& str2)
	{
		for (auto& c : str1) {
			int index = c - 'A';
			str1Alpha[index] = 1;
		}

		for (auto& c : str2) {
			int index = c - 'A';
			str2Alpha[index] = 1;
		}
	}

	const int CHECK_LENGTH_SCORE_MAX = 60;
	const int CHECK_LENGTH_SCORE_MIN = 0;
	const int ALPHA_LETTER_MAX = 26;
	const int CHECK_ALPHA_SCORE_MAX = 40;
	const int CHECK_ALPHA_SCORE_MIN = 0;

	int str1Alpha[26] = { 0, };
	int str2Alpha[26] = { 0, };
};