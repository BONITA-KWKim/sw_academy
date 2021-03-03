#include "maze.h"

Maze::Maze () {
    this->clear_maze ();
}

bool Maze::set_maze (int v, int h, int w) {
    if (MAZE_LENGTH < h || MAZE_LENGTH < w || 
        0 > h || 0 > w) return false;
    this->MAZE[h][w] = v;
    return true;
}

int Maze::get_maze (int h, int w) {
    if (MAZE_LENGTH < h || MAZE_LENGTH < w || 
        0 > h || 0 > w) return false;
    return this->MAZE[h][w];
}

void Maze::clear_maze (void) {
    int i = 0;
    for (i = 0; MAZE_LENGTH > i; ++i)
        memset(this->MAZE[i], 1, sizeof(int)*MAZE_LENGTH);

    for (i = 0; MAZE_LENGTH > i; ++i)
        memset(this->visited[i], 0, sizeof(int)*MAZE_LENGTH);   
}

bool Maze::find_way (void) {
    bool find_st = false;
    // find start
    int h = 0, w = 0;
    for (h = 0; MAZE_LENGTH > h; ++h) {
        for (w = 0; MAZE_LENGTH > w; ++w) {
            if (2 == this->MAZE[h][w]) {
                find_st = true;
                break;
            }
        }
        if (find_st) break;
    }

    return (find_st ? this->dfs(h, w) : false);
}

bool Maze::dfs (int h, int w) {
    bool res = false;
    this->visited[h][w] = 1;
    // base case
    if (3 == this->MAZE[h][w]) {
        return true;
    }

    // move
    for (int i = 0; 4 > i; ++i) {
        if (!this->is_wall(h+dy[i], w+dx[i]) && 
            !this->is_visited(h+dy[i], w+dx[i])) {
            if (res = dfs(h+dy[i], w+dx[i])) break;
        }
    }
    this->visited[h][w] = 0;

    return res;
}

bool Maze::is_wall (int h, int w) {
    return (this->MAZE[h][w] == 1 || MAZE_LENGTH < h || MAZE_LENGTH < w || 
        0 > h || 0 > w);
}

bool Maze::is_visited (int h, int w) {
    return (this->visited[h][w] == 1);
}