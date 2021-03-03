#ifndef __MAZE_H__
#define __MAZE_H__

#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAZE_LENGTH 100

class Maze {
public:
    Maze ();
    ~Maze () {};

    bool set_maze (int v, int h, int w);
    int get_maze (int h, int w);

    void clear_maze (void);

    bool find_way (void);

private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int MAZE[MAZE_LENGTH][MAZE_LENGTH];
    int visited[MAZE_LENGTH][MAZE_LENGTH];

    bool dfs(int h, int w);
    bool is_wall(int h, int w);
    bool is_visited(int h, int w);
};

#endif