#ifndef VEICULO_H
#define VEICULO_H

#include "../include/utilitarios.h" // Para MAX_PLACA_VEICULO, MAX_MODELO_VEICULO, MAX_NOME_LOCAL
#include "../include/local.h"       // Para referenciar Local

// Definição da struct Veiculo
typedef struct {
    char placa[MAX_PLACA_VEICULO];
    char modelo[MAX_MODELO_VEICULO];
    int status; // 0 = Disponível, 1 = Ocupado
    char localAtualNome[MAX_NOME_LOCAL]; // Nome do Local onde o veículo se encontra
} Veiculo;

// Protótipos das funções de CRUD para Veiculo
void criarVeiculo(Veiculo veiculos[], int *totalVeiculos, Local locais[], int totalLocais);
void listarVeiculos(Veiculo veiculos[], int totalVeiculos);
void atualizarVeiculo(Veiculo veiculos[], int totalVeiculos, Local locais[], int totalLocais);
void excluirVeiculo(Veiculo veiculos[], int *totalVeiculos);
int buscarVeiculoPorPlaca(Veiculo veiculos[], int totalVeiculos, const char *placa); // Retorna índice ou -1

#endif // VEICULO_H