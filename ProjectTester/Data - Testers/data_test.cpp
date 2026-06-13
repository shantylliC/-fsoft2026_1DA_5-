#include "gtest/gtest.h"
#include "data.h"


TEST(DataConstructorTest, DatasValidas) {
    bool flag = false;
    try {
        Data d(1, 6, 2024, 10, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(DataConstructorTest, MesInvalido) {
    bool flag = false;
    try {
        Data d(1, 13, 2024, 10, 14, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataConstructorTest, DiaInvalido) {
    bool flag = false;
    try {
        Data d(32, 6, 2024, 33, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataConstructorTest, AnoAnteriorA2024) {
    bool flag = false;
    try {
        Data d(1, 6, 2023, 10, 6, 2023);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataConstructorTest, SaidaAntesDeChegada) {
    bool flag = false;
    try {
        Data d(10, 6, 2024, 1, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataConstructorTest, MesmoDia) {
    bool flag = false;
    try {
        Data d(5, 6, 2024, 5, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(DataConstructorTest, FevereiroBissextoValido) {
    bool flag = false;
    try {
        Data d(29, 2, 2024, 1, 3, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(DataConstructorTest, FevereiroNaoBissextoInvalido) {
    bool flag = false;
    try {
        Data d(29, 2, 2025, 1, 3, 2025);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataConstructorTest, Dia31EmMesComSo30Dias) {
    bool flag = false;
    try {
        Data d(31, 4, 2024, 31, 5, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataNumeroDiasTest, MesmoDiaZeroDias) {
    Data d(5, 6, 2024, 5, 6, 2024);
    int dias = d.getNumeroDias();
    EXPECT_EQ(dias, 0);
}

TEST(DataNumeroDiasTest, UmaSemana) {
    Data d(1, 6, 2024, 8, 6, 2024);
    int dias = d.getNumeroDias();
    EXPECT_EQ(dias, 7);
}

TEST(DataNumeroDiasTest, PassagemDeMes) {
    Data d(28, 6, 2024, 2, 7, 2024);
    int dias = d.getNumeroDias();
    EXPECT_EQ(dias, 4);
}

TEST(DataSetChegadaTest, DataValida) {
    Data d(1, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setChegada(2, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(DataSetChegadaTest, DataInvalida) {
    Data d(1, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setChegada(32, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataSetChegadaTest, ChegadaDepoisDaSaida) {
    Data d(1, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setChegada(15, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataSetSaidaTest, DataValida) {
    Data d(1, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setSaida(15, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_FALSE(flag);
}

TEST(DataSetSaidaTest, DataInvalida) {
    Data d(1, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setSaida(0, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataSetSaidaTest, SaidaAntesDeChegada) {
    Data d(5, 6, 2024, 10, 6, 2024);
    bool flag = false;
    try {
        d.setSaida(1, 6, 2024);
    } catch (DataInvalidaException& e) {
        flag = true;
    }
    EXPECT_TRUE(flag);
}

TEST(DataHorariosTest, AdicionarUmHorario) {
    Data d(1, 6, 2024, 10, 6, 2024);
    d.addHorario("09:00 - Visita ao museu");
    EXPECT_EQ(d.getHorarios().size(), 1);
}

TEST(DataHorariosTest, AdicionarVariosHorarios) {
    Data d(1, 6, 2024, 10, 6, 2024);
    d.addHorario("09:00 - Pequeno almoco");
    d.addHorario("11:00 - Visita ao museu");
    d.addHorario("14:00 - Almoco");
    EXPECT_EQ(d.getHorarios().size(), 3);
}

TEST(DataHorariosTest, SemHorarios) {
    Data d(1, 6, 2024, 10, 6, 2024);
    EXPECT_TRUE(d.getHorarios().empty());
}