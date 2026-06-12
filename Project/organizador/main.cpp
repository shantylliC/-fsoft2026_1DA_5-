#include "AutenticacaoController/AutenticacaoController.h"

#include <iostream>

int main() {
    AutenticacaoController fluxoLogin;
    Organizador* utilizador = fluxoLogin.executar();

    if (utilizador == nullptr) {
        std::cout << "\nA encerrar o programa...\n";
        return 0;
    }

    std::cout << "\n--------------------------------------------------\n";
    std::cout << "Bem-vindo ao sistema de Gestao de Viagens!\n";
    std::cout << "--------------------------------------------------\n";

    return 0;
}
