#include "LoginView.h"

#include <iostream>
#include <limits>

int LoginView::lerInteiro(const std::string& mensagem) {
    int valor = 0;

    while (true) {
        std::cout << mensagem;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }

        std::cout << "Valor invalido. Tente novamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int LoginView::lerInteiroMinimo(const std::string& mensagem, int minimo) {
    while (true) {
        const int valor = lerInteiro(mensagem);
        if (valor >= minimo) {
            return valor;
        }

        std::cout << "O valor deve ser maior ou igual a " << minimo << ".\n";
    }
}

int LoginView::mostrarMenuInicial() {
    std::cout << "\nBem-vindo a nossa agencia de viagens!\n";
    std::cout << "1 - Registar\n";
    std::cout << "2 - Fazer login\n";
    std::cout << "3 - Sair\n";
    return lerInteiro("Escolha: ");
}

int LoginView::mostrarMenuFalhaLogin() {
    std::cout << "Email ou password incorretos!\n";
    std::cout << "1 - Tentar novamente\n";
    std::cout << "2 - Registar-se\n";
    std::cout << "3 - Sair\n";
    return lerInteiro("Escolha: ");
}

void LoginView::mostrarCabecalhoRegisto() {
    std::cout << "\n--- REGISTO ---\n";
}

std::string LoginView::pedirEmailRegisto() {
    std::string email;
    std::cout << "Indique o seu email: ";
    std::getline(std::cin, email);
    return email;
}

std::string LoginView::pedirPasswordRegisto() {
    std::string password;
    std::cout << "Crie a sua password: ";
    std::getline(std::cin, password);
    return password;
}

void LoginView::pedirDadosLogin(std::string& email, std::string& password) {
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Password: ";
    std::getline(std::cin, password);
}

void LoginView::preencherDadosPessoa(Pessoa& pessoa, const std::string& tipo, bool pedirEmail) {
    std::string texto;

    std::cout << "\n--- " << tipo << " ---\n";
    std::cout << "Nome: ";
    std::getline(std::cin, texto);
    pessoa.colocarNome(texto);

    pessoa.colocarIdade(lerInteiroMinimo("Idade: ", 0));

    if (pedirEmail) {
        std::cout << "Email: ";
        std::getline(std::cin, texto);
        pessoa.colocarEmail(texto);
    }

    std::cout << "Numero do BI: ";
    std::getline(std::cin, texto);
    pessoa.colocarBI(texto);

    std::cout << "Validade do BI: ";
    std::getline(std::cin, texto);
    pessoa.colocarValidade(texto);
}

int LoginView::pedirNumeroViajantes() {
    return lerInteiroMinimo("Numero viajantes: ", 0);
}

void LoginView::mostrarDadosTodos(const Organizador& organizador) {
    std::cout << "\n=== ORGANIZADOR ===\n";
    std::cout << "Nome: " << organizador.obterNome() << '\n';
    std::cout << "Idade: " << organizador.obterIdade() << '\n';
    std::cout << "Email: " << organizador.obterEmail() << '\n';
    std::cout << "Numero do BI: " << organizador.obterBI() << '\n';
    std::cout << "Validade do BI: " << organizador.obterValidade() << '\n';

    const auto& viajantes = organizador.obterViajantes();
    std::cout << "\n=== VIAJANTES ===\n";
    if (viajantes.empty()) {
        std::cout << "Sem viajantes registados.\n";
        return;
    }

    for (std::size_t i = 0; i < viajantes.size(); ++i) {
        std::cout << "\nViajante " << (i + 1) << '\n';
        std::cout << "Nome: " << viajantes[i].obterNome() << '\n';
        std::cout << "Idade: " << viajantes[i].obterIdade() << '\n';
        std::cout << "Email: " << viajantes[i].obterEmail() << '\n';
        std::cout << "Numero do BI: " << viajantes[i].obterBI() << '\n';
        std::cout << "Validade do BI: " << viajantes[i].obterValidade() << '\n';
    }
}

bool LoginView::confirmarDados() {
    return lerInteiro("\nConfirma que esta tudo correto? (1=sim, 0=nao): ") == 1;
}

int LoginView::escolherQuemAlterar(int numViajantes) {
    std::cout << "\nDe quem deseja alterar os dados?\n";
    std::cout << "0 - Organizador\n";
    for (int i = 0; i < numViajantes; ++i) {
        std::cout << (i + 1) << " - Viajante " << (i + 1) << '\n';
    }

    return lerInteiro("Escolha: ");
}

int LoginView::perguntarVerDados() {
    return lerInteiro("\nDeseja ver os seus dados? (1 sim / 0 nao): ");
}

int LoginView::perguntarCriarNovaViagem() {
    return lerInteiro("\nCriar nova viagem? (1 sim / 0 nao): ");
}

void LoginView::mostrarMensagem(const std::string& mensagem) {
    std::cout << mensagem << '\n';
}
