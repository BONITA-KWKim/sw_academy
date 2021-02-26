#include <cstring>
#include "gtest/gtest.h"
#include "stack.h"

GTEST_TEST (calculator, test001) {
	std::string in = "(3+5)*(4+2)";
	char out[11];

	CALC_STACK::postfix (out, in.c_str());

	std::string answer = "35+42+*";
	EXPECT_STREQ(answer.c_str(), out);
}

int main (int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
