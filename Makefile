# Makefile para o Projeto SLEM

# Compilador C
CC = gcc

# Flags de compilação
# -Wall: Habilita todos os warnings
# -g: Inclui informações de debug (útil para gdb)
# -I: Especifica diretórios de inclusão para headers
# -std=c11: Usa o padrão C11
# -lm: Linka com a biblioteca matemática (para sqrtf em utilitarios.c)
CFLAGS = -Wall -g -Iinclude -std=c11 -lm

# Diretórios
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
DATA_DIR = data # Para arquivos de persistência

# Arquivo executável principal
TARGET = $(BIN_DIR)/slem

# Arquivos fonte C
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/utilitarios.c \
       $(SRC_DIR)/local.c \
       $(SRC_DIR)/veiculo.c \
       $(SRC_DIR)/pedido.c \
       $(SRC_DIR)/roteamento.c \
       $(SRC_DIR)/persistencia.c

# Arquivos objeto (gerados a partir dos fontes)
# Substitui o diretório e a extensão .c por .o no OBJ_DIR
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Arquivo de teste
TEST_SRC = $(TEST_DIR)/test_local.c
TEST_OBJ = $(OBJ_DIR)/test_local.o
TEST_TARGET = $(BIN_DIR)/slem_test

# Regra padrão: compila e gera o executável principal
all: dirs $(TARGET)

# Cria os diretórios necessários
dirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DATA_DIR)

# Regra para compilar o executável principal
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

# Regra genérica para compilar arquivos .c em .o
# Compila os arquivos fonte do SRC_DIR para o OBJ_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar o arquivo de teste
# O teste precisa dos headers e implementações das funções para testá-las
$(TEST_OBJ): $(TEST_SRC) $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para compilar e linkar o executável de teste
# O executável de teste linka com os objetos do teste e os objetos do programa principal.
# Munit deve estar disponível no sistema ou seus arquivos .c devem ser adicionados.
# Se munit foi baixado e seus .c/.h estão em um diretório 'munit/' dentro de 'include/'
# Você pode precisar de uma flag -Iinclude/munit e, se tiver .c do munit, adicioná-los aos SRCS.
# Para simplicidade, assumimos que munit está disponível via -Iinclude e que o test_local.c
# inclui apenas o que precisa.
test: dirs $(TEST_TARGET)
$(TEST_TARGET): $(TEST_OBJ) $(OBJS)
	$(CC) $(TEST_OBJ) $(OBJS) -o $@ $(CFLAGS)

# Executa os testes
run_tests: test
	@echo "-----------------------------------"
	@echo "EXECUTANDO TESTES AUTOMATIZADOS:"
	@echo "-----------------------------------"
	$(TEST_TARGET)

# Limpa arquivos temporários e executáveis
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(DATA_DIR)/*
	@echo "Limpeza de objetos, executáveis e dados concluída."

# Phony targets para evitar conflitos com arquivos de mesmo nome
.PHONY: all dirs clean test run_tests