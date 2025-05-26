#include "util.hpp"
#include <vector>
using std::vector;

bool hasSolution(const std::vector<std::vector<int>>& tabuleiro) {
    std::vector<int> elementos;
    int quantidadeInversoes = 0;

    for (const auto& linha : tabuleiro) {
        for (int valor : linha) {
            if (valor != 0) {
                elementos.push_back(valor);
            }
        }
    }

    for (size_t i = 0; i < elementos.size(); i++) {
        for (size_t j = i + 1; j < elementos.size(); j++) {
            if (elementos[i] > elementos[j]) {
                quantidadeInversoes++;
            }
        }
    }

    return quantidadeInversoes % 2 == 0;
}