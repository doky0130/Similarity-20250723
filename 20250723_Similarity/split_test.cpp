#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

struct TestTarget {
	string str1;
	string str2;
	double score;
};

class SimilarityFixture : public Test {
public:
	Similarity similarity;
	TestTarget target;
	double ret;

	void checkTextLength(TestTarget target) {
		ret = similarity.checkLenSimilarity(target.str1, target.str2);
		EXPECT_EQ(target.score, ret);
	}
};

TEST_F(SimilarityFixture, CheckTextLength) {
	target = { "ASD", "DSA", 60 };
	checkTextLength(target);

	target = { "A", "BB", 0 };
	checkTextLength(target);
	
	target = { "AAABB", "BAA", 20 };
	checkTextLength(target);	
}

TEST_F(SimilarityFixture, CheckTextLengthAssertion) {
	try {
		ret = similarity.checkLenSimilarity("A", "");
		FAIL();
	}
	catch (const exception& e) {

	}
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}