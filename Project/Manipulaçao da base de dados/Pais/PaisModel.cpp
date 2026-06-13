//
// Created by HQCamachoPC on 12/06/2026.
//

#include "PaisModel.h"

void PaisModel::carregarDeLinha(std::string linha) {
    size_t pos = linha.find(';');
    if (pos != std::string::npos) {
        // A lógica matemática/processamento de strings fica toda no modelo
        id = std::stoi(linha.substr(0, pos));
        nome = linha.substr(pos + 1);
    }
}
