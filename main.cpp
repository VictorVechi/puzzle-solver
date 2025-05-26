#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip> 
#include "board.hpp"
#include "util.hpp"
#include "bfs.hpp"
#include "dfs.hpp"

using std::vector, std::cout, std::endl;

int main() {
    BFS bfs;
    DFS dfs;
    vector<vector<int>> tabuleiro =
    {
        {2, 3, 0},
        {1, 4, 5},
        {6, 7, 8}
    };
    Board estadoInicial(tabuleiro);

    if (!hasSolution(estadoInicial.getTabuleiro())) {
        cout << "NÃO é solucionável!" << endl;
        return 0;
    }

    auto tempoInicial = std::chrono::high_resolution_clock::now();
    // Para exibir o caminho tomado, passe 'true' como segundo argumento
    bfs.bfs(estadoInicial, false);
    auto tempoFinal = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = tempoFinal - tempoInicial;   
    cout << std::fixed << std::setprecision(2);
    cout << "Tempo de execução: " << duracao.count() << " segundos" << endl;

    cout << "-------------------------------" << endl;

    tempoInicial = std::chrono::high_resolution_clock::now();
    // Para exibir o caminho tomado, passe 'true' como segundo argumento
    dfs.dfs(estadoInicial, false);
    tempoFinal = std::chrono::high_resolution_clock::now();

    duracao = tempoFinal - tempoInicial;   
    cout << std::fixed << std::setprecision(2);
    cout << "Tempo de execução: " << duracao.count() << " segundos" << endl;

    return 0;
}