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

TEST_F(SimilarityFixture, CheckTextLength3) {
	try {
		ret = similarity.checkLenSimilarity("A", "");
		FAIL();
	}
	catch (const exception& e) {

	}
}
TEST_F(SimilarityFixture, CheckTextLength4) {
	ret = similarity.checkLenSimilarity("AAABB", "BAA");
	EXPECT_EQ(20, ret);
}


int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}