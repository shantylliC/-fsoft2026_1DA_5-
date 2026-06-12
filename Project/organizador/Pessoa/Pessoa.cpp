#include "Pessoa.h"

Pessoa::Pessoa()
    : idade(0) {
}

Pessoa::Pessoa(const std::string& nome, int idade, const std::string& email,
               const std::string& bi, const std::string& validade)
    : nome(nome), email(email), bi(bi), validade(validade), idade(idade) {
}

Pessoa::~Pessoa() = default;

std::string Pessoa::obterNome() const {
    return nome;
}

std::string Pessoa::obterEmail() const {
    return email;
}

std::string Pessoa::obterBI() const {
    return bi;
}

std::string Pessoa::obterValidade() const {
    return validade;
}

int Pessoa::obterIdade() const {
    return idade;
}

void Pessoa::colocarNome(const std::string& nome) {
    this->nome = nome;
}

void Pessoa::colocarEmail(const std::string& email) {
    this->email = email;
}

void Pessoa::colocarBI(const std::string& bi) {
    this->bi = bi;
}

void Pessoa::colocarValidade(const std::string& validade) {
    this->validade = validade;
}

void Pessoa::colocarIdade(int idade) {
    this->idade = idade;
}

Viajante::Viajante() = default;

Organizador::Organizador() = default;

void Organizador::adicionarViajante(const Viajante& viajante) {
    listaViajantes.push_back(viajante);
}

const std::vector<Viajante>& Organizador::obterViajantes() const {
    return listaViajantes;
}

std::size_t Organizador::obterNumeroViajantes() const {
    return listaViajantes.size();
}

bool Organizador::substituirViajante(std::size_t indice, const Viajante& viajante) {
    if (indice >= listaViajantes.size()) {
        return false;
    }

    listaViajantes[indice] = viajante;
    return true;
}

void Organizador::limparViajantes() {
    listaViajantes.clear();
}