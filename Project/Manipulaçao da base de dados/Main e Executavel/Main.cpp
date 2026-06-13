#include <iostream>
#include <vector>
#include <string>
#include <limits>

// ==================================================
// CLASSES DO PROJETO REFATORADO (MVC)
// ==================================================
#include "RepositorioCatalogo.h"
#include "RoteiroController.h"
#include "PaisModel.h"
#include "CidadeModel.h"
#include "AtividadeModel.h"
#include "Excecoes.h"

#include "Controller.h"

int main() {
    // 1. Carregar dados com proteção imediata no arranque
    RepositorioCatalogo catalogo;
    try {
        catalogo.carregarTudo();
    }
    catch (const ErroFormatacaoFicheiroException& e) {
        std::cout << "\n[ERRO CRITICO DE SISTEMA]: " << e.what() << std::endl;
        std::cout << "O programa esta a ter problemas com a base de dados. Volte a tentar mais tarde.\n";
        return 1; // Fecha o programa com código de erro se a base de dados falhar
    }

    // 2. Instanciar o Controlador do Roteiro (O motor da Shantall)
    RoteiroController meuRoteiro;

    int indiceInicial = 0;
    const int itensPorPagina = 5;
    std::string comando = "";

    std::cout << "====================================================\n";
    std::cout << "           CATALOGO DE VIAGENS           \n";
    std::cout << "====================================================\n";

    while (comando != "0") {
        const std::vector<PaisModel*>& listaPaises = catalogo.obterPaises();
        int totalPaises = listaPaises.size();

        // --- MOSTRAR PAGINA ATUAL ---
        std::cout << "\n--- LISTA DE PAISES (Pagina " << (indiceInicial / itensPorPagina) + 1 << ") ---\n";

        for (int i = indiceInicial; i < indiceInicial + itensPorPagina && i < totalPaises; i++) {
            std::cout << "[ID: " << listaPaises[i]->obterID() << "] " << listaPaises[i]->obterNome() << std::endl;
        }

        std::cout << "\n================ MENU DE OPCOES ================\n";
        if (indiceInicial + itensPorPagina < totalPaises) std::cout << "P. Proxima Pagina\n";
        if (indiceInicial > 0) std::cout << "A. Pagina Anterior\n";
        std::cout << "E. Escolher Destino/Atividade (ID)\n";

        // --- A TUA TOMADA VISUAL ---
        std::cout << "D. Definir Datas da Viagem\n";

        std::cout << "M. Definir Metodo de Pagamento\n";
        std::cout << "V. Visualizar Roteiro e Fatura (Financeiro)\n";
        std::cout << "L. Limpar Roteiro\n";
        std::cout << "G. Gravar Reserva em Ficheiro\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> comando;

        // --- LÓGICA DE COMANDOS PROTEGIDA POR TRY-CATCH ---
        try {
            // Navegação de Páginas
            if (comando == "P" || comando == "p") {
                if (indiceInicial + itensPorPagina < totalPaises) indiceInicial += itensPorPagina;
            }
            else if (comando == "A" || comando == "a") {
                if (indiceInicial > 0) indiceInicial -= itensPorPagina;
            }

            // Seleção e Inserção no Roteiro (E)
            else if (comando == "E" || comando == "e") {
                int idBusca;
                std::cout << "Introduza o ID (Pais, Cidade ou Atividade) para adicionar: ";

                if (!(std::cin >> idBusca)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw InputInvalidoException("O ID introduzido e invalido! Deve digitar um numero inteiro.");
                }

                bool encontrado = false;

                // 1. Procurar nos Países
                for (PaisModel* p : catalogo.obterPaises()) {
                    if (p->obterID() == idBusca) {
                        meuRoteiro.registarEscolha(p);
                        encontrado = true;
                        break;
                    }
                }

                // 2. Procurar nas Cidades
                if (!encontrado) {
                    for (CidadeModel* c : catalogo.obterCidades()) {
                        if (c->obterID() == idBusca) {
                            meuRoteiro.registarEscolha(c);
                            encontrado = true;
                            break;
                        }
                    }
                }

                // 3. Procurar nas Atividades
                if (!encontrado) {
                    for (AtividadeModel* a : catalogo.obterAtividades()) {
                        if (a->obterID() == idBusca) {
                            meuRoteiro.registarEscolha(a);
                            encontrado = true;
                            break;
                        }
                    }
                }

                if (!encontrado) {
                    throw IDInvalidoException("Nenhuma localidade ou atividade encontrada com o ID " + std::to_string(idBusca));
                }
            }

            // --- A TUA IGNIÇÃO E LIGAÇÃO ---
            else if (comando == "D" || comando == "d") {
                std::cout << "\n[A abrir o modulo de Gestao de Datas...]\n";
                Controller motorDatas;

                Data dataFinal = motorDatas.obterDataValidada();
                meuRoteiro.definirDatas(dataFinal);
            }

            // Módulo Financeiro
            else if (comando == "M" || comando == "m") {
                meuRoteiro.alterarMetodoPagamento();
            }

            // Visualizar Roteiro (V)
            else if (comando == "V" || comando == "v") {
                meuRoteiro.mostrarResumo();
            }

            // Limpar Roteiro (L)
            else if (comando == "L" || comando == "l") {
                meuRoteiro.esvaziarRoteiro();
            }

            // Gravar Reserva (G)
            else if (comando == "G" || comando == "g") {
                meuRoteiro.finalizarEGravar();
            }

            // Sair (0)
            else if (comando == "0") {
                std::cout << "A encerrar o programa... Boa viagem!\n";
            }
            else {
                std::cout << "Comando nao reconhecido. Tente novamente.\n";
            }
        }
        // ==========================================
        // CATCH: ZONA DE CAPTURA DE TODAS AS EXCEÇÕES
        // ==========================================
        catch (const InputInvalidoException& e) {
            std::cout << "\n[ERRO DE INPUT]: " << e.what() << std::endl;
        }
        catch (const IDInvalidoException& e) {
            std::cout << "\n[ERRO DE PESQUISA]: " << e.what() << std::endl;
        }
        catch (const RoteiroVazioException& e) {
            std::cout << "\n[AVISO]: " << e.what() << std::endl;
        }
        catch (const ErroFormatacaoFicheiroException& e) {
            std::cout << "\n[ERRO DE GRAVACAO]: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "\n[ERRO INESPERADO]: " << e.what() << std::endl;
        }
    }

    return 0;
}