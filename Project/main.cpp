#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <windows.h>

// 1. Módulo de Autenticação (Organizador + Viajantes)
#include "organizador/AutenticacaoController/AutenticacaoController.h"
#include "organizador/Pessoa/Pessoa.h"

// 2. Módulo de Validação de Datas
#include "Controller.h"
#include "data.h"

// 3. Módulo de Catálogo e Roteiro (Países, Cidades, Atividades)
#include "Manipulaçao da base de dados/Repositorio Catalogo/RepositorioCatalogo.h"
#include "Manipulaçao da base de dados/Roteiro/RoteiroController.h"
#include "Manipulaçao da base de dados/Exceçoes/Excecoes.h"

// 4. Módulo de Reserva e Pagamento Final
#include "reserva.h"

struct ItemSessao {
    int id;
    int dia;
    std::string hora;
};

int main() {
    // Configurar a consola do Windows para ler acentos portugueses corretamente
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // ====================================================
    // PASSO 1: LOGIN / REGISTO DO ORGANIZADOR + VIAJANTES
    // ====================================================
    AutenticacaoController fluxoLogin;
    Organizador* utilizadorLogado = fluxoLogin.executar();

    if (utilizadorLogado == nullptr) {
        std::cout << "\nA encerrar o programa com segurança...\n";
        return 0;
    }

    std::cout << "\n>>> Autenticação Efetuada com Sucesso! <<<\n";
    std::cout << "Operador Conectado: " << utilizadorLogado->obterNome() << "\n\n";

    // Instanciação dos objetos base da aplicação
    Data datasValidadas;
    Viagem viagemFinal;
    std::vector<ItemSessao> roteiroSessao; // Vetor para registar a árvore de escolhas do utilizador
    RepositorioCatalogo catalogo;
    try {
        catalogo.carregarTudo();
    }
    catch (const std::exception& e) {
        std::cout << "\n[ERRO DE CARREGAMENTO]: " << e.what() << std::endl;
        return 1;
    }
    RoteiroController meuRoteiro;
    bool viagemCarregadaSessao = false;

    // --- CARREGAMENTO AUTOMÁTICO DE SESSÃO POR UTILIZADOR ---
    std::string arquivoSessao = "sessao_viagem_" + utilizadorLogado->obterEmail() + ".txt";
    std::ifstream fsessao(arquivoSessao);

    if (fsessao.is_open()) {

        std::cout << "Encontrámos um plano de viagem guardado associado a esta conta.\n";
        std::cout << "1 - Carregar viagem guardada e ir para o Menu de Gestão\n";
        std::cout << "2 - Eliminar registo antigo e criar uma viagem do zero\n";
        std::cout << "Escolha uma opção: ";
        int opCarregar = 0;

        if (std::cin >> opCarregar) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (opCarregar == 1) {
    int cd, cm, ca, sd, sm, sa;
    fsessao >> cd >> cm >> ca;
    fsessao >> sd >> sm >> sa;
    fsessao.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string tituloG, notasG;
    std::getline(fsessao, tituloG);
    std::getline(fsessao, notasG);

    int metodoId;
    fsessao >> metodoId;

    // LER OS DADOS ESTRUTURADOS DO FICHEIRO (ID, Dia e Hora)
    size_t totalIds;
    fsessao >> totalIds;
    for (size_t i = 0; i < totalIds; ++i) {
        int idTmp, diaTmp;
        std::string horaTmp;
        fsessao >> idTmp >> diaTmp >> horaTmp;
        roteiroSessao.push_back({idTmp, diaTmp, horaTmp});
    }

    // Criar o objeto de data completo e sincronizar com a Viagem
    Data periodoCarregado(cd, cm, ca, sd, sm, sa);
    datasValidadas = periodoCarregado;
    viagemFinal.definirDataViagem(periodoCarregado);

    if (!tituloG.empty() && tituloG != "Sem Titulo") viagemFinal.setTitulo(tituloG);
    if (!notasG.empty() && notasG != "Sem Notas") viagemFinal.setNotasViagem(notasG);

    if (metodoId == 0) Financeiro::definirMetodo(MetodoPagamento::DINHEIRO);
    else if (metodoId == 1) Financeiro::definirMetodo(MetodoPagamento::CARTAO);
    else if (metodoId == 2) Financeiro::definirMetodo(MetodoPagamento::TRANSFERENCIA);

    // RECONSTRUIR O ROTEIRO SILENCIOSAMENTE NA MEMÓRIA (Sem perguntas na consola)
    for (const auto& item : roteiroSessao) {
        LocalidadeModel* selecionado = nullptr;
        for (auto* p : catalogo.obterPaises()) { if (p->obterID() == item.id) { selecionado = p; break; } }
        if (!selecionado) { for (auto* c : catalogo.obterCidades()) { if (c->obterID() == item.id) { selecionado = c; break; } } }
        if (!selecionado) { for (auto* a : catalogo.obterAtividades()) { if (a->obterID() == item.id) { selecionado = a; break; } } }

        if (selecionado != nullptr) {
            meuRoteiro.carregarEscolhaSessao(selecionado, item.dia, item.hora);
        }
    }

    // RESOLUÇÃO DO PREÇO SUMIDO: Recalcular o custo total com base no roteiro lido
    double custoTotalViagem = meuRoteiro.obterPrecoFinalComIVA();
    viagemFinal.carregarDadosDoCatalogo(custoTotalViagem);

    viagemCarregadaSessao = true;
    std::cout << "\n-> Plano de viagem restabelecido com sucesso!\n";
} else {
                fsessao.close();
                std::remove(arquivoSessao.c_str()); // Apaga o ficheiro físico do utilizador
                std::cout << "\nPlano anterior descartado. A iniciar do zero...\n";
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (fsessao.is_open()) fsessao.close();
    }

    // ====================================================
    // PASSO 2: SELECIONAR E VALIDAR DATAS DA VIAGEM
    // ====================================================
    if (!viagemCarregadaSessao) {

        Controller controladorDatas;
        datasValidadas = controladorDatas.obterDataValidada();
    }

    // ====================================================
    // PASSO 3: SELECIONAR PAÍSES, CIDADES E ATIVIDADES
    // ====================================================

    meuRoteiro.definirDatas(datasValidadas);

    std::string comandoRoteiro = "";
    bool passo3Concluido = viagemCarregadaSessao; // Salta o menu interativo se já carregou
    int paisSelecionadoId = -1;
    int cidadeSelecionadaId = -1;

    while (!passo3Concluido) {
        try {
            if (paisSelecionadoId == -1) {
                std::cout << "\n--- SELECIONE UM PAÍS DO CATÁLOGO ---\n";
                for (auto* p : catalogo.obterPaises()) {
                    std::cout << "[" << p->obterID() << "] - " << p->obterNome() << "\n";
                }
                std::cout << "--------------------------------------\n";
                std::cout << "Comandos: 'V' (Ver) | 'L' (Limpar) | 'P' (Definir Pagamento) | 'G' (Gravar e Avançar)\n";
                std::cout << "Introduza o ID do País desejado: ";
            }
            else if (cidadeSelecionadaId == -1) {
                std::cout << "\n--- CIDADES DISPONÍVEIS NESTE PAÍS ---\n";
                for (auto* c : catalogo.obterCidades()) {
                    if (c->obterIdPais() == paisSelecionadoId) {
                        std::cout << "[" << c->obterID() << "] - " << c->obterNome() << " (Custo Base: " << c->obterPreco() << " EUR)\n";
                    }
                }
                std::cout << "--------------------------------------\n";
                std::cout << "Comandos: 'B' (Voltar) | 'V' (Ver) | 'L' (Limpar) | 'P' (Pagamento) | 'G' (Gravar)\n";
                std::cout << "Introduza o ID da Cidade para adicionar ao roteiro: ";
            }
            else {
                std::cout << "\n--- ATIVIDADES DISPONÍVEIS NESTA CIDADE ---\n";
                bool encontrouAtividades = false;
                for (auto* a : catalogo.obterAtividades()) {
                    if (a->obterIdCidade() == cidadeSelecionadaId) {
                        std::cout << "[" << a->obterID() << "] - " << a->obterNome() << " (Bilhete: " << a->obterPreco() << " EUR)\n";
                        encontrouAtividades = true;
                    }
                }
                if (!encontrouAtividades) std::cout << "(Não existem atividades registadas para esta cidade)\n";
                std::cout << "--------------------------------------\n";
                std::cout << "Comandos: 'B' (Voltar) | 'V' (Ver) | 'L' (Limpar) | 'P' (Pagamento) | 'G' (Gravar)\n";
                std::cout << "Introduza o ID da Atividade para a adicionar ao roteiro: ";
            }

            std::getline(std::cin, comandoRoteiro);
            if (comandoRoteiro.empty()) continue;

            if (comandoRoteiro == "G" || comandoRoteiro == "g") {
                if (Financeiro::obterMetodoSelecionado() == MetodoPagamento::NAO_DEFINIDO) {
                    std::cout << "\n[REQUISITO] É obrigatório definir o método de pagamento primeiro:\n";
                    meuRoteiro.alterarMetodoPagamento();
                }
                meuRoteiro.finalizarEGravar();
                passo3Concluido = true;
            }
            else if (comandoRoteiro == "V" || comandoRoteiro == "v") {
                meuRoteiro.mostrarResumo();
            }
            else if (comandoRoteiro == "P" || comandoRoteiro == "p") {
                meuRoteiro.alterarMetodoPagamento();
            }
            else if (comandoRoteiro == "L" || comandoRoteiro == "l") {
                meuRoteiro.esvaziarRoteiro();
                roteiroSessao.clear(); // Limpa o histórico de cache de IDs
                paisSelecionadoId = -1;
                cidadeSelecionadaId = -1;
            }
            else if (comandoRoteiro == "B" || comandoRoteiro == "b") {
                if (cidadeSelecionadaId != -1) cidadeSelecionadaId = -1;
                else if (paisSelecionadoId != -1) paisSelecionadoId = -1;
            }
            else {
                try {
                    int idEscolhido = std::stoi(comandoRoteiro);

                    if (paisSelecionadoId == -1) {
                        bool valido = false;
                        for (auto* p : catalogo.obterPaises()) {
                            if (p->obterID() == idEscolhido) { paisSelecionadoId = idEscolhido; valido = true; break; }
                        }
                        if (!valido) std::cout << "ID de País inválido.\n";
                    }
                    else if (cidadeSelecionadaId == -1) {
                        bool valido = false;
                        for (auto* c : catalogo.obterCidades()) {
                            if (c->obterID() == idEscolhido && c->obterIdPais() == paisSelecionadoId) {
                                cidadeSelecionadaId = idEscolhido;
                                meuRoteiro.registarEscolha(c);
                                roteiroSessao.push_back({idEscolhido, 0, "00:00"}); // Grava o ID, com dia 0 e hora padrão
                                valido = true;
                                break;
                            }
                        }
                        if (!valido) std::cout << "ID de Cidade inválido para este país.\n";
                    }
                    else {
                        bool valido = false;
                        for (auto* a : catalogo.obterAtividades()) {
                            if (a->obterID() == idEscolhido && a->obterIdCidade() == cidadeSelecionadaId) {
                                meuRoteiro.registarEscolha(a);
                                roteiroSessao.push_back({idEscolhido, a->obterDiaAgendado(), a->obterHoraAgendada()});
                                valido = true;
                                break;
                            }
                        }
                        if (!valido) std::cout << "ID de Atividade inválido para esta cidade.\n";
                    }
                }
                catch (const std::invalid_argument&) {
                    std::cout << "Entrada inválida. Use IDs numéricos ou os comandos (B, V, L, P, G).\n";
                }
            }
        }
        catch (const std::exception& e) {
            std::cout << "\n[Aviso Roteiro]: " << e.what() << std::endl;
        }
    }

// ====================================================
    // PASSO 4: GESTÃO FINANCEIRA E RESERVA FINAL
    // ====================================================

    // Nota: Garante que a linha abaixo existe logo antes do "if"

    if (!viagemCarregadaSessao) {

        viagemFinal.definirDataViagem(datasValidadas);
        double custoTotalViagem = meuRoteiro.obterPrecoFinalComIVA();
        viagemFinal.carregarDadosDoCatalogo(custoTotalViagem);
    }
    bool terminarPrograma = false;

    while (!terminarPrograma) {
        int opcaoReserva;

    std::cout << "\n--- MENU FINAL DE RESERVA & PAGAMENTO ---\n";
    std::cout << "1. Visualizar Ficha Completa da Viagem\n";
    std::cout << "2. Modificar Título da Viagem\n";
    std::cout << "3. Modificar Notas Auxiliares\n";
    std::cout << "4. Ajustar Custo Total Manualmente\n";
    std::cout << "5. Configurar Método de Pagamento / Pagar\n";
    std::cout << "6. Reajustar Datas de Reserva\n";
    std::cout << "7. Exibir Identificador Único da Reserva\n";
    std::cout << "0. Confirmar, Gravar e Sair do Sistema\n";
    std::cout << "-----------------------------------------\n";
    std::cout << "Opção: ";

    if (!(std::cin >> opcaoReserva)) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Opção Inválida!\n";
        continue;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (opcaoReserva) {

        case 1: viagemFinal.print();                break;
        case 2: {
            std::cout << ">> Novo Título:\n";
            while (!viagemFinal.mudarTitulo());
            break;
        }
        case 3: {
            std::cout << ">> Novas Notas:\n";
            while (!viagemFinal.mudarNotasViagem())
            break;
        }
        case 4: viagemFinal.mudarCustoTotal();       break;
        case 5:
            viagemFinal.mudarMetodoPagamento();
            break;
        case 6: viagemFinal.mudarData();             break;
        case 7: viagemFinal.mostrarNumeroReserva();  break;
        case 0: {
            viagemFinal.estadoConfirmar();
            viagemFinal.gravarFicheiro();
            std::ofstream fsalvar(arquivoSessao);
            if (fsalvar.is_open()) {

                fsalvar << datasValidadas.getChegada().dia << " " << datasValidadas.getChegada().mes << " " << datasValidadas.getChegada().ano << "\n";
                fsalvar << datasValidadas.getSaida().dia << " " << datasValidadas.getSaida().mes << " " << datasValidadas.getSaida().ano << "\n";

                fsalvar << (viagemFinal.getTitulo().empty() ? "Sem Titulo" : viagemFinal.getTitulo()) << "\n";
                fsalvar << (viagemFinal.getNotasViagem().empty() ? "Sem Notas" : viagemFinal.getNotasViagem()) << "\n";

                fsalvar << static_cast<int>(Financeiro::obterMetodoSelecionado()) << "\n";

                // 4. Gravar a quantidade e os dados estruturados do roteiro (ID, Dia e Hora)
                fsalvar << roteiroSessao.size() << "\n";
                for (const auto& item : roteiroSessao) {
                    fsalvar << item.id << " " << item.dia << " " << item.hora << "\n";
                }
                fsalvar.close();
            }

            terminarPrograma = true;

            std::cout << "\nReserva processada com sucesso. Ficheiros atualizados! Boa viagem!\n";
            break;
        }

        default:
            std::cout << "Opção inválida.\n";
    }
}
return 0;

}