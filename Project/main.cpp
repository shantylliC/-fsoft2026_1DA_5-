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

    return 0;
}