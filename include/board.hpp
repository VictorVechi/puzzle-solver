#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

using std::vector;

class Board {
    private:
        vector<vector<int>> tabuleiro;
        int posBranco[2];
    public:
        Board();
        Board(vector<vector<int>> tabuleiro);
        ~Board();
        bool operator<(const Board& outro) const;
        bool operator!=(const Board& outro) const;
        void imprimirTabuleiro() const;
        bool isObjective();
        void trocarComBranco(vector<vector<int>>& matriz, int novoX, int novoY);
        vector<Board> obterEstadosPossiveis();
        vector<vector<int>> getTabuleiro() const;
};

#endif