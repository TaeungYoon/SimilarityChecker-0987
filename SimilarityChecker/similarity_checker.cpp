#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLength(string str1, string str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		
		if (len1 == len2)
			return 60;

		int A = getLongStrLen(len1, len2);
		int B = getShortStrLen(len1, len2);
		int gap = A - B;
		double result = static_cast<double>(1 - gap / B) * 60;
		
		return result;
	}

	int getLongStrLen(const int strLen1, const int strLen2) {
		return strLen1 > strLen2 ? strLen1 : strLen2;
	}
	int getShortStrLen(const int strLen1, const int strLen2) {
		return strLen1 < strLen2 ? strLen1 : strLen2;
	}
};