CLFAGS=--std=c++11
GTEST_INC=../gtest_inc
GTEST_LIB=../gtest_lib


all: calculator_all maze_all

#####
calculator_all: calculator test_calc

stack: stack.cc
	g++ ${CLFAGS} -c -o obj/stack.o $^

calculator: calculator.cc
	g++ ${CLFAGS} -c -o obj/calculator.o $^

test_calc: test_calc.cc obj/calculator.o
	g++ ${CLFAGS} -I${GTEST_INC} -L${GTEST_LIB} -o test/test_calc $^ -lgtest -lpthread

#####
maze_all: maze test_maze

maze: maze.cc
	g++ ${CLFAGS} -c -o obj/maze.o $^

test_maze: test_maze.cc obj/maze.o
	g++ ${CLFAGS} -I${GTEST_INC} -L${GTEST_LIB} -o test/test_maze $^ -lgtest -lpthread

#####
test: test/test_calc test/test_maze
	# ./test/test_calc
	./test/test_maze

#####
clean:
	--rm -f obj/*.o
	--rm -f test/*