#include "dfs.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector, std::map;
using std::cout, std::endl;

DFS::DFS(){}

DFS::~DFS(){}

void DFS::dfs(Board estadoInicial, bool showPath) {
    pilhaEstados.push(estadoInicial);
    estadosVisitados.insert(estadoInicial);
    map<Board, Board> mapaPais;
    mapaPais[estadoInicial] = estadoInicial;

    while(!pilhaEstados.empty()) { // Laço principal da DFS
        Board estadoAtual = pilhaEstados.top();
        pilhaEstados.pop();

        if(estadoAtual.isObjective()) {
            vector<Board> caminho;
            // Reconstrói o caminho da solução
            for(Board estado = estadoAtual; estado != estadoInicial; estado = mapaPais[estado]) {
                caminho.push_back(estado);
            }
            caminho.push_back(estadoInicial);
            std::reverse(caminho.begin(), caminho.end());

            cout << "Solução encontrada pelo DFS!" << endl;
            cout << "Tamanho do caminho para a solução: " << caminho.size() << endl;
            cout << "Estados visitados: " << estadosVisitados.size() << endl;
            cout << "Caminho tomado: " << endl;
            if (showPath) {
                for (const auto& instancia : caminho) {
                    instancia.imprimirTabuleiro();
                    cout << endl;
                }
            }
            return;
        }

        vector<Board> proximosEstados = estadoAtual.obterEstadosPossiveis();
        // Expande os próximos estados possíveis
        for(Board& filho : proximosEstados){
            if(!estadosVisitados.count(filho)) {
                pilhaEstados.push(filho);
                estadosVisitados.insert(filho);
                mapaPais[filho] = estadoAtual;
            }
        }
    }
}