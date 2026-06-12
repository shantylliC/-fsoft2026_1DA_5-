cmake_minimum_required(VERSION 3.28)
project(fsoft2026_1DA_5)
set(CMAKE_CXX_STANDARD 17)

add_executable(fsoft2026_1DA_5
        organizador/main.cpp
        Datas/data.cpp
        Datas/View.cpp
        Datas/Controller.cpp
        organizador/AutenticacaoController/AutenticacaoController.cpp
        organizador/AutenticacaoService/AutenticacaoService.cpp
        organizador/Login/Login.cpp
        organizador/LoginRepository/LoginRepository.cpp
        organizador/LoginView/LoginView.cpp
        organizador/Pessoa/Pessoa.cpp
)