CLFAGS=--std=c++11
GTEST_INC=../gtest_inc
GTEST_LIB=../gtest_lib


all: self2


self2: stack test_stack

stack: stack.cc
	g++ ${CLFAGS} -c -o obj/stack.o $^

test_stack: test_stack.cc obj/stack.o
	g++ ${CLFAGS} -I${GTEST_INC} -L${GTEST_LIB} -o test/test_stack $^ -lgtest -lpthread


test: test/test_stack
	./test/test_stack


clean:
	--rm -f obj/*.o
