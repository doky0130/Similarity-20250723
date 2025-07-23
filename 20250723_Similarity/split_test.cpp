#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

TEST(TS, CheckTextLength) {
	Similarity similarity;
	float ret = similarity.checkLenSimilarity("ASD", "DSA");
	EXPECT_EQ(60, ret);
}

TEST(TS, CheckTextLength2) {
	Similarity similarity;
	float ret = similarity.checkLenSimilarity("A", "BB");
	EXPECT_EQ(0, ret);
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}