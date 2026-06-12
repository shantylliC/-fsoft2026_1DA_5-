#include <iostream>
#include <string>
#include <windows.h>
#include "Data.h"
#include "numero_de_reserva/Modelo/n_reserva_modelo.h"
#include "numero_de_reserva/View/n_reserva_view.h"
#include "numero_de_reserva/Controlador/n_reserva_controlador.h"
#include "titulo_notas/Modelo/titulo_notas_modelo.h"
#include "titulo_notas/View/titulo_notas_view.h"
#include "titulo_notas/Controlador/titulo_notas_controlador.h"
#include "alt_estados/alt_estados.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int diaC, mesC, anoC;
    int diaS, mesS, anoS;


    Viagem viagem;

    std::cout << "=== NOVA VIAGEM ===\n";
    std::cout << "Preencha os dados da viagem:\n\n";
    viagem.mudarData();


    std::cout << ">> Título:\n";
    while (!viagem.mudarTitulo()) {
        std::cout << "Vote a inserir o título:\n";
    }

    std::cout << ">> Deseja inserir notas?\n";
    char opcaonotas;
    std::cout << "1. Sim (s)\n";
    std::cout << "2. Não (n)\n";
    std::cout << "Opção: ";
    std::cin >> opcaonotas;
    std::cin.ignore();

    switch (opcaonotas) {
        case 's':
        case 'S':
        {

            while (!viagem.mudarNotasViagem()) {
                std::cout << "Volte a inserir as notas:\n";
            }
        };
            break;
        case 'n':
        case 'N':
        {
            break;
        }
        default: std::cout << "Opcao invalida.\n";
    }

    std::cout << "\n>> Custo da Viagem\n";
    while (!viagem.mudarCustoTotal()) {
        std::cout << "Vote a inserir o custo:\n";
    }

    std::cout << "\n>> Metodo de pagamento:\n";
    while (!viagem.mudarMetodoPagamento()) {
        std::cout << "Vote a inserir o metodo de pagamento:\n";
    }

    std::cout << "\n=== DADOS PREENCHIDOS ===\n";
    viagem.print();
    std::cout << "\nPode agora editar os dados no menu.\n";

    bool sair = false;

    while (!sair) {
        int opcao;
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Ver viagem\n";
        std::cout << "2. Mudar titulo\n";
        std::cout << "3. Mudar notas\n";
        std::cout << "4. Mudar custo total\n";
        std::cout << "5. Mudar metodo de pagamento\n";
        std::cout << "6. Mudar data de reserva\n";
        std::cout << "7. Mostrar numero de reserva\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: viagem.print();                                             break;
            case 2: viagem.mudarTitulo();                                       break;
            case 3: viagem.mudarNotasViagem();                                  break;
            case 4: viagem.mudarCustoTotal();                                   break;
            case 5: viagem.mudarMetodoPagamento();                              break;
            case 6: viagem.mudarData();                                         break;
            case 7: viagem.mostrarNumeroReserva();                              break;
            case 0: sair = true;                                                break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    viagem.estadoConfirmar();
    viagem.gravarFicheiro();
    std::cout << "A sair...\n";
    return 0;
}