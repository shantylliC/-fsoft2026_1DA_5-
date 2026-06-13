
#include "AtividadeModel.h"
#include "../Exceçoes/Excecoes.h"
// Construtores
AtividadeModel::AtividadeModel() : LocalidadeModel(), cidadeAssociada(0), precoTicket(0.0) {}

AtividadeModel::AtividadeModel(int _id, std::string _nome, int _cidadeAssociada, double _precoTicket)
    : LocalidadeModel(_id, _nome), cidadeAssociada(_cidadeAssociada), precoTicket(_precoTicket) {}

// Getters
int AtividadeModel::obterIdCidade() const {
    return cidadeAssociada;
}

double AtividadeModel::obterPreco() const {
    return precoTicket;
}

// Leitura da linha (apenas dados, sem couts)
void AtividadeModel::carregarDeLinha(std::string linha) {
    try {
        size_t pos = 0;
        size_t proxima;

        // 1. Saltar ID Pais
        proxima = linha.find(';', pos);
        pos = proxima + 1;

        // 2. ID Cidade
        proxima = linha.find(';', pos);
        proxima = linha.find(';', pos);
        cidadeAssociada = std::stoi(linha.substr(pos, proxima - pos));
        pos = proxima + 1;

        // 3. ID Atividade (herdado)
        proxima = linha.find(';', pos);
        id = std::stoi(linha.substr(pos, proxima - pos));
        pos = proxima + 1;

        // VALIDAÇÃO DO ID DA ATIVIDADE
        if (id <= 0) {
            throw IDInvalidoException("ID invalido (" + std::to_string(id) + ") na Atividade.");
        }

        // 4. Nome Atividade (herdado)
        proxima = linha.find(';', pos);
        nome = linha.substr(pos, proxima - pos);
        nome = linha.substr(pos, proxima - pos);
        pos = proxima + 1;

        // VALIDAÇÃO DO NOME VAZIO
        if (nome.empty()) {
            throw ErroFormatacaoFicheiroException("Erro: Encontrada uma atividade sem nome.");
        }

        // 5. Preço
        precoTicket = std::stod(linha.substr(pos));

        // LANÇAR EXCEÇÃO SE O PREÇO FOR NEGATIVO
        // (Nota: corrigi aqui a tua variável antiga 'precoCidade' para 'precoTicket')
        if (precoTicket < 0) {
            throw PrecoInvalidoException("Preco negativo detetado na Atividade ID: " + std::to_string(id));
        }

    }
    catch (const std::invalid_argument& e) {
        throw ErroFormatacaoFicheiroException("Erro de formatacao ao ler os dados da Atividade.");
    }
    // Proteção contra estouro de memória por números gigantes
    catch (const std::out_of_range& e) {
        throw ErroFormatacaoFicheiroException("Erro: Numero grande demais encontrado nos dados da Atividade.");
    }
}
