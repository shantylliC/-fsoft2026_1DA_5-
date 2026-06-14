#include "View.h"

DadosBrutos View::pedirDatasViagem() {
    DadosBrutos dados;
    std::cout << "Introduza a data de inicio da viagem (dia mes ano):" << std::endl;
    std::cin >> dados.diaC >> dados.mesC >> dados.anoC;
    std::cout << "Introduza a data de termino da viagem (dia mes ano):" << std::endl;
    std::cin >> dados.diaS >> dados.mesS >> dados.anoS;
    std::cin.ignore();
    return dados;
}

void View::mostrarErro(const std::string& erro) {
    std::cerr << erro << std::endl;
}

bool View::perguntarMaisHorarios() {
    std::string opcao;
    std::cout << "Deseja adicionar um horario? (s/n):" << std::endl;
    std::getline(std::cin, opcao);
    return (opcao == "s" || opcao == "S");
}

std::string View::pedirHorario() {
    std::string horario;
    std::cout << "Introduza o horario e atividade:" << std::endl;
    std::getline(std::cin, horario);
    return horario;
}

void View::mostrarSucesso(const std::string& ch, const std::string& sa, int dias, const std::vector<std::string>& horarios) {
    std::cout << "\n--- DADOS DA VIAGEM ---" << std::endl;
    std::cout << "Data de inicio da viagem: " << ch << std::endl;
    std::cout << "Data de termino da viagem: " << sa << std::endl;
    std::cout << "Duracao: " << dias << " dias" << std::endl;
    std::cout << "Horarios planeados:" << std::endl;
    for (const std::string& h : horarios) {
        std::cout << " -> " << h << std::endl;
    }
}
