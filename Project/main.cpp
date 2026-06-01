#include <iostream>
#include <string>
#include "Data.h"

int main() {
    int diaC, mesC, anoC;
    int diaS, mesS, anoS;

    std::cout << "Introduza a data de chegada (dia mes ano):" << std::endl;
    if (!(std::cin >> diaC >> mesC >> anoC)) return 1;

    std::cout << "Introduza a data de Saida (dia mes ano):" << std::endl;
    if (!(std::cin >> diaS >> mesS >> anoS)) return 1;

    std::cin.ignore();

    try {
        Data viagem(diaC, mesC, anoC, diaS, mesS, anoS);

        std::string opcao;
        while (true) {
            std::cout << "Deseja adicionar um horario? (s/n):" << std::endl;
            std::getline(std::cin, opcao);
            if (opcao != "s" && opcao != "S") break;

            std::string horario;
            std::cout << "Introduza o horario e atividade:" << std::endl;
            std::getline(std::cin, horario);
            viagem.addHorario(horario);
        }

        std::cout << "\n--- DADOS DA VIAGEM ---" << std::endl;
        Calendario ch = viagem.getChegada();
        Calendario sa = viagem.getSaida();

        std::cout << "Data de Chegada: " << ch.dia << "/" << ch.mes << "/" << ch.ano << std::endl;
        std::cout << "Data de Saida: " << sa.dia << "/" << sa.mes << "/" << sa.ano << std::endl;
        std::cout << "Duracao: " << viagem.getNumeroDias() << " dias" << std::endl;

        std::cout << "Horarios planeados:" << std::endl;
        for (const std::string& h : viagem.getHorarios()) {
            std::cout << " -> " << h << std::endl;
        }

    } catch (const DataInvalidaException& e) {
        std::cerr << e.what() << std::endl;
    }
        SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Viagem viagem;
    viagem.novoNumeroReserva();

    std::cout << "=== NOVA VIAGEM ===\n";
    std::cout << "Preencha os dados da viagem:\n\n";

    std::cout << ">> Título:\n";
    while (!viagem.mudarTitulo()) {
        std::cout << "Vote a inserir o título:\n";
    }
    std::cout << "\n>> Custo da Viagem\n";
    while (!viagem.mudarCustoTotal()) {
        std::cout << "Vote a inserir o custo:\n";
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

    std::cout << "\n>> Metodo de pagamento:\n";
    while (!viagem.mudarMetodoPagamento()) {
        std::cout << "Vote a inserir o metodo de pagamento:\n";
    }

    std::cout << "\n>> Data de reserva:\n";
    while (!viagem.mudarDataReserva()) {
        std::cout << "Tente novamente:\n";
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
        std::cout << "3. Mudar custo total\n";
        std::cout << "4. Mudar notas\n";
        std::cout << "5. Mudar metodo de pagamento\n";
        std::cout << "6. Mudar data de reserva\n";
        std::cout << "7. Mostrar numero de reserva\n";
        std::cout << "0. Sair\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: viagem.print();                  break;
            case 2: viagem.mudarTitulo();            break;
            case 3: viagem.mudarCustoTotal();        break;
            case 4: viagem.mudarNotasViagem();       break;
            case 5: viagem.mudarMetodoPagamento();   break;
            case 6: viagem.mudarDataReserva();       break;
            case 7: viagem.mostrarNumeroReserva();   break;
            case 0: sair = true;                     break;
            default: std::cout << "Opcao invalida.\n";
        }
    }

    viagem.estadoConfirmar();
    viagem.gravarFicheiro();
    std::cout << "A sair...\n";
    return 0;
}