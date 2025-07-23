#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

TEST(TS, TC1) {
	EXPECT_EQ(1, 1);
}

int main() {
	InitGoogleMock();
	return RUN_ALL_TESTS();
}