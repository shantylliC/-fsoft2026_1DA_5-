cmake_minimum_required(VERSION 4.1)
project(_fsoft2026_1DA_5_)

# Forçar C++17 para suportar o polimorfismo moderno e as exceções do catálogo
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        .
        Datas
        "organizador/Pessoa"
        "organizador/Login"
        "organizador/LoginView"
        "organizador/LoginRepository"
        "organizador/AutenticacaoService"
        "organizador/AutenticacaoController"
        "Manipulaçao da base de dados/Localidade"
        "Manipulaçao da base de dados/Pais"
        "Manipulaçao da base de dados/Cidade"
        "Manipulaçao da base de dados/Atividade"
        "Manipulaçao da base de dados/Repositorio Catalogo"
        "Manipulaçao da base de dados/Roteiro"
        "Manipulaçao da base de dados/Financeiro"
        "Manipulaçao da base de dados/Exceçoes"
)

add_executable(_fsoft2026_1DA_5_
        # Fluxo Principal e Datas
        main.cpp
        Datas/data.cpp
        Datas/data.h
        Datas/Controller.cpp
        Datas/Controller.h
        Datas/View.cpp
        Datas/View.h

        # Módulo Reserva e Pagamentos
        reserva.cpp
        reserva.h
        pagamento.h
        pagamento.cpp

        # Sub-módulos da Reserva (MVCs organizados em pastas)
        numero_de_reserva/Controlador/n_reserva_controlador.h
        numero_de_reserva/Modelo/n_reserva_modelo.h
        numero_de_reserva/View/n_reserva_view.h
        numero_de_reserva/Controlador/n_reserva_controlador.cpp
        numero_de_reserva/Modelo/n_reserva_modelo.cpp
        numero_de_reserva/View/n_reserva_view.cpp

        titulo_notas/Controlador/titulo_notas_controlador.h
        titulo_notas/Modelo/titulo_notas_modelo.h
        titulo_notas/View/titulo_notas_view.h
        titulo_notas/Controlador/titulo_notas_controlador.cpp
        titulo_notas/Modelo/titulo_notas_modelo.cpp
        titulo_notas/View/titulo_notas_view.cpp

        alt_estados/Controlador/alt_estados_controller.h
        alt_estados/Modelo/alt_estados_modelo.h
        alt_estados/View/alt_estados_view.h
        alt_estados/Controlador/alt_estados_controller.cpp
        alt_estados/Modelo/alt_estados_modelo.cpp
        alt_estados/View/alt_estados_view.cpp

        # Módulo Autenticação (Login e Utilizadores)
        organizador/Pessoa/Pessoa.cpp
        organizador/Pessoa/Pessoa.h
        organizador/Login/Login.cpp
        organizador/Login/Login.h
        organizador/LoginView/LoginView.cpp
        organizador/LoginView/LoginView.h
        organizador/LoginRepository/LoginRepository.cpp
        organizador/LoginRepository/LoginRepository.h
        organizador/AutenticacaoService/AutenticacaoService.cpp
        organizador/AutenticacaoService/AutenticacaoService.h
        organizador/AutenticacaoController/AutenticacaoController.cpp
        organizador/AutenticacaoController/AutenticacaoController.h

        # Módulo Catálogo Geográfico e Roteiro (MVC + Polimorfismo)
        "Manipulaçao da base de dados/Localidade/LocalidadeModel.cpp"
        "Manipulaçao da base de dados/Localidade/LocalidadeModel.h"
        "Manipulaçao da base de dados/Localidade/LocalidadeView.cpp"
        "Manipulaçao da base de dados/Localidade/LocalidadeView.h"
        "Manipulaçao da base de dados/Localidade/LocalidadeController.cpp"
        "Manipulaçao da base de dados/Localidade/LocalidadeController.h"
        "Manipulaçao da base de dados/Pais/PaisModel.cpp"
        "Manipulaçao da base de dados/Pais/PaisModel.h"
        "Manipulaçao da base de dados/Cidade/CidadeModel.cpp"
        "Manipulaçao da base de dados/Cidade/CidadeModel.h"
        "Manipulaçao da base de dados/Atividade/AtividadeModel.cpp"
        "Manipulaçao da base de dados/Atividade/AtividadeModel.h"
        "Manipulaçao da base de dados/Repositorio Catalogo/RepositorioCatalogo.cpp"
        "Manipulaçao da base de dados/Repositorio Catalogo/RepositorioCatalogo.h"
        "Manipulaçao da base de dados/Roteiro/RoteiroModel.cpp"
        "Manipulaçao da base de dados/Roteiro/RoteiroModel.h"
        "Manipulaçao da base de dados/Roteiro/RoteiroView.cpp"
        "Manipulaçao da base de dados/Roteiro/RoteiroView.h"
        "Manipulaçao da base de dados/Roteiro/RoteiroController.cpp"
        "Manipulaçao da base de dados/Roteiro/RoteiroController.h"
        "Manipulaçao da base de dados/Financeiro/Financeiro.cpp"
        "Manipulaçao da base de dados/Financeiro/Financeiro.h"
        "Manipulaçao da base de dados/Exceçoes/Excecoes.h"
)
# =====================================================================
# COPIAR AS BASES DE DADOS AUTOMATICAMENTE PARA A PASTA DE EXECUÇÃO
# =====================================================================

# Copiar os ficheiros a partir da localização real detetada pelo sistema
configure_file("Manipulaçao da base de dados/Base de dados/BaseDados-paises.txt" "BaseDados-paises.txt" COPYONLY)
configure_file("Manipulaçao da base de dados/Base de dados/BaseDados-cidades.txt" "BaseDados-cidades.txt" COPYONLY)
configure_file("Manipulaçao da base de dados/Base de dados/BaseDados-atividades.txt" "BaseDados-atividades.txt" COPYONLY)

# Copiar também as credenciais de login que estão na raiz
configure_file("dados_login.txt" "dados_login.txt" COPYONLY)