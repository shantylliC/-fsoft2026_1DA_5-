#include <gtest/gtest.h>
#include "LocalidadeModel.h"

// Substituído o termo técnico anterior por TesteLocalidade
class TesteLocalidade : public LocalidadeModel {
public:
    // Construtores escritos por extenso
    TesteLocalidade() : LocalidadeModel() {}
    TesteLocalidade(int identificador, std::string nome) : LocalidadeModel(identificador, nome) {}

    // Implementação obrigatória da função virtual pura
    void carregarDeLinha(std::string linha) override {
        // Corpo vazio apenas para permitir a compilação do teste
    }
};

// ==================================================
// TESTES UNITÁRIOS PARA O MODELO DA LOCALIDADE
// ==================================================

TEST(TesteLocalidadeModelo, construtorPadrao) {
    // Arrange & Act: Instanciação do objeto com o nome por extenso
    TesteLocalidade localidadeInstanciada;

    // Assert: Verificação dos valores iniciais de fábrica
    EXPECT_EQ(localidadeInstanciada.obterID(), 0);
    EXPECT_EQ(localidadeInstanciada.obterNome(), "");
    EXPECT_DOUBLE_EQ(localidadeInstanciada.obterPreco(), 0.0);
}

TEST(TesteLocalidadeModelo, construtorParametrizado) {
    // Arrange: Definição das variáveis sem qualquer tipo de abreviação
    int identificadorEsperado = 10;
    std::string nomeEsperado = "Lisboa";

    // Act: Criação do objeto com os parâmetros definidos
    TesteLocalidade localidadeInstanciada(identificadorEsperado, nomeEsperado);

    // Assert: Validação dos dados retornados pelas funções do modelo
    EXPECT_EQ(localidadeInstanciada.obterID(), identificadorEsperado);
    EXPECT_EQ(localidadeInstanciada.obterNome(), nomeEsperado);
}

TEST(TesteLocalidadeModelo, obterPrecoBase) {
    // Arrange: Configuração do cenário de teste
    TesteLocalidade localidadeInstanciada(1, "Porto");

    // Act: Execução do comportamento que queremos analisar
    double precoRetornado = localidadeInstanciada.obterPreco();

    // Assert: Garantia de que o preço base permanece em zero vírgula zero
    EXPECT_DOUBLE_EQ(precoRetornado, 0.0);
}

TEST(TesteLocalidadeModelo, gerirAtividadesInternas) {
    TesteLocalidade localidadeInstanciada(1, "Porto");

    // Act: Adicionar atividades diretamente na instância do modelo
    localidadeInstanciada.adicionarAtividade("Visita às Caves do Vinho do Porto");
    localidadeInstanciada.adicionarAtividade("Cruzeiro das Seis Pontes");

    // Assert: Verificar se foram guardadas e listadas corretamente
    const auto& listaRetornada = localidadeInstanciada.obterAtividades();
    EXPECT_EQ(listaRetornada.size(), 2);
    EXPECT_EQ(listaRetornada.at(0), "Visita às Caves do Vinho do Porto");
}


