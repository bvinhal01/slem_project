#ifndef ROTEAMENTO_H
#define ROTEAMENTO_H

#include "../include/local.h"   // Para struct Local e buscarLocalPorNome
#include "../include/veiculo.h" // Para struct Veiculo e buscarVeiculoPorPlaca, e status do veiculo
#include "../include/pedido.h"  // Para struct Pedido e buscarPedidoPorId
#include "../include/utilitarios.h" // Para calculaDistanciaEuclidiana

// Protótipos das funções de roteamento e simulação
void simularEntrega(Pedido pedidos[], int totalPedidos, Veiculo veiculos[], int *totalVeiculos, Local locais[], int totalLocais);

#endif // ROTEAMENTO_H