//
// Created by HQCamachoPC on 12/06/2026.
//

#include "RoteiroModel.h"
#include "Financeiro.h"
#include <fstream>

RoteiroModel::RoteiroModel() {}

RoteiroModel::~RoteiroModel() {
    listaEscolhas.clear();
}

void RoteiroModel::adicionarEscolha(LocalidadeModel* localidade) {
    if (localidade != nullptr) {
        listaEscolhas.push_back(localidade);
    }
}

void RoteiroModel::esvaziar() {
    listaEscolhas.clear();
}

const std::vector<LocalidadeModel*>& RoteiroModel::obterEscolhas() const {
    return listaEscolhas;
}

// ATUALIZADO: Sem o parâmetro antigo de atividades
bool RoteiroModel::gravarFicheiroReserva(int numeroReserva,
                               const std::string& estado,
                               const std::string& titulo,
                               const std::string& notas,
                               const std::string& dataChegada,
                               const std::string& dataSaida,
                               int duracao,
                               double subtotal,
                               double totalFinal) {

    if (listaEscolhas.empty()) return false;

    std::ofstream ficheiroReserva("BaseDados-reserva.txt", std::ios::app);
    if (!ficheiroReserva.is_open()) return false;

    ficheiroReserva << "RESERVA Nº        " << numeroReserva << "\n\n";
    ficheiroReserva << "Estado:           " << estado << "\n";
    ficheiroReserva << "Titulo:           " << titulo << "\n";
    ficheiroReserva << "Notas:            " << notas << "\n";

    // ATUALIZADO: Escreve a localidade e imediatamente as atividades DELA
    ficheiroReserva << "Destinos e Atividades:\n";
    for (LocalidadeModel* item : listaEscolhas) {
        if (item != nullptr) {
            ficheiroReserva << "  -> " << item->obterNome() << " (" << item->obterPreco() << " EUR)\n";

            // NOVO: Procura as atividades guardadas dentro desta instância de Localidade
            for (const std::string& atividade : item->obterAtividades()) {
                ficheiroReserva << "       * " << atividade << "\n";
            }
        }
    }

    ficheiroReserva << "Subtotal:         " << subtotal << " EUR\n";
    ficheiroReserva << "Custo total (IVA):" << totalFinal << " EUR\n";
    ficheiroReserva << "Metodo pagamento: " << Financeiro::obterMetodoPagamentoComoString() << "\n";

    ficheiroReserva << "Data de chegada:  " << dataChegada << "\n";
    ficheiroReserva << "Data de Saida:    " << dataSaida << "\n";
    ficheiroReserva << "Duracao:          " << duracao << " dias\n";

    // (O bloco antigo "Atividades dinâmicas" que ficava aqui no fim foi removido!)

    ficheiroReserva << "\n====================================\n\n";

    ficheiroReserva.close();
    return true;
}
