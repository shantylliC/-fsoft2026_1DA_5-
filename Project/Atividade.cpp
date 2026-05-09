//
// Created by HQCamachoPC on 08/05/2026.
//

#include "Atividade.h"

int Atividade::obterIdCidade() const {
    return id_cidade;
}

double Atividade::obterPreco() const {
    return preco_ticket;
}

void Atividade::carregarDeLinha(std::string linha) {
    // 1. Ignorar ID Pais (procura o primeiro ;)
    size_t posicao1 = linha.find(';');
    std::string sobrante1 = linha.substr(posicao1 + 1);

    // 2. ID Cidade
    size_t posicao2 = sobrante1.find(';');
    this->id_cidade = std::stoi(sobrante1.substr(0, posicao2));
    std::string sobrante2 = sobrante1.substr(posicao2 + 1);

    // 3. ID Atividade (vai para o 'id' da Localidade)
    size_t posicao3 = sobrante2.find(';');
    this->id = std::stoi(sobrante2.substr(0, posicao3));
    std::string sobrante3 = sobrante2.substr(posicao3 + 1);

    // 4. Nome Atividade
    size_t posicao4 = sobrante3.find(';');
    this->nome = sobrante3.substr(0, posicao4);

    // 5. Preço Ticket
    this->preco_ticket = std::stod(sobrante3.substr(posicao4 + 1));
}

void Atividade::mostrarDados() {
    std::cout << "\t\t" << id << " . " << nome
              << " | Preco: " << preco_ticket << " EUR" << std::endl;
}