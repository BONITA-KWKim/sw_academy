#include <stack>
#include <cstring>
#include <cstdlib>
#include "stack.h"

namespace CALC_STACK {
void test_calc (void) {
	std::cout << "calculator with stack v0.0.1" << std::endl;
}

void postfix (char *out, const char *in) {
	std::stack<char> stack;

	int out_pos = 0;
	int len = strlen(in);
	for (int i = 0; len > i; ++i) {
		// to-do
		if (in[i] == '(' || in[i] == '{' || in[i] == '[') {
			stack.push(in[i]);
			continue;
		} else if (in[i] == ')' || in[i] == '}' || in[i] == ']') {
			while (stack.top() == ')' ||
				stack.top() == '}' ||
				stack.top() == ']') {
				stack.pop();
				out[out_pos++] = stack.top();
				stack.pop();
			}	
		}

		out[out_pos++] = in[i];
	} // for loop
}

}
