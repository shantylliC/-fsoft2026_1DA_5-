#include "Login.h"

Login::Login() = default;

Login::Login(const std::string& email, const std::string& password, const Organizador& organizador)
    : contaEmail(email), contaPassword(password), organizadorLogado(organizador) {
}

void Login::colocarEmail(const std::string& email) {
    contaEmail = email;
}

void Login::colocarPassword(const std::string& password) {
    contaPassword = password;
}

void Login::colocarOrganizador(const Organizador& organizador) {
    organizadorLogado = organizador;
}

std::string Login::obterEmail() const {
    return contaEmail;
}

std::string Login::obterPassword() const {
    return contaPassword;
}

Organizador& Login::obterOrganizador() {
    return organizadorLogado;
}

const Organizador& Login::obterOrganizador() const {
    return organizadorLogado;
}
