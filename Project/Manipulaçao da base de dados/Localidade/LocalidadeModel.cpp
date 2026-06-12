#include "LocalidadeModel.h"

int LocalidadeModel::obterID() const {
    return id;
}

std::string LocalidadeModel::obterNome() const {
    return nome;
}

double LocalidadeModel::obterPreco() const {
    return 0.0;
}

void LocalidadeModel::adicionarAtividade(const std::string& atividade) {

    atividadesDaCidade.push_back(atividade);

}

// 4. EM CASO DE LEITURA: Devolve a lista de atividades para o RoteiroModel poder ler

const std::vector<std::string>& LocalidadeModel::obterAtividades() const {
    return atividadesDaCidade;
}
