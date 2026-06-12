#include "AutenticacaoController.h"

void AutenticacaoController::copiarDadosPessoa(Pessoa& destino, const Pessoa& origem, bool copiarEmail) {
    destino.colocarNome(origem.obterNome());
    destino.colocarIdade(origem.obterIdade());
    destino.colocarBI(origem.obterBI());
    destino.colocarValidade(origem.obterValidade());

    if (copiarEmail) {
        destino.colocarEmail(origem.obterEmail());
    }
}

bool AutenticacaoController::gerirRegisto(std::string email, std::string password) {
    while (servico.emailExiste(email)) {
        vista.mostrarMensagem("Este email ja esta a ser utilizado!");
        email = vista.pedirEmailRegisto();
    }

    if (password.empty()) {
        password = vista.pedirPasswordRegisto();
    }

    modelo = Login();
    modelo.colocarEmail(email);
    modelo.colocarPassword(password);

    Pessoa dadosOrganizador;
    vista.preencherDadosPessoa(dadosOrganizador, "Dados Organizador");

    Organizador& organizador = modelo.obterOrganizador();
    copiarDadosPessoa(organizador, dadosOrganizador, false);
    organizador.colocarEmail(email);

    if (!servico.organizadorTemIdadeMinima(organizador)) {
        vista.mostrarMensagem("Nao tem idade suficiente para ser organizador!");
        return false;
    }

    return criarNovaViagem();
}

bool AutenticacaoController::criarNovaViagem() {
    modelo.obterOrganizador().limparViajantes();

    const int numeroViajantes = vista.pedirNumeroViajantes();
    for (int i = 0; i < numeroViajantes; ++i) {
        Viajante viajante;
        vista.preencherDadosPessoa(viajante, "Viajante " + std::to_string(i + 1), true);
        modelo.obterOrganizador().adicionarViajante(viajante);
    }

    return reverEConfirmarDados();
}

bool AutenticacaoController::reverEConfirmarDados() {
    while (true) {
        Organizador& organizador = modelo.obterOrganizador();
        vista.mostrarDadosTodos(organizador);

        if (vista.confirmarDados()) {
            return true;
        }

        const int correcao = vista.escolherQuemAlterar(static_cast<int>(organizador.obterNumeroViajantes()));
        if (correcao == 0) {
            Pessoa dadosOrganizador;
            vista.preencherDadosPessoa(dadosOrganizador, "Organizador");
            copiarDadosPessoa(organizador, dadosOrganizador, false);

            if (!servico.organizadorTemIdadeMinima(organizador)) {
                vista.mostrarMensagem("Nao tem idade suficiente para ser organizador!");
                return false;
            }
        } else if (correcao >= 1 && correcao <= static_cast<int>(organizador.obterNumeroViajantes())) {
            Viajante viajante;
            vista.preencherDadosPessoa(viajante, "Viajante " + std::to_string(correcao), true);
            organizador.substituirViajante(static_cast<std::size_t>(correcao - 1), viajante);
        } else {
            vista.mostrarMensagem("Opcao invalida!");
        }
    }
}

Organizador* AutenticacaoController::executar() {
    while (true) {
        const int opcao = vista.mostrarMenuInicial();
        if (opcao == 3) {
            return nullptr;
        }

        if (opcao == 1) {
            vista.mostrarCabecalhoRegisto();
            const std::string email = vista.pedirEmailRegisto();
            const std::string password = vista.pedirPasswordRegisto();

            if (!gerirRegisto(email, password)) {
                return nullptr;
            }

            if (!servico.guardar(modelo)) {
                vista.mostrarMensagem("Nao foi possivel guardar os dados.");
                return nullptr;
            }

            vista.mostrarMensagem("\nConta criada com sucesso!");
            return &modelo.obterOrganizador();
        }

        if (opcao == 2) {
            std::string email;
            std::string password;
            vista.pedirDadosLogin(email, password);

            while (true) {
                if (servico.autenticar(email, password, modelo)) {
                    vista.mostrarMensagem("Login efetuado com sucesso!\n");

                    if (vista.perguntarVerDados() == 1 && !reverEConfirmarDados()) {
                        return nullptr;
                    }

                    while (true) {
                        const int novaViagem = vista.perguntarCriarNovaViagem();
                        if (novaViagem == 1) {
                            if (!criarNovaViagem()) {
                                return nullptr;
                            }
                        } else if (novaViagem == 0) {
                            break;
                        } else {
                            vista.mostrarMensagem("Opcao invalida!");
                        }
                    }

                    if (!servico.guardar(modelo)) {
                        vista.mostrarMensagem("Nao foi possivel guardar os dados.");
                        return nullptr;
                    }

                    vista.mostrarMensagem("\nOs dados foram todos guardados com sucesso!");
                    return &modelo.obterOrganizador();
                }

                const int escolha = vista.mostrarMenuFalhaLogin();
                if (escolha == 1) {
                    vista.pedirDadosLogin(email, password);
                } else if (escolha == 2) {
                    vista.mostrarCabecalhoRegisto();
                    email = vista.pedirEmailRegisto();
                    password = vista.pedirPasswordRegisto();

                    if (!gerirRegisto(email, password)) {
                        return nullptr;
                    }

                    if (!servico.guardar(modelo)) {
                        vista.mostrarMensagem("Nao foi possivel guardar os dados.");
                        return nullptr;
                    }

                    vista.mostrarMensagem("\nConta criada com sucesso!");
                    return &modelo.obterOrganizador();
                } else if (escolha == 3) {
                    return nullptr;
                } else {
                    vista.mostrarMensagem("Opcao invalida!");
                }
            }
        }

        vista.mostrarMensagem("Opcao invalida!");
    }
}
