#include <cstring>
#include "gtest/gtest.h"
#include "maze.h"

Maze *maze;
int w=15, h=15;
int t_maze[][15] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

GTEST_TEST (maze, test001) {
    EXPECT_EQ (0, maze->set_maze(0, 101, 200));
    EXPECT_EQ (0, maze->set_maze(0, -1, -200));
}

GTEST_TEST (maze, test002) {
    EXPECT_EQ (0, maze->get_maze (4, 11));
    EXPECT_EQ (1, maze->get_maze (13, 10));
    EXPECT_EQ (2, maze->get_maze (1, 1));
    EXPECT_EQ (3, maze->get_maze (13, 13));
}

GTEST_TEST (maze, test003) {
    EXPECT_EQ (1, maze->find_way ());
}

int main (int argc, char *argv[]) {
    maze = new Maze ();
    for (int i = 0; h > i; ++i) {
        for (int j = 0; w > j; ++j) {
            maze->set_maze (t_maze[i][j], i, j);
        }
    }

    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}
