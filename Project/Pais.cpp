//
// Created by HQCamachoPC on 08/05/2026.
//

#include "Pais.h"

void Pais::carregarDeLinha(std::string linha) {
    size_t pos = linha.find(';');
    if (pos != std::string::npos) {
        this->id = std::stoi(linha.substr(0, pos));
        this->nome = linha.substr(pos + 1);
    }
}

void Pais::mostrarDados() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << " ID: " << id << " | Nome: " << nome << std::endl;
    std::cout << "---------------------------------" << std::endl;
}