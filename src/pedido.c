#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para system("clear") ou system("cls")

#include "../include/pedido.h"
#include "../include/utilitarios.h"
#include "../include/local.h" // Para usar buscarLocalPorNome

// Variável estática para gerar IDs de pedido (simples, para evitar duplicação)
static int proximoIdPedido = 1;

// Função para buscar um pedido pelo ID
// Retorna o índice do pedido no vetor ou -1 se não encontrado
int buscarPedidoPorId(Pedido pedidos[], int totalPedidos, int id) {
    for (int i = 0; i < totalPedidos; i++) {
        if (pedidos[i].id == id) {
            return i;
        }
    }
    return -1; // Pedido não encontrado
}

// Implementação das funções de CRUD para Pedido

void criarPedido(Pedido pedidos[], int *totalPedidos, Local locais[], int totalLocais) {
    if (*totalPedidos >= MAX_ENTIDADES) {
        printf("Limite maximo de pedidos atingido!\n");
        return;
    }

    Pedido novoPedido;
    char origemNomeTemp[MAX_NOME_LOCAL];
    char destinoNomeTemp[MAX_NOME_LOCAL];

    printf("\n--- CADASTRAR NOVO PEDIDO ---\n");

    // Gerar ID único
    novoPedido.id = proximoIdPedido++; // Incrementa para o próximo
    printf("ID do Pedido: %d (gerado automaticamente)\n", novoPedido.id);

    printf("Nome do Local de Origem: ");
    fgets(origemNomeTemp, MAX_NOME_LOCAL, stdin);
    origemNomeTemp[strcspn(origemNomeTemp, "\n")] = '\0';

    if (buscarLocalPorNome(locais, totalLocais, origemNomeTemp) == -1) {
        printf("ERRO: Local de origem '%s' nao encontrado. Cadastre o local primeiro.\n", origemNomeTemp);
        proximoIdPedido--; // Desfaz o incremento do ID se o pedido não for criado
        return;
    }
    strcpy(novoPedido.origemNome, origemNomeTemp);

    printf("Nome do Local de Destino: ");
    fgets(destinoNomeTemp, MAX_NOME_LOCAL, stdin);
    destinoNomeTemp[strcspn(destinoNomeTemp, "\n")] = '\0';

    if (buscarLocalPorNome(locais, totalLocais, destinoNomeTemp) == -1) {
        printf("ERRO: Local de destino '%s' nao encontrado. Cadastre o local primeiro.\n", destinoNomeTemp);
        proximoIdPedido--; // Desfaz o incremento do ID
        return;
    }
    strcpy(novoPedido.destinoNome, destinoNomeTemp);

    printf("Peso do Item (Kg): ");
    scanf("%f", &novoPedido.pesoKg);
    limparBufferEntrada(); // Limpa o buffer após scanf

    pedidos[*totalPedidos] = novoPedido;
    (*totalPedidos)++;
    printf("Pedido %d cadastrado com sucesso!\n", novoPedido.id);
}

void listarPedidos(Pedido pedidos[], int totalPedidos) {
    printf("\n--- PEDIDOS CADASTRADOS ---\n");
    if (totalPedidos == 0) {
        printf("Nenhum pedido cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalPedidos; i++) {
        printf("ID: %d | Origem: %s | Destino: %s | Peso: %.2f Kg\n",
               pedidos[i].id, pedidos[i].origemNome, pedidos[i].destinoNome, pedidos[i].pesoKg);
    }
}

void atualizarPedido(Pedido pedidos[], int totalPedidos, Local locais[], int totalLocais) {
    int idBusca;
    char origemNomeTemp[MAX_NOME_LOCAL];
    char destinoNomeTemp[MAX_NOME_LOCAL];
    float novoPeso;

    printf("\n--- ATUALIZAR PEDIDO ---\n");
    printf("Digite o ID do pedido que deseja atualizar: ");
    scanf("%d", &idBusca);
    limparBufferEntrada();

    int indice = buscarPedidoPorId(pedidos, totalPedidos, idBusca);

    if (indice != -1) {
        printf("Pedido encontrado: ID: %d | Origem: %s | Destino: %s | Peso: %.2f Kg\n",
               pedidos[indice].id, pedidos[indice].origemNome, pedidos[indice].destinoNome, pedidos[indice].pesoKg);

        printf("\nNovas informacoes (deixe em branco para manter a atual):\n");

        printf("Novo Local de Origem (atual: %s): ", pedidos[indice].origemNome);
        fgets(origemNomeTemp, MAX_NOME_LOCAL, stdin);
        origemNomeTemp[strcspn(origemNomeTemp, "\n")] = '\0';
        if (strlen(origemNomeTemp) > 0) {
            if (buscarLocalPorNome(locais, totalLocais, origemNomeTemp) != -1) {
                strcpy(pedidos[indice].origemNome, origemNomeTemp);
            } else {
                printf("Local de origem '%s' nao encontrado. Mantendo o local atual.\n", origemNomeTemp);
            }
        }

        printf("Novo Local de Destino (atual: %s): ", pedidos[indice].destinoNome);
        fgets(destinoNomeTemp, MAX_NOME_LOCAL, stdin);
        destinoNomeTemp[strcspn(destinoNomeTemp, "\n")] = '\0';
        if (strlen(destinoNomeTemp) > 0) {
            if (buscarLocalPorNome(locais, totalLocais, destinoNomeTemp) != -1) {
                strcpy(pedidos[indice].destinoNome, destinoNomeTemp);
            } else {
                printf("Local de destino '%s' nao encontrado. Mantendo o local atual.\n", destinoNomeTemp);
            }
        }

        printf("Novo Peso do Item (Kg) (atual: %.2f): ", pedidos[indice].pesoKg);
        char pesoStr[20];
        fgets(pesoStr, sizeof(pesoStr), stdin);
        pesoStr[strcspn(pesoStr, "\n")] = '\0';
        if (strlen(pesoStr) > 0) {
            if (sscanf(pesoStr, "%f", &novoPeso) == 1 && novoPeso > 0) {
                pedidos[indice].pesoKg = novoPeso;
            } else {
                printf("Peso invalido. Mantendo o peso atual.\n");
            }
        }

        printf("Pedido %d atualizado com sucesso!\n", pedidos[indice].id);
    } else {
        printf("Pedido com ID %d nao encontrado.\n", idBusca);
    }
}

void excluirPedido(Pedido pedidos[], int *totalPedidos) {
    int idBusca;
    printf("\n--- EXCLUIR PEDIDO ---\n");
    printf("Digite o ID do pedido que deseja excluir: ");
    scanf("%d", &idBusca);
    limparBufferEntrada();

    int indice = buscarPedidoPorId(pedidos, *totalPedidos, idBusca);

    if (indice != -1) {
        // Move os elementos seguintes uma posição para trás
        for (int i = indice; i < (*totalPedidos - 1); i++) {
            pedidos[i] = pedidos[i + 1];
        }
        (*totalPedidos)--;
        printf("Pedido %d excluido com sucesso!\n", idBusca);
    } else {
        printf("Pedido com ID %d nao encontrado.\n", idBusca);
    }
}