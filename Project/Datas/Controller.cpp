#include "Controller.h"

Data Controller::obterDataValidada() {

    while (true) {
        DadosBrutos dados = interfaceUsuario.pedirDatasViagem();

        try {

            Data viagem(dados.diaC, dados.mesC, dados.anoC, dados.diaS, dados.mesS, dados.anoS);

            while (interfaceUsuario.perguntarMaisHorarios()) {
                std::string hor = interfaceUsuario.pedirHorario();
                viagem.addHorario(hor);
            }

            Calendario ch = viagem.getChegada();
            Calendario sa = viagem.getSaida();
            std::string strChegada = std::to_string(ch.dia) + "/" + std::to_string(ch.mes) + "/" + std::to_string(ch.ano);
            std::string strSaida = std::to_string(sa.dia) + "/" + std::to_string(sa.mes) + "/" + std::to_string(sa.ano);

            interfaceUsuario.mostrarSucesso(strChegada, strSaida, viagem.getNumeroDias(), viagem.getHorarios());

            return viagem;

        } catch (const DataInvalidaException& e) {
            interfaceUsuario.mostrarErro(e.what());
        }
    }
}