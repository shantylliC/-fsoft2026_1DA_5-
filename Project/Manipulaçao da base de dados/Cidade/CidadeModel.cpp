//
// Created by HQCamachoPC on 12/06/2026.
//

#include "CidadeModel.h"

#include "Excecoes.h"

// Construtores
CidadeModel::CidadeModel() : LocalidadeModel(), paisAssociado(0), precoCidade(0.0) {}

CidadeModel::CidadeModel(int _id, std::string _nome, int _paisAssociado, double _precoCidade)
    : LocalidadeModel(_id, _nome), paisAssociado(_paisAssociado), precoCidade(_precoCidade) {}

// Getters
int CidadeModel::obterIdPais() const {
    return paisAssociado;
}

double CidadeModel::obterPreco() const {
    return precoCidade;
}




// A lógica de leitura tal como a escreveste, perfeita para o Modelo!
void CidadeModel::carregarDeLinha(std::string linha) {

try { // <-- O 'try' tem de abrir logo no início para proteger os std::stoi/stod
    size_t pos = 0;
    size_t proximo;

    // ID DO PAÍS
    proximo = linha.find(';', pos);
    paisAssociado = std::stoi(linha.substr(pos, proximo - pos));
    pos = proximo + 1;

    // ID DA CIDADE
    proximo = linha.find(';', pos);
    id = std::stoi(linha.substr(pos, proximo - pos));
    pos = proximo + 1;

//VALIDAÇÃO DO ID DA CIDADE
        if (id <= 0) {
            throw IDInvalidoException("ID invalido (" + std::to_string(id) + ") na Cidade.");
        }


    // NOME DA CIDADE
    proximo = linha.find(';', pos);
    nome = linha.substr(pos, proximo - pos);
    pos = proximo + 1;

    // PREÇO
    precoCidade = std::stod(linha.substr(pos));

//VALIDAÇÃO DO NOME VAZIO
      if (nome.empty()) {
            throw ErroFormatacaoFicheiroException("Erro: Encontrada uma cidade sem nome.");
        }



        // LANÇAR EXCEÇÃO SE O PREÇO FOR NEGATIVO
        if (precoCidade < 0) {
            throw PrecoInvalidoException("Preco negativo detetado na Cidade ID: " + std::to_string(id));
        }

    }

catch (const std::invalid_argument& e) {
        // Se o ficheiro tiver "abc" em vez de um número, o std::stoi/stod lança invalid_argument
        throw ErroFormatacaoFicheiroException("Erro de formatação ao ler os dados da Cidade (letras em vez de numeros).");
    }

catch (const std::out_of_range& e) {
        // Se o número for absurdamente gigante
        throw ErroFormatacaoFicheiroException("Erro: Numero grande demais encontrado nos dados da Cidade.");
    }


}


