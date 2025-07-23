#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

class SimilarityFixture : public Test {
public:
	Similarity similarity;
	float ret;
};

TEST_F(SimilarityFixture, CheckTextLength) {
	ret = similarity.checkLenSimilarity("ASD", "DSA");
	EXPECT_EQ(60, ret);
}

TEST_F(SimilarityFixture, CheckTextLength2) {
	ret = similarity.checkLenSimilarity("A", "BB");
	EXPECT_EQ(0, ret);
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}