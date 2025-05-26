#ifndef BFS_HPP
#define BFS_HPP

#include "board.hpp"
#include <queue>
#include <set>

using std::queue, std::set;

class BFS {
    private:
        queue<Board> fila;
        set<Board> visitados;
    public:
        BFS();
        ~BFS();
        void bfs(Board estadoInicial, bool showPath = false);
};

#endif