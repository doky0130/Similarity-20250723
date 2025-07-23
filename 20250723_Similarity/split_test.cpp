#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

class SimilarityFixture : public Test {
public:
	Similarity similarity;
	double ret;

	void checkTextLength(double score, string str1, string str2) {
		ret = similarity.getLenSimilarity(str1, str2);
		EXPECT_DOUBLE_EQ(score, ret);
	}
};

TEST_F(SimilarityFixture, CheckTextLength) {
	checkTextLength(60, "ASD", "DSA");
	checkTextLength(0, "A", "BB");
	checkTextLength(20, "AAABB", "BAA");
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}