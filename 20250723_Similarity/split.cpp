#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Similarity {
public:
	double getLenSimilarity(const string& str1, const string& str2) {
		int max = std::max(str1.length(), str2.length());
		int min = std::min(str1.length(), str2.length());

		lenAssertion(min);

		return getPatialLenSimilarity(max, min);
	}
	double getAlphaSimilarity(const string& str1, const string& str2) {
		double totalCnt = getTotalCnt(str1, str2);
		double sameCnt = getSameCnt(str1, str2);

		double score = sameCnt / totalCnt * POINT_OF_ALPHA_SIMILARITY;

		return score;
	}

private:
	const int POINT_OF_LEN_SIMILARITY = 60;
	const int POINT_OF_ALPHA_SIMILARITY = 40;

	void lenAssertion(int min) {
		if (min < 1) { throw std::length_error("String length must be larger than 0"); }
	}

	double getPatialLenSimilarity(double max, double min) {
		double gap = max - min;
		double score = (1 - gap / min) * POINT_OF_LEN_SIMILARITY;
		if (score <= 0) score = 0;
		return score;
	}

	double getTotalCnt(const string& str1, const string& str2) {
		int usedChar1[26];
		int usedChar2[26];

		checkUsedAlpha(str1, usedChar1);
		checkUsedAlpha(str2, usedChar2);

		double totalCnt = 0;
		for (int i = 0; i < 26; i++) {
			if (usedChar1[i] > 0 || usedChar2[i] > 0) {
				totalCnt++;
			}		
		}
		return totalCnt;
	}

	double getSameCnt(const string& str1, const string& str2) {
		int usedChar1[26];
		int usedChar2[26];

		checkUsedAlpha(str1, usedChar1);
		checkUsedAlpha(str2, usedChar2);

		double sameCnt = 0;
		for (int i = 0; i < 26; i++) {
			if (usedChar1[i] > 0 && usedChar2[i] > 0) {
				sameCnt++;
			}
		}
		return sameCnt;
	}

	void checkUsedAlpha(const string& str, int used[26]) {
		std::fill_n(used, 26, 0);

		for (auto ch : str) {
			used[ch - 'A'] += 1;
		}
	}
};