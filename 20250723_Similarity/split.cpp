#include <iostream>

using std::string;

class Similarity {
public:
	double getLenSimilarity(const string& str1, const string& str2) {
		int max = std::max(str1.length(), str2.length());
		int min = std::min(str1.length(), str2.length());

		lenAssertion(min);

		return getPatialLenSimilarity(max, min);
	}
private:
	const int POINT_OF_LEN_SIMILARITY = 60;

	void lenAssertion(int min) {
		if (min < 1) { throw std::length_error("String length must be larger than 0"); }
	}

	double getPatialLenSimilarity(double max, double min) {
		double gap = max - min;
		double score = (1 - gap / min) * POINT_OF_LEN_SIMILARITY;
		if (score <= 0) score = 0;
		return score;
	}
};