#include <iostream>

using namespace std;

class Similarity {
public:
	float checkLenSimilarity(const string& str1, const string& str2) {
		int len1 = str1.length();
		int len2 = str2.length();
		
		int gap = abs(len1 - len2);
		float score = (1 - gap / min(len1, len2)) * 60;

		if (max(len1, len2) >= 2 * min(len1, len2)) score = 0;

		return score;
	}
};