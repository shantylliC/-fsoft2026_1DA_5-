//
// Created by HQCamachoPC on 12/06/2026.
//

#include "RoteiroView.h"
#include "Financeiro.h"
#include <limits>


void RoteiroView::mostrarMensagem(std::string mensagem) const {
    std::cout << mensagem << std::endl;
}

void RoteiroView::mostrarErro(std::string erro) const {
    std::cout << "ERRO: " << erro << std::endl;
}

void RoteiroView::mostrarTalao(const std::vector<LocalidadeModel*>& escolhas, double base, double iva, double total) const {
    std::cout << "\n========== TALAO DE RESERVA ==========" << std::endl;

    for (LocalidadeModel* item : escolhas) {
        std::cout << " - " << item->obterNome() << " " << item->obterPreco() << " EUR" << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Subtotal: " << base << " EUR" << std::endl;
    std::cout << "IVA:      " << iva  << " EUR" << std::endl;
    std::cout << "TOTAL:    " << total << " EUR" << std::endl;
    std::cout << "======================================\n" << std::endl;

    std::cout << "Pagamento:  " << Financeiro::obterMetodoPagamentoComoString() << std::endl;
    std::cout << "======================================\n" << std::endl;
}

int RoteiroView::pedirMetodoPagamento() const {
    int opcao;
    std::cout << "\n======= METODO DE PAGAMENTO =======\n";
    std::cout << "0. Dinheiro \n";
    std::cout << "1. Cartao \n";
    std::cout << "2. Transferencia \n";
    std::cout << "Escolha uma opcao: ";

    if (!(std::cin >> opcao)) {
        std::cin.clear();
        // Limpa caracteres inválidos do buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1; // Retorna flag de erro para o controlador gerir
    }

    return opcao;
}
