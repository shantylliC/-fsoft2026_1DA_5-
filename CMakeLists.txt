cmake_minimum_required(VERSION 3.28)
project(ProjetoViagens)

set(CMAKE_CXX_STANDARD 17)

#adicionar os fichieros .cpp:
add_executable(ProjetoViagens
        Project/Data.cpp
        Project/Data.h
        Main.cpp
        Project/Localidade.cpp
        Project/Localidade.h
        Project/Pais.cpp
        Project/Pais.h
        Project/Cidade.cpp
        Project/Cidade.h
        Project/Atividade.cpp
        Project/Atividade.h
        Project/Financeiro.cpp
        Project/Financeiro.h
        Project/Repositorio.cpp
        Project/Repositorio.h
        Project/Roteiro.cpp
        Project/Roteiro.h


)