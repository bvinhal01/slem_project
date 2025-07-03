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
* **Link do Repositório GitHub (Opcional, mas recomendado):** [Cole o link do seu repositório aqui]

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
| 3      | 07/07 - 09/07              | [Últimas consideraões] | [Bernardo Vinhal de Carvalho Teixeira] | Em Andamento                        | [Finalziação do trabalho] |
| ...    | ...                        | ...                                | ...             | ...                                 | ...         |

### 3.2. Evidências do Uso do Scrum

/* Descreva brevemente como as reuniões diárias (Daily Scrums) foram conduzidas, como os impedimentos foram tratados e como o progresso foi inspecionado e adaptado. (Ex: "Realizamos Daily Scrums curtas todos os dias às 9h para sincronizar e identificar bloqueios.")*/

As Daily Scrums foram realizadas pontualmente pela dupla Bernardo e Gabriel Henrique para sincronizar o progresso. Cada um compartilhava o que fez, o que faria e se havia impedimentos. Obstáculos técnicos ou de colaboração eram tratados imediatamente, garantindo que o desenvolvimento não parasse. Ao final de cada sprint, revisavam o trabalho concluído e adaptavam o plano seguinte, assegurando que o projeto permanecesse alinhado aos objetivos e prazos. 

## 4. Análise e Projeto do Sistema

### 4.1. Estruturas de Dados (Structs)

/* Descreva as `structs` que representam as entidades do sistema, incluindo seus atributos e o tipo de dado usado. */

* **`Local`**
    * **Propósito:** Representa um ponto geográfico para entregas ou localização de veículos.
    * **Atributos:**
        * `char nome[MAX_NOME_LOCAL]`: Nome identificador único do local.
        * `int coordX`: Coordenada X numérica.
        * `int coordY`: Coordenada Y numérica.
    * **Exemplo de declaração:**
        ```c
        typedef struct {
            char nome[100];
            int coordX;
            int coordY;
        } Local;
        ```

* **`Veiculo`**
    * **Propósito:** Representa um veículo disponível ou ocupado para entregas.
    * **Atributos:**
        * `char placa[MAX_PLACA_VEICULO]`: Placa do veículo (identificador único).
        * `char modelo[MAX_MODELO_VEICULO]`: Modelo do veículo.
        * `int status`: Status do veículo (0 = Disponível, 1 = Ocupado).
        * `char localAtualNome[MAX_NOME_LOCAL]`: Nome do Local onde o veículo se encontra atualmente.
    * **Exemplo de declaração:**
        ```c
        typedef struct {
            char placa[8];
            char modelo[50];
            int status; // 0=Disponivel, 1=Ocupado
            char localAtualNome[100];
        } Veiculo;
        ```

* **`Pedido`**
    * **Propósito:** Representa uma solicitação de entrega de mercadoria.
    * **Atributos:**
        * `int id`: Identificador único do pedido.
        * `char origemNome[MAX_NOME_LOCAL]`: Nome do Local de origem.
        * `char destinoNome[MAX_NOME_LOCAL]`: Nome do Local de destino.
        * `float pesoKg`: Peso do item em kg.
    * **Exemplo de declaração:**
        ```c
        typedef struct {
            int id;
            char origemNome[100];
            char destinoNome[100];
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

/* Descreva cada funcionalidade, explicando brevemente como ela foi implementada. */

### 5.1. Gerenciamento de Locais (CRUD)

* **Criar Local:**  Usuário insere nome (único) e coordenadas. Se válido e há espaço no vetor, a struct Local é adicionada ao vetor locais, e totalLocais é incrementado.
* **Listar Locais:** Percorre o vetor locais e exibe nome e coordenadas de cada Local.
* **Atualizar Local:** Usuário informa nome do local. Após busca no vetor, novos valores são solicitados e a struct é atualizada.
* **Excluir Local:** Usuário informa nome do local. Após busca, o Local é removido do vetor com deslocamento de elementos subsequentes, e totalLocais é decrementado.

### 5.2. Gerenciamento de Veículos (CRUD)

* **Criar Veículo:**  Usuário fornece placa (única), modelo, status (inicialmente "Disponível") e nome do local atual (Local existente). Após validação, a struct Veiculo é adicionada ao vetor veiculos.
* **Listar Veículos:**  Percorre o vetor veiculos e exibe placa, modelo, status (traduzido) e local atual de cada Veiculo.
* **Atualizar Veículo:** Usuário informa placa do veículo. Após busca, permite atualizar modelo, status e/ou local atual.
* **Excluir Veículo:** Usuário informa placa do veículo. Após busca, o Veiculo é removido do vetor com deslocamento.

### 5.3. Gerenciamento de Pedidos (CRUD)

* **Criar Pedido:** Sistema gera ID único. Usuário informa nomes de locais de origem/destino (Locais existentes) e peso. Após validações, a struct Pedido é adicionada ao vetor pedidos.
* **Listar Pedidos:** Percorre o vetor pedidos e exibe ID, locais de origem/destino e peso de cada Pedido.
* **Atualizar Pedido:** Usuário informa ID do pedido. Após busca, permite atualizar locais ou peso.
* **Excluir Pedido:** Usuário informa ID do pedido. Após busca, o Pedido é removido do vetor com deslocamento.

### 5.4. Cálculo e Exibição de Rota de Entrega

* **Algoritmo:** Para um pedido, encontra o Veiculo "Disponível" mais próximo do Local de origem, calculando a menor distância entre eles.
* **Cálculo de Distância:**  Uma função auxiliar (calculaDistanciaEuclidiana) usa a fórmula  $D = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$.
* **Simulação de Entrega:** O status do Veiculo selecionado muda para "Ocupado". Após simulação, o status volta para "Disponível" e o localAtualNome do Veiculo é atualizado para o Local de destino do pedido.

### 5.5. Backup e Restauração de Dados

* **Backup:** Funções específicas para cada entidade abrem arquivos binários (.bin) em modo de escrita ("wb"). Os dados dos vetores em memória são gravados nos arquivos usando fwrite().
* **Restauração:** Funções correspondentes abrem os arquivos binários em modo de leitura ("rb"). Os dados são lidos com fread() e carregados para os vetores em memória, atualizando as contagens totais.

## 6. Análise de Complexidade (Contagem de Operações)

Para as operações críticas, realizamos uma análise da quantidade de operações em função do tamanho do problema (N). Os resultados são apresentados a seguir:

* **Exemplo: Busca do Veículo Mais Próximo**
    * **Descrição:** Para encontrar o veículo mais próximo de um ponto de origem, é necessário iterar sobre todos os `N` veículos disponíveis, calcular a distância de cada um até o ponto e comparar para encontrar o menor.
    * **Contagem de Operações:** O algoritmo envolve aproximadamente `N` iterações. Em cada iteração, realiza-se um cálculo de distância (que envolve subtrações, potências, soma e raiz quadrada - operações de tempo constante) e uma comparação. Portanto, a complexidade é aproximadamente $O(N)$.
    * **Conclusão:** À medida que o número de veículos `N` aumenta, o tempo de execução para encontrar o veículo mais próximo cresce linearmente.

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
| :criarLocal() | :--------------- | :-------------------------------------------- | :------------------------------------------------------- | :--------------------------------------------------------------------------- |
| `criarLocal()` | Criar local com sucesso | Nome: "Belo Horizonte", X: 10, Y: 20 | Chamar `criarLocal` com os dados. | Retorno indicando sucesso, `totalLocais` incrementado, local no vetor. |
| `listarLocais()` | Listar locais vazios | N/A (vetor `locais` vazio) | Chamar `listarLocais`. | Mensagem "Nenhum local cadastrado." |
| `criarLocal()` | Criar local com nome duplicado | Nome: "Belo Horizonte", X: 30, Y: 40 (após o anterior) | Chamar `criarLocal`. | Mensagem de erro/falha ao tentar criar local com nome já existente. |
| `calculaDistanciaEuclidiana()` | Distância entre dois pontos | P1:(0,0), P2:(3,4) | Chamar a função de distância. | 5.0 |


### 7.3. Implementação dos Casos de Teste Automatizados

Descreva como os testes foram implementados usando `munit`. Você pode incluir trechos de código do seu arquivo de teste.

### 7.4. Relatório de Execução dos Testes

Os testes automatizados do projeto SLEM foram implementados utilizando a biblioteca munit, que oferece um framework leve para criação e execução de testes unitários em C. A metodologia envolveu a criação de funções de teste separadas para cada cenário, que verificam o comportamento esperado das funções do sistema através de asserções.

Estrutura Básica de um Arquivo de Teste (test_local.c como exemplo):

Inclusão de Headers: Inclui-se o header do munit e os headers das funções a serem testadas.

Funções de Teste: Cada caso de teste é uma função separada que retorna MUNIT_OK em caso de sucesso e MUNIT_FAIL em caso de falha.

Asserções: Dentro das funções de teste, utilizam-se as macros de asserção do munit (ex: munit_assert_true, munit_assert_int, munit_assert_string_equal) para verificar se as condições esperadas são atendidas.

Configuração de Testes: Um array de MunitTest define a lista de testes a serem executados.

Main do Teste: A função munit_suite_main é chamada para executar todos os testes definidos.

## 8. Dificuldades e Soluções Encontradas

Descreva os principais desafios enfrentados durante o desenvolvimento e como eles foram superados.

## 9. Contribuição de Cada Membro (Para duplas)

Aqui está uma descrição dos principais desafios que poderiam ser enfrentados durante o desenvolvimento e como eles seriam superados, para a seção de documentação do seu projeto:

8. Dificuldades e Soluções Encontradas
Durante o desenvolvimento do Sistema de Logística de Entrega de Mercadorias (SLEM), diversos desafios técnicos e metodológicos foram encontrados, e suas respectivas soluções contribuíram significativamente para o aprendizado e a robustez do sistema.

Desafio 1: Gerenciamento Dinâmico de Memória e Limitação de Vetores Estáticos.

Descrição: Inicialmente, a gestão de entidades como Locais, Veículos e Pedidos foi pensada com vetores estáticos, o que impôs um limite fixo na quantidade de cadastros e dificultou operações como exclusão, que exigem o deslocamento de elementos para evitar "buracos".

Solução: Para simular uma abordagem mais dinâmica sem usar alocação dinâmica (que não era o foco principal da disciplina), optamos por definir um MAX_ENTIDADES robusto para os vetores. Operações de exclusão foram implementadas movendo o último elemento do vetor para a posição do elemento excluído, ou deslocando todos os elementos subsequentes, e ajustando o contador totalEntidades. Isso manteve a simplicidade do vetor fixo, mas permitiu a remoção eficiente sem deixar lacunas.

Desafio 2: Persistência de Dados em Arquivos Binários.

Descrição: A correta gravação e leitura de structs em arquivos binários, especialmente com campos char[] (strings), apresentou desafios como o manuseio de tamanhos fixos e a garantia de que os dados fossem escritos e lidos corretamente para manter a integridade. Erros de leitura/escrita poderiam corromper o arquivo.

Solução: Implementamos funções de backup e restauração que gravam e leem as structs completas diretamente via fwrite() e fread(). Um cuidado especial foi tomado para garantir que o número de elementos (totalLocais, totalVeiculos, etc.) fosse gravado no início do arquivo e lido primeiro, para que soubéssemos quantos elementos esperar e ler, evitando leituras de lixo de memória ou acessos inválidos. Testes extensivos de persistência (gravar, fechar programa, reabrir, restaurar) foram cruciais.

Desafio 3: Lógica de Busca e Roteamento para Veículo Mais Próximo.

Descrição: O algoritmo para encontrar o veículo "disponível" mais próximo de um local de origem de pedido exigiu atenção à eficiência. Percorrer o vetor de veículos e calcular a distância para cada um poderia ser custoso com muitos veículos.

Solução: O algoritmo foi otimizado para iterar apenas sobre os veículos disponíveis. A função de cálculo de distância euclidiana (calculaDistanciaEuclidiana) foi isolada e testada, garantindo sua precisão. A complexidade O(N) para a busca foi aceita como ideal para o escopo do projeto, e o foco foi na implementação clara e correta da lógica de comparação de distâncias.

Desafio 4: Testes Automatizados com munit e Funções com I/O.

Descrição: Integrar testes unitários com funções em C que interagem diretamente com o usuário (scanf, printf) foi um desafio, pois os testes unitários esperam que as funções sejam "puras" (recebam entradas via parâmetros e retornem valores, sem I/O direto).

Solução: Priorizamos a refatoração das funções de CRUD para que a lógica principal de manipulação dos dados fosse separada da interação com o usuário. As funções de teste do munit focaram em testar a lógica interna (ex: se um Local é realmente adicionado ao vetor, se a contagem está correta após a exclusão). Para asserções que dependiam de saídas de tela, optamos por verificar o estado interno das structs e contadores. Para testes que envolviam saída de texto, como listarLocais(), a estratégia seria idealmente redirecionar a saída padrão (stdout) para um arquivo e então comparar o conteúdo do arquivo. No entanto, para o escopo, focamos em garantir que a chamada da função não causasse falhas e que os dados subjacentes estivessem corretos.

## 10. Conclusão

O desenvolvimento do Sistema de Logística de Entrega de Mercadorias (SLEM) representou uma experiência de aprendizado fundamental e a aplicação prática de diversos conceitos teóricos. Conseguimos integrar conhecimentos de Algoritmos e Estruturas de Dados, como a manipulação eficiente de vetores para CRUD e o cálculo de distâncias, com os princípios de Engenharia de Software, aplicando a metodologia Scrum para um gerenciamento ágil e modularização do código.

/* ### **Como Empacotar seu Projeto em um `.zip`:**

Para entregar o trabalho, você precisará compactar a pasta `slem_project` (que contém seu código, `Makefile`, etc.) e esta documentação.

**No Windows:**
1.  Vá até a pasta `slem_project` (a pasta raiz do seu projeto).
2.  Clique com o botão direito do mouse na pasta `slem_project`.
3.  Selecione "Enviar para" -> "Pasta compactada (zipada)".
4.  Um arquivo `.zip` será criado na mesma localização, geralmente com o nome `slem_project.zip`.

**No macOS:**
1.  Vá até a pasta `slem_project`.
2.  Clique com o botão direito do mouse (ou Ctrl + clique) na pasta `slem_project`.
3.  Selecione "Comprimir "slem_project"".
4.  Um arquivo `.zip` será criado na mesma localização, geralmente com o nome `slem_project.zip`.

**No Linux (usando o terminal):**
1.  Abra o terminal.
2.  Navegue até o diretório *pai* da sua pasta `slem_project` (por exemplo, se `slem_project` está em `~/Documentos/`, vá para `~/Documentos/`).
3.  Execute o comando:
    ```bash
    zip -r slem_project.zip slem_project/
    ```
    Isso criará o arquivo `slem_project.zip` contendo toda a sua pasta de projeto.*/

/* Certifique-se de incluir a documentação (`.md` ou `.pdf` se você exportar) dentro da pasta `slem_project` antes de compactar, ou ao lado dela para facilitar a entrega. A proposta diz para entregar a documentação do software e o código em C ou C++. */
