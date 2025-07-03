#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "../include/local.h"
#include "../include/veiculo.h"
#include "../include/pedido.h"

// Protótipos das funções de backup e restauração
void backupDados(Local locais[], int totalLocais, Veiculo veiculos[], int totalVeiculos, Pedido pedidos[], int totalPedidos);
void restaurarDados(Local locais[], int *totalLocais, Veiculo veiculos[], int *totalVeiculos, Pedido pedidos[], int *totalPedidos);

#endif // PERSISTENCIA_H