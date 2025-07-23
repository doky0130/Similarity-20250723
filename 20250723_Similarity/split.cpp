#include <iostream>

using namespace std;

class Similarity {
public:
	double checkLenSimilarity(const string& str1, const string& str2) {
		int len1 = str1.length();
		int len2 = str2.length();

		lenAssertion(len1, len2);

		double gap = abs(len1 - len2);
		double score = (1 - gap / min(len1, len2)) * POINT_OF_LEN_SIMILARITY;

		if (score <= 0) score = 0;

		return score;
	}
private:
	const int POINT_OF_LEN_SIMILARITY = 60;
	void lenAssertion(int len1, int len2) {
		if (len1 < 1) { throw length_error("String length must be larger than 0"); }
		if (len2 < 1) { throw length_error("String length must be larger than 0"); }
	}
};