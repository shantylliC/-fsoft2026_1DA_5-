//
// Created by HQCamachoPC on 08/05/2026.
//

#include "Roteiro.h"

#include <fstream>

Roteiro::Roteiro() {}

Roteiro::~Roteiro() {
    // Apenas limpamos o vetor. NÃO fazemos delete nos ponteiros porque estes pertencem ao Repositorio.
    listaPonteirosEscolhidos.clear();
}

void Roteiro::registarEscolha(Localidade* ponteiroParaAdicionar) {
    if (ponteiroParaAdicionar != nullptr) {
        listaPonteirosEscolhidos.push_back(ponteiroParaAdicionar);
        std::cout << "Adicionado: " << ponteiroParaAdicionar->obterNome() << std::endl;
    }
}

void Roteiro::esvaziarRoteiro() {
    listaPonteirosEscolhidos.clear();
    std::cout << "Roteiro limpo!" << std::endl;
}

void Roteiro::mostrarResumo() {
    if (listaPonteirosEscolhidos.empty()) {
        std::cout << "\nO seu roteiro esta vazio!, adicione destinos para ter um!" << std::endl;
        return;
    }

    std::cout << "\n========== TALAO DE RESERVA ==========" << std::endl;
    for (Localidade* localidade : listaPonteirosEscolhidos) {
        std::cout << " - " << localidade->obterNome()
                  << " [" << localidade->obterPreco() << " EUR]" << std::endl;
    }

    // Chamadas estaticas a classe Financeiro
    double base = Financeiro::calcularTotalBase(listaPonteirosEscolhidos);
    double iva = Financeiro::calcularValorIVA(base);
    double totalFinal = Financeiro::calcularTotalComIVA(base);

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Subtotal (Base):      " << base << " € (EUR)" << std::endl;
    std::cout << "IVA (23%):            " << iva << " € (EUR)" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "TOTAL A PAGAR:        " << totalFinal << " € (EUR)" << std::endl;
    std::cout << "======================================\n" << std::endl;
}

void Roteiro::gravarFicheiro() {
    if (listaPonteirosEscolhidos.empty()) return;

    std::ofstream ficheiroSaida("Base de dados - reserva.txt", std::ios::app);

    if (ficheiroSaida.is_open()) {
        double valorBase = Financeiro::calcularTotalBase(listaPonteirosEscolhidos);
        double valorComIVA = Financeiro::calcularTotalComIVA(valorBase);

        ficheiroSaida << "========================================" << std::endl;
        ficheiroSaida << "NOVA RESERVA REGISTADA" << std::endl;
        ficheiroSaida << "========================================" << std::endl;

        for (Localidade* localidade : listaPonteirosEscolhidos) {
            ficheiroSaida << " -> " << localidade->obterNome()
                          << " (" << localidade->obterPreco() << " EUR)" << std::endl;
        }

        ficheiroSaida << "----------------------------------------" << std::endl;
        ficheiroSaida << "SUBTOTAL: " << valorBase << " EUR" << std::endl;
        ficheiroSaida << "TOTAL (c/ IVA): " << valorComIVA << " EUR" << std::endl;
        ficheiroSaida << "========================================\n\n" << std::endl;

        ficheiroSaida.close();
        std::cout << "Reserva guardada com sucesso!'" << std::endl;
    } else {
        std::cerr << "Erro: Nao foi possivel guardar a sua reserva. Tente novamente" << std::endl;
    }
}