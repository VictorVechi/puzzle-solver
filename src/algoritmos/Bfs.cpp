#include "bfs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

using std::vector, std::map, std::queue, std::set;
using std::cout, std::endl;

BFS::BFS() {}

BFS::~BFS() {}

// Busca em Largura (BFS) para resolver o 8-puzzle
void BFS::bfs(Board estadoInicial, bool showPath) {
    queue<Board> fila;
    set<Board> visitados;
    map<Board, Board> pais;

    fila.push(estadoInicial);
    visitados.insert(estadoInicial);
    pais[estadoInicial] = estadoInicial;

    while (!fila.empty()) { // Laço principal da BFS
        Board estadoAtual = fila.front();
        fila.pop();

        if (estadoAtual.ehObjetivo()) {
            vector<Board> caminho;
            // Reconstrói o caminho da solução
            for (Board estado = estadoAtual; estado != estadoInicial; estado = pais[estado]) {
                caminho.push_back(estado);
            }
            caminho.push_back(estadoInicial);
            std::reverse(caminho.begin(), caminho.end());

            cout << "Solução encontrada pelo BFS!" << endl;
            cout << "Tamanho do caminho: " << caminho.size() << endl;
            cout << "Estados visitados: " << visitados.size() << endl;
            cout << "Caminho percorrido:" << endl;
            if (showPath) {
                for (const auto& instancia : caminho) {
                    instancia.imprimirTabuleiro();
                    cout << endl;
                }
            }
            return;
        }

        // Expande os próximos estados possíveis
        for (Board& proximoEstado : estadoAtual.obterEstadosPossiveis()) {
            if (!visitados.count(proximoEstado)) {
                fila.push(proximoEstado);
                visitados.insert(proximoEstado);
                pais[proximoEstado] = estadoAtual;
            }
        }
    }
}