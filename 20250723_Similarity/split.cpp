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
		double totalCnt = 0;
		double sameCnt = 0;
		int usedChar1[26];
		int usedChar2[26];

		std::fill_n(usedChar1, 26, 0);
		std::fill_n(usedChar2, 26, 0);

		for (auto ch : str1) {
			if (ch >= 'A' && ch <= 'Z') usedChar1[ch - 'A'] += 1;
			if (ch >= 'a' && ch <= 'z') usedChar1[ch - 'a'] += 1;
		}

		for (auto ch : str2) {
			if (ch >= 'A' && ch <= 'Z') usedChar2[ch - 'A'] += 1;
			if (ch >= 'a' && ch <= 'z') usedChar2[ch - 'a'] += 1;
		}

		
		for (int i = 0; i < 26; i++) {
			if (usedChar1[i] == 0 && usedChar2[i] == 0) continue;
			if (usedChar1[i] > 0 && usedChar2[i] > 0) {
				sameCnt++;
			}
			totalCnt++;
		}

		double score = sameCnt / totalCnt * 40;

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
};