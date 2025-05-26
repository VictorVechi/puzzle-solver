#ifndef DFS_HPP
#define DFS_HPP

#include "board.hpp"
#include <stack>
#include <set>

using std::stack, std::set;

class DFS {
    private:
        stack<Board> pilhaEstados;
        set<Board> estadosVisitados;
        bool encontrouObjetivo = false;
    public:
        DFS();
        ~DFS();
        void dfs(Board estadoInicial, bool showPath = false);
};

#endif