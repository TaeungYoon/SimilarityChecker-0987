#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkLength(string str1, string str2) {
		if (str1.size() == str2.size())
			return 60;

		int len1 = str1.size();
		int len2 = str2.size();
		int A = len1 > len2 ? len1: len2;
		int B = len1 < len2 ? len1 : len2;
		int gap = A - B;
		double result = (1 - gap / B) * 60;
		
		return result;
	}
};