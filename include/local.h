#ifndef LOCAL_H
#define LOCAL_H

#include "../include/utilitarios.h" // Para MAX_NOME_LOCAL

// Definição da struct Local
typedef struct {
    char nome[MAX_NOME_LOCAL];
    float coordX;
    float coordY;
} Local;

// Protótipos das funções de CRUD para Local
void criarLocal(Local locais[], int *totalLocais);
void listarLocais(Local locais[], int totalLocais);
void atualizarLocal(Local locais[], int totalLocais);
void excluirLocal(Local locais[], int *totalLocais);
int buscarLocalPorNome(Local locais[], int totalLocais, const char *nome); // Retorna índice ou -1

#endif // LOCAL_H