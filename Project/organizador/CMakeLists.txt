cmake_minimum_required(VERSION 3.20)
project(organizador)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(organizador
        main.cpp
        Pessoa/Pessoa.cpp
        Login/Login.cpp
        LoginRepository/LoginRepository.cpp
        AutenticacaoService/AutenticacaoService.cpp
        AutenticacaoController/AutenticacaoController.cpp
        LoginView/LoginView.cpp)

target_include_directories(organizador PRIVATE headers)

configure_file(dados_login.txt dados_login.txt COPYONLY)
