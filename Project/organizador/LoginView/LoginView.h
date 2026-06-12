#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "../Pessoa/Pessoa.h"
#include <string>

class LoginView {
private:
    int lerInteiro(const std::string& mensagem);
    int lerInteiroMinimo(const std::string& mensagem, int minimo);

public:
    int mostrarMenuInicial();
    int mostrarMenuFalhaLogin();
    void mostrarCabecalhoRegisto();
    std::string pedirEmailRegisto();
    std::string pedirPasswordRegisto();
    void pedirDadosLogin(std::string& email, std::string& password);
    void preencherDadosPessoa(Pessoa& pessoa, const std::string& tipo, bool pedirEmail = false);
    int pedirNumeroViajantes();
    void mostrarDadosTodos(const Organizador& organizador);
    bool confirmarDados();
    int escolherQuemAlterar(int numViajantes);
    int perguntarVerDados();
    int perguntarCriarNovaViagem();
    void mostrarMensagem(const std::string& mensagem);
};

#endif
