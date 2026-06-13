cmake_minimum_required(VERSION 3.28)
project(ProjetoViagens)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "../Localidade"
        "../Pais"
        "../Cidade"
        "../Atividade"
        "../Repositorio Catalogo"
        "../Roteiro"
        "../Financeiro"
        "../Exceçoes"
        "../../Datas"
)
#adicionar os ficheiros .cpp:
add_executable(ProjetoViagens
        Main.cpp
        "../Localidade/LocalidadeModel.cpp"
        "../Localidade/LocalidadeModel.h"
        "../Localidade/LocalidadeView.cpp"
        "../Localidade/LocalidadeView.h"
        "../Localidade/LocalidadeController.cpp"
        "../Localidade/LocalidadeController.h"
        "../Pais/PaisModel.cpp"
        "../Pais/PaisModel.h"
        "../Cidade/CidadeModel.cpp"
        "../Cidade/CidadeModel.h"
        "../Atividade/AtividadeModel.cpp"
        "../Atividade/AtividadeModel.h"
        "../Repositorio Catalogo/RepositorioCatalogo.cpp"
        "../Repositorio Catalogo/RepositorioCatalogo.h"
        "../Roteiro/RoteiroModel.cpp"
        "../Roteiro/RoteiroModel.h"
        "../Roteiro/RoteiroView.cpp"
        "../Roteiro/RoteiroView.h"
        "../Roteiro/RoteiroController.cpp"
        "../Roteiro/RoteiroController.h"
        "../Financeiro/Financeiro.cpp"
        "../Financeiro/Financeiro.h"
        "../Exceçoes/Excecoes.h"
        #datas
        "../../Datas/Controller.cpp"
        "../../Datas/Controller.h"
        "../../Datas/View.cpp"
        "../../Datas/View.h"
        "../../Datas/data.cpp"
        "../../Datas/data.h"
)