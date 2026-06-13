//
// Created by HQCamachoPC on 12/06/2026.
//

#include "LocalidadeView.h"
#include "CidadeModel.h"
#include "AtividadeModel.h"

void LocalidadeView::mostrarDetalhes(const LocalidadeModel* localidade) const {
    if (localidade != nullptr) {

        // 1. Se for uma ATIVIDADE (Descobrimos usando dynamic_cast)
        if (dynamic_cast<const AtividadeModel*>(localidade) != nullptr) {
            std::cout << "\t\t" << localidade->obterID() << localidade->obterNome()
                      << " |  " << localidade->obterPreco() << " EUR" << std::endl;
        }

        // 2. Se for uma CIDADE (Descobrimos usando dynamic_cast)
        else if (dynamic_cast<const CidadeModel*>(localidade) != nullptr) {
            std::cout << "\t" << localidade->obterID() << localidade->obterNome()
                      << " |  " << localidade->obterPreco() << " EUR" << std::endl;
        }

        // 3. Se não for nenhuma das de cima, é um PAÍS (comporta-se como o original)
        else {
            std::cout << "---------------------------------" << std::endl;
            std::cout << " ID: " << localidade->obterID() << " | Nome: " << localidade->obterNome() << std::endl;
            std::cout << "---------------------------------" << std::endl;
        }
    }
}
void LocalidadeView::mostrarErroFicheiro() const {
    std::cout << "\nFalha ao ler os detalhes da localidade.\n";
}