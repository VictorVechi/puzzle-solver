#include "board.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::cout, std::endl;

Board::Board() {
    tabuleiro = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    posBranco[0] = 0;
    posBranco[1] = 0;
}

Board::Board(vector<vector<int>> tabuleiro) {
    this->tabuleiro = tabuleiro;
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == 0) {
                posBranco[0] = linha;
                posBranco[1] = coluna;
            }
        }
    }
}

Board::~Board() {}

bool Board::operator<(const Board& outro) const {
    return this->tabuleiro < outro.tabuleiro;
}

bool Board::operator!=(const Board& outro) const {
    return this->tabuleiro != outro.tabuleiro;
}

void Board::imprimirTabuleiro() const {
    cout << "+---+---+---+" << endl;
    for (const auto& linha : tabuleiro) {
        for (const auto& valor : linha) {
            cout << "| " << valor << " ";
        }
        cout << "|" << endl;
        cout << "+---+---+---+" << endl;
    }
}

bool Board::isObjective() {
    vector<vector<int>> objetivo = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    return tabuleiro == objetivo;
}

void Board::trocarComBranco(vector<vector<int>>& matriz, int novaLinha, int novaColuna) {
    int valorAntigo = matriz[novaLinha][novaColuna];
    matriz[novaLinha][novaColuna] = 0;
    matriz[posBranco[0]][posBranco[1]] = valorAntigo;
}

vector<Board> Board::obterEstadosPossiveis() {
    vector<Board> proximosEstados;
    int movimentos[4] = {-1, 1, -1, 1};
    int novaLinha, novaColuna;

    for (int i = 0; i < 4; i++) {
        novaLinha = posBranco[0];
        novaColuna = posBranco[1];

        if (i < 2) {
            novaLinha += movimentos[i];
        } else {
            novaColuna += movimentos[i];
        }

        if (novaLinha >= 0 && novaLinha < 3 && novaColuna >= 0 && novaColuna < 3) {
            vector<vector<int>> novoTabuleiro = tabuleiro;
            trocarComBranco(novoTabuleiro, novaLinha, novaColuna);
            proximosEstados.emplace_back(Board(novoTabuleiro));
        }
    }
    return proximosEstados;
}

vector<vector<int>> Board::getTabuleiro() const {
    return tabuleiro;
}