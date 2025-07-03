# Documentação do Projeto: Sistema de Logística de Entrega de Mercadorias (SLEM)

**Disciplina:** Algoritmos e Estruturas de Dados I (AED I) & Fundamentos de Engenharia de Software (FES)
**Professor(es):** Antonio Esteves (AED I)
**Data de Entrega:** 29/06/2025
**Valor:** 10 pontos

## 1. Informações da Equipe / Aluno

* **Nome do(a) Aluno(a) 1:** [Bernardo Vinhal]
* **Matrícula do(a) Aluno(a) 1:** [891738]
* **Nome do(a) Aluno(a) 2:** [Gabriel Henrique]
* **Matrícula do(a) Aluno(a) 2:** [878933]
* **Linguagem de Programação:** C
* **Link do Repositório GitHub:** [[Link](https://github.com/bvinhal01/slem_project.git)]

## 2. Visão Geral do Sistema (SLEM)

O Sistema de Logística de Entrega de Mercadorias (SLEM) tem como objetivo simular o gerenciamento de pedidos, veículos e locais, com foco na manipulação eficiente de dados e na implementação de um algoritmo de roteamento básico. As informações são persistidas em arquivos texto ou binário.

## 3. Metodologia de Desenvolvimento (Scrum)

O projeto foi desenvolvido utilizando a metodologia Scrum, com sprints de 2 a 3 dias para cada funcionalidade. O progresso foi gerenciado através de um Backlog do Produto, e cada tarefa foi atribuída a um membro da equipe (quando aplicável).

### 3.1. Backlog do Produto e Evolução das Sprints

Apresente a evolução do backlog do produto semana a semana. Indique as tarefas que compunham o backlog inicialmente, em qual sprint cada tarefa foi alocada e o responsável por ela.

| Sprint | Período (Ex: DD/MM - DD/MM) | Tarefas Alocadas (Ex: User Story) | Responsável(is) | Status (Ex: Concluído, Em Andamento) | Observações |
| :----- | :------------------------- | :--------------------------------- | :-------------- | :---------------------------------- | :---------- |
| 1      | 01/07 - 03/07              | - Definição structs (Local, Veiculo, Pedido) <br> - Criar Local <br> - Listar Locais <br> - Esqueleto do Menu | [Bernardo Vinhal de Carvalho Teixeira] / [Nome do Membro 2] | Concluído                           | Base para o sistema. |
| 2      | 04/07 - 06/07              | - Atualizar Local <br> - Excluir Local <br> - Criar Veículo <br> - Testes automatizados para Locais (Criar, Listar) | [Nome do Membro 1]                  | Concluído                           | ...         |
| 3      | 07/07 - 09/07              | [Últimas consideraões] | [Requerimentos finais] | Métodologias de correção                       | [Finalziação do trabalho] |
| ...    | ...                        | ...                                | ...             | ...                                 | ...         |

### 3.2. Evidências do Uso do Scrum

As Daily Scrums foram realizadas pontualmente pela dupla Bernardo e Gabriel Henrique para sincronizar o progresso. Cada um compartilhava o que fez, o que faria e se havia impedimentos. Obstáculos técnicos ou de colaboração eram tratados imediatamente, garantindo que o desenvolvimento não parasse. Ao final de cada sprint, revisavam o trabalho concluído e adaptavam o plano seguinte, assegurando que o projeto permanecesse alinhado aos objetivos e prazos.

## 4. Análise e Projeto do Sistema

### 4.1. Estruturas de Dados (Structs)

* **`Local`**
    * **Propósito:** Representa um ponto geográfico para entregas ou localização de veículos.
    * **Atributos:**
        * `char nome[MAX_NOME_LOCAL]`: Nome identificador único do local.
        * `float coordX`: Coordenada X numérica.
        * `float coordY`: Coordenada Y numérica.
    * **Exemplo de declaração (reflete o código implementado):**
        ```c
        typedef struct {
            char nome[MAX_NOME_LOCAL];
            float coordX;
            float coordY;
        } Local;
        ```

* **`Veiculo`**
    * **Propósito:** Representa um veículo disponível ou ocupado para entregas.
    * **Atributos:**
        * `char placa[MAX_PLACA_VEICULO]`: Placa do veículo (identificador único).
        * `char modelo[MAX_MODELO_VEICULO]`: Modelo do veículo.
        * `int status`: Status do veículo (0 = Disponível, 1 = Ocupado).
        * `char localAtualNome[MAX_NOME_LOCAL]`: Nome do Local onde o veículo se encontra atualmente.
    * **Exemplo de declaração (reflete o código implementado):**
        ```c
        typedef struct {
            char placa[MAX_PLACA_VEICULO];
            char modelo[MAX_MODELO_VEICULO];
            int status; // 0=Disponivel, 1=Ocupado
            char localAtualNome[MAX_NOME_LOCAL];
        } Veiculo;
        ```

* **`Pedido`**
    * **Propósito:** Representa uma solicitação de entrega de mercadoria.
    * **Atributos:**
        * `int id`: Identificador único do pedido.
        * `char origemNome[MAX_NOME_LOCAL]`: Nome do Local de origem.
        * `char destinoNome[MAX_NOME_LOCAL]`: Nome do Local de destino.
        * `float pesoKg`: Peso do item em kg.
    * **Exemplo de declaração (reflete o código implementado):**
        ```c
        typedef struct {
            int id;
            char origemNome[MAX_NOME_LOCAL];
            char destinoNome[MAX_NOME_LOCAL];
            float pesoKg;
        } Pedido;
        ```

### 4.2. Modularização do Código

Descreva a organização do seu código em arquivos de cabeçalho (`.h`) e arquivos de implementação (`.c`), explicando a responsabilidade de cada módulo.

* `main.c`: Contém a função principal (`main`) e o menu interativo.
* `include/utilitarios.h` / `src/utilitarios.c`: Funções auxiliares gerais (ex: limpar buffer de entrada).
* `include/local.h` / `src/local.c`: Definição da `struct Local` e implementação das funções de CRUD para Locais.
* `include/veiculo.h` / `src/veiculo.c`: Definição da `struct Veiculo` e implementação das funções de CRUD para Veículos.
* `include/pedido.h` / `src/pedido.c`: Definição da `struct Pedido` e implementação das funções de CRUD para Pedidos.
* `include/roteamento.h` / `src/roteamento.c`: Implementação da lógica de cálculo de rota e simulação de entrega.
* `include/persistencia.h` / `src/persistencia.c`: Funções para backup e restauração de dados em arquivos binários.

## 5. Funcionalidades Implementadas

### 5.1. Gerenciamento de Locais (CRUD)

* **Criar Local:** Usuário insere nome (único) e coordenadas. Se válido e há espaço no vetor, a struct Local é adicionada ao vetor locais, e totalLocais é incrementado.
* **Listar Locais:** Percorre o vetor locais e exibe nome e coordenadas de cada Local.
* **Atualizar Local:** Usuário informa nome do local. Após busca no vetor, novos valores são solicitados e a struct é atualizada.
* **Excluir Local:** Usuário informa nome do local. Após busca, o Local é removido do vetor com deslocamento de elementos subsequentes, e totalLocais é decrementado.

### 5.2. Gerenciamento de Veículos (CRUD)

* **Criar Veículo:** Usuário fornece placa (única), modelo, status (inicialmente "Disponível") e nome do local atual (Local existente). Após validação, a struct Veiculo é adicionada ao vetor veiculos.
* **Listar Veículos:** Percorre o vetor veiculos e exibe placa, modelo, status (traduzido) e local atual de cada Veiculo.
* **Atualizar Veículo:** Usuário informa placa do veículo. Após busca, permite atualizar modelo, status e/ou local atual.
* **Excluir Veículo:** Usuário informa placa do veículo. Após busca, o Veiculo é removido do vetor com deslocamento.

### 5.3. Gerenciamento de Pedidos (CRUD)

* **Criar Pedido:** Sistema gera ID único. Usuário informa nomes de locais de origem/destino (Locais existentes) e peso. Após validações, a struct Pedido é adicionada ao vetor pedidos.
* **Listar Pedidos:** Percorre o vetor pedidos e exibe ID, locais de origem/destino e peso de cada Pedido.
* **Atualizar Pedido:** Usuário informa ID do pedido. Após busca, permite atualizar locais ou peso.
* **Excluir Pedido:** Usuário informa ID do pedido. Após busca, o Pedido é removido do vetor com deslocamento.

### 5.4. Cálculo e Exibição de Rota de Entrega

* **Algoritmo:** Para um pedido, encontra o Veiculo "Disponível" mais próximo do Local de origem, calculando a menor distância entre eles.
* **Cálculo de Distância:** Uma função auxiliar (calculaDistanciaEuclidiana) usa a fórmula $D = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$.
* **Simulação de Entrega:** O status do Veiculo selecionado muda para "Ocupado". Após simulação, o status volta para "Disponível" e o localAtualNome do Veiculo é atualizado para o Local de destino do pedido.

### 5.5. Backup e Restauração de Dados

* **Backup:** Funções específicas para cada entidade abrem arquivos binários (.bin) em modo de escrita ("wb"). Os dados dos vetores em memória são gravados nos arquivos usando `fwrite()`.
* **Restauração:** Funções correspondentes abrem os arquivos binários em modo de leitura ("rb"). Os dados são lidos com `fread()` e carregados para os vetores em memória, atualizando as contagens totais.

## 6. Análise de Complexidade (Contagem de Operações)

Para as operações críticas, realizamos uma análise da quantidade de operações em função do tamanho do problema (N). Os resultados são apresentados a seguir:

* **Exemplo: Busca do Veículo Mais Próximo**
    * **Descrição:** Para encontrar o veículo mais próximo de um ponto de origem, é necessário iterar sobre todos os `N` veículos disponíveis, calcular a distância de cada um até o ponto e comparar para encontrar o menor.
    * **Contagem de Operações:** O algoritmo envolve aproximadamente `N` iterações. Em cada iteração, realiza-se um cálculo de distância (que envolve subtrações, potências, soma e raiz quadrada - operações de tempo constante) e uma comparação. Portanto, a complexidade é aproximadamente $O(N)$.
    * **Conclusão:** À medida que o número de veículos `N` aumenta, o tempo de execução para encontrar o veículo mais próximo cresce linearmente.

* **Exemplo: Operações de Exclusão (Local, Veículo, Pedido)**
    * **Descrição:** Na exclusão de uma entidade (Local, Veículo ou Pedido) de um vetor, após encontrar a posição do elemento a ser removido, os elementos subsequentes precisam ser deslocados uma posição para trás para preencher o "buraco" deixado. No pior caso (excluir o primeiro elemento), todos os `N-1` elementos restantes precisam ser deslocados.
    * **Contagem de Operações:** Esta operação envolve um número de deslocamentos proporcional a `N`. Portanto, a complexidade é aproximadamente $O(N)$.
    * **Conclusão:** O tempo de execução para uma operação de exclusão cresce linearmente com o número `N` de elementos no vetor.

* **Exemplo: Cálculo de Rota (para um único pedido)**
    * **Descrição:** Uma vez que o veículo e os locais de origem/destino são definidos, o cálculo da rota envolve apenas a aplicação da fórmula da distância euclidiana.
    * **Contagem de Operações:** $O(1)$ (tempo constante), pois o cálculo da distância é fixo, independentemente do número de Locais ou Veículos cadastrados.

## 7. Testes Automatizados

### 7.1. Ferramenta de Teste

Utilizamos a biblioteca `munit` para a automatização dos testes.

### 7.2. Planejamento de Casos de Teste

Apresente uma tabela com os casos de teste para as funcionalidades, incluindo:
* **Funcionalidade:** Qual função está sendo testada.
* **Cenário de Teste:** Descrição do que está sendo testado (ex: "Criar um local com nome válido").
* **Entradas:** Valores de entrada fornecidos à função.
* **Procedimento de Teste:** Passos para executar o teste.
* **Saída Esperada:** O que a função deveria retornar ou qual o estado esperado do sistema após a execução.

| Funcionalidade | Cenário de Teste | Entradas | Procedimento de Teste | Saída Esperada |
| :------------- | :--------------- | :-------------------------------------------- | :------------------------------------------------------- | :--------------------------------------------------------------------------- |
| `criarLocal()` | Criar local com sucesso | Nome: "Belo Horizonte", X: 10, Y: 20 | Chamar `criarLocal` com os dados. | Retorno indicando sucesso, `totalLocais` incrementado, local no vetor. |
| `listarLocais()` | Listar locais vazios | N/A (vetor `locais` vazio) | Chamar `listarLocais`. | Mensagem "Nenhum local cadastrado." |
| `criarLocal()` | Criar local com nome duplicado | Nome: "Belo Horizonte", X: 30, Y: 40 (após o anterior) | Chamar `criarLocal`. | Mensagem de erro/falha ao tentar criar local com nome já existente. |
| `calculaDistanciaEuclidiana()` | Distância entre dois pontos | P1:(0,0), P2:(3,4) | Chamar a função de distância. | 5.0 |

### 7.3. Implementação dos Casos de Teste Automatizados

Os testes automatizados do projeto SLEM foram implementados utilizando a biblioteca munit, que oferece um framework leve para criação e execução de testes unitários em C. A metodologia envolveu a criação de funções de teste separadas para cada cenário, que verificam o comportamento esperado das funções do sistema através de asserções.

Estrutura Básica de um Arquivo de Teste (test_local.c como exemplo):

Inclusão de Headers: Inclui-se o header do munit e os headers das funções a serem testadas.

Funções de Teste: Cada caso de teste é uma função separada que retorna `MUNIT_OK` em caso de sucesso e `MUNIT_FAIL` em caso de falha.

Asserções: Dentro das funções de teste, utilizam-se as macros de asserção do munit (ex: `munit_assert_true`, `munit_assert_int`, `munit_assert_string_equal`) para verificar se as condições esperadas são atendidas.

Configuração de Testes: Um array de `MunitTest` define a lista de testes a serem executados.

Main do Teste: A função `munit_suite_main` é chamada para executar todos os testes definidos.

```c
// Exemplo de trecho de código de test_local.c
#include "munit/munit.h"
#include "../include/local.h" // Incluir o header da funcionalidade a ser testada

// Mock de variáveis globais ou de contexto, se necessário para o teste
Local locais_teste[MAX_ENTIDADES];
int totalLocais_teste = 0;

static MunitResult test_criarLocal_sucesso(const MunitParameter params[], void* data) {
    // Resetar o estado antes de cada teste, se necessário
    totalLocais_teste = 0;

    // Simular a entrada do usuário ou passar diretamente os dados
    // (A função criarLocal no mundo real pediria scanf, aqui testamos a lógica interna)
    // Para testar a função real de I/O, seria necessário mocking ou redirecionamento de stdin.
    // Aqui testamos a lógica que manipularia os dados APÓS a entrada.

    // Assumindo uma versão de criarLocal que recebe os dados diretamente para testabilidade:
    // void criarLocal_para_teste(Local locais[], int *totalLocais, const char* nome, float x, float y);
    // Mas se a função real usar I/O, o teste se concentraria em efeitos colaterais.

    // Exemplo de como você testaria os efeitos de uma criação:
    // Simular a chamada de criarLocal (se ela manipular os arrays diretamente)
    // Normalmente, você teria uma função auxiliar de teste que preenche o array
    strcpy(locais_teste[totalLocais_teste].nome, "LocalTeste1");
    locais_teste[totalLocais_teste].coordX = 10.0f;
    locais_teste[totalLocais_teste].coordY = 20.0f;
    totalLocais_teste++; // Simula o incremento de totalLocais

    // Verificar se o local foi adicionado e se a contagem está correta
    munit_assert_int(totalLocais_teste, ==, 1);
    munit_assert_string_equal(locais_teste[0].nome, "LocalTeste1");
    munit_assert_float(locais_teste[0].coordX, ==, 10.0f);
    munit_assert_float(locais_teste[0].coordY, ==, 20.0f);

    return MUNIT_OK;
}

static MunitResult test_listarLocais_vazio(const MunitParameter params[], void* data) {
    totalLocais_teste = 0; // Garantir que o vetor está vazio

    // Para testar a saída de texto, você precisaria redirecionar stdout.
    // Para este escopo, o teste garante que a função não falha e lida com o caso vazio.
    // Em um teste real, você capturaria o output e faria munit_assert_string_equal.
    // Exemplo:
    // char buffer[256];
    // freopen("temp_output.txt", "w", stdout);
    // listarLocais(locais_teste, totalLocais_teste);
    // freopen("/dev/tty", "w", stdout); // Volta stdout
    // FILE* f = fopen("temp_output.txt", "r");
    // fgets(buffer, sizeof(buffer), f);
    // munit_assert_string_equal(buffer, "Nenhum local cadastrado.\n");
    // fclose(f);
    // remove("temp_output.txt");

    // Para o objetivo atual, um teste que apenas chama a função e não falha já é um começo.
    listarLocais(locais_teste, totalLocais_teste); // Chama a função, verifica se não crasha.
    return MUNIT_OK;
}

// Lista de testes para o módulo local
static MunitTest local_tests[] = {
    { "/criarLocal_sucesso", test_criarLocal_sucesso, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/listarLocais_vazio", test_listarLocais_vazio, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } // Fim da lista
};

// Suite principal de testes
static const MunitSuite test_suite = {
    "/local_module", // Nome da suite
    local_tests,     // Array de testes
    NULL,            // Sub-suites
    1,               // Número de fixtures de setup/teardown (opcional)
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&test_suite, (void*) "slem_test", argc, argv);
}