#ifndef AUTENTICACAOCONTROLLER_H
#define AUTENTICACAOCONTROLLER_H

#include "../AutenticacaoService/AutenticacaoService.h"
#include "../Login/Login.h"
#include "../LoginView/LoginView.h"
#include <string>

class AutenticacaoController {
private:
    Login modelo;
    LoginView vista;
    AutenticacaoService servico;

    bool gerirRegisto(std::string email, std::string password);
    bool criarNovaViagem();
    bool reverEConfirmarDados();
    void copiarDadosPessoa(Pessoa& destino, const Pessoa& origem, bool copiarEmail);

public:
    Organizador* executar();
};

#endif