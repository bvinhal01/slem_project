// tests/test_local.c
#include "munit.h"
#include "../include/local.h"     // Inclui o header da struct Local e suas funções
#include "../include/utilitarios.h" // Inclui para calculaDistanciaEuclidiana e constantes
#include <string.h>
#include <stdio.h>
#include <stdlib.h> // Para malloc, free, se necessário


// Mock de variáveis globais para o contexto de teste
// Em um projeto real, as funções de CRUD deveriam receber esses arrays e contadores como parâmetros.
// Para este teste, criamos uma versão mock dessas variáveis.
static Local test_locais[MAX_ENTIDADES];
static int test_totalLocais;

// --- Mock de funções de I/O para testar funções que interagem com o usuário ---
// Como as funções de CRUD originais interagem com stdin/stdout, para testá-las diretamente
// precisaríamos de mocks ou refatoração. Para este exemplo, testaremos a lógica resultante.

// --- Funções de Setup e Teardown ---
// Setup: Executado ANTES de cada teste. Garante um estado limpo.
static void* test_setup(const MunitParameter params[], void* user_data) {
    test_totalLocais = 0; // Reseta a contagem de locais para cada teste
    // Opcional: inicializar 'test_locais' com memset, se structs complexas
    return (void*)1; // Retorna um valor arbitrário não-NULL
}

// Teardown: Executado DEPOIS de cada teste. Limpa recursos.
static void test_teardown(void* fixture) {
    // Não há alocações dinâmicas complexas neste exemplo que precisem de teardown.
}


// --- Casos de Teste para 'Local' e 'Utilitarios' ---

// Teste: buscarLocalPorNome - local não encontrado
static MunitResult test_buscar_local_nao_encontrado(const MunitParameter params[], void* data) {
    // Assume que test_totalLocais é 0 (setup)
    int indice = buscarLocalPorNome(test_locais, test_totalLocais, "Cidade Nao Existe");
    munit_assert_int(indice, ==, -1);
    return MUNIT_OK;
}

// Teste: buscarLocalPorNome - local encontrado
static MunitResult test_buscar_local_encontrado(const MunitParameter params[], void* data) {
    // Prepara um local manualmente para o teste
    strcpy(test_locais[0].nome, "Sao Paulo");
    test_locais[0].coordX = 1;
    test_locais[0].coordY = 2;
    test_totalLocais = 1;

    int indice = buscarLocalPorNome(test_locais, test_totalLocais, "Sao Paulo");
    munit_assert_int(indice, ==, 0); // Deve ser o primeiro elemento (índice 0)
    return MUNIT_OK;
}

// Teste: calculaDistanciaEuclidiana - pontos básicos
static MunitResult test_calcula_distancia_euclidiana_basico(const MunitParameter params[], void* data) {
    float dist = calculaDistanciaEuclidiana(0, 0, 3, 4);
    munit_assert_float(dist, ==, 5.0f, 0.0001f); // 0.0001f é a tolerância para floats
    return MUNIT_OK;
}

// Teste: calculaDistanciaEuclidiana - pontos negativos
static MunitResult test_calcula_distancia_euclidiana_negativos(const MunitParameter params[], void* data) {
    float dist = calculaDistanciaEuclidiana(-1, -1, 2, 3); // dx=3, dy=4
    munit_assert_float(dist, ==, 5.0f, 0.0001f);
    return MUNIT_OK;
}

// Teste: calculaDistanciaEuclidiana - mesmo ponto
static MunitResult test_calcula_distancia_euclidiana_mesmo_ponto(const MunitParameter params[], void* data) {
    float dist = calculaDistanciaEuclidiana(10, 20, 10, 20);
    munit_assert_float(dist, ==, 0.0f, 0.0001f);
    return MUNIT_OK;
}

// --- Array de Testes ---
static MunitTest local_tests[] = {
    { "/buscar-local-nao-encontrado", test_buscar_local_nao_encontrado, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/buscar-local-encontrado", test_buscar_local_encontrado, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/calcula-distancia-euclidiana-basico", test_calcula_distancia_euclidiana_basico, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/calcula-distancia-euclidiana-negativos", test_calcula_distancia_euclidiana_negativos, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { "/calcula-distancia-euclidiana-mesmo-ponto", test_calcula_distancia_euclidiana_mesmo_ponto, test_setup, test_teardown, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Marcador de fim de testes
};

// --- Configuração da Suite de Testes ---
static const MunitSuite test_suite = {
    "/slem-tests", // Nome da suite principal (poderia ser mais específico se houvessem sub-suites)
    local_tests,   // Array de testes (neste caso, apenas os testes de local/utilitarios)
    NULL,          // Array de sub-suites (nenhuma neste exemplo)
    1,             // Número de testes que serão executados em paralelo
    MUNIT_SUITE_OPTION_NONE
};

// --- Main do Teste ---
// Esta função é o ponto de entrada para o executável de teste.
// Ela chama o runner de testes do munit.
int main(int argc, char* argv[]) {
    // Para que o munit funcione, você precisa ter a biblioteca munit instalada e linkada.
    // Isso geralmente é feito via Makefile.
    printf("Rodando testes com munit...\n");
    return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}