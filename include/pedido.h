#ifndef PEDIDO_H
#define PEDIDO_H

#include "../include/utilitarios.h" // Para MAX_NOME_LOCAL
#include "../include/local.h}       // Para referenciar Local

// Definição da struct Pedido
typedef struct {
    int id;
    char origemNome[MAX_NOME_LOCAL];
    char destinoNome[MAX_NOME_LOCAL];
    float pesoKg;
    // int status; // Poderia ser adicionado para "pendente", "em transito", "entregue"
} Pedido;

// Protótipos das funções de CRUD para Pedido
void criarPedido(Pedido pedidos[], int *totalPedidos, Local locais[], int totalLocais);
void listarPedidos(Pedido pedidos[], int totalPedidos);
void atualizarPedido(Pedido pedidos[], int totalPedidos, Local locais[], int totalLocais);
void excluirPedido(Pedido pedidos[], int *totalPedidos);
int buscarPedidoPorId(Pedido pedidos[], int totalPedidos, int id); // Retorna índice ou -1

#endif // PEDIDO_H