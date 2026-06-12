//
// Created by HQCamachoPC on 08/05/2026.
//

#include "Cidade.h"

int Cidade::obterIdPais() const {
    return id_pais;
}

double Cidade::obterPreco() const {
    return preco_cidade;
}

void Cidade::carregarDeLinha(std::string linhaLida) {
    // 1. Extrair ID Pais
    size_t posicao1 = linhaLida.find(';');
    this->id_pais = std::stoi(linhaLida.substr(0, posicao1));
    std::string sobrante1 = linhaLida.substr(posicao1 + 1);

    // 2. Extrair ID Cidade
    size_t posicao2 = sobrante1.find(';');
    this->id = std::stoi(sobrante1.substr(0, posicao2));
    std::string sobrante2 = sobrante1.substr(posicao2 + 1);

    // 3. Extrair Nome
    size_t posicao3 = sobrante2.find(';');
    this->nome = sobrante2.substr(0, posicao3);

    // 4. Extrair Preço (procura o ':' no final)
    std::string sobrante3 = sobrante2.substr(posicao3 + 1);
    size_t posicao4 = sobrante3.find(':');
    // Se não encontrar ':', lê até ao fim da linha
    this->preco_cidade = std::stod(sobrante3.substr(0, posicao4));
}

void Cidade::mostrarDados() {
    std::cout << "\t" << id << " . " << nome
              << " | Preço: " << preco_cidade << " € (EUR)" << std::endl;
}