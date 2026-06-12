#ifndef LOGIN_H
#define LOGIN_H

#include "../Pessoa/Pessoa.h"
#include <string>

class Login {
private:
    std::string contaEmail;
    std::string contaPassword;
    Organizador organizadorLogado;

public:
    Login();
    Login(const std::string& email, const std::string& password, const Organizador& organizador);

    void colocarEmail(const std::string& email);
    void colocarPassword(const std::string& password);
    void colocarOrganizador(const Organizador& organizador);

    std::string obterEmail() const;
    std::string obterPassword() const;
    Organizador& obterOrganizador();
    const Organizador& obterOrganizador() const;
};

#endif
