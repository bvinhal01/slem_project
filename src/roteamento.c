#include <stdio.h>
#include <string.h>
#include <float.h> // Para DBL_MAX ou FLT_MAX

#include "../include/roteamento.h"
#include "../include/utilitarios.h"
#include "../include/local.h"
#include "../include/veiculo.h"
#include "../include/pedido.h"

// Implementação das funções de roteamento e simulação

void simularEntrega(Pedido pedidos[], int totalPedidos, Veiculo veiculos[], int *totalVeiculos, Local locais[], int totalLocais) {
    int idPedidoBusca;
    printf("\n--- SIMULAR ENTREGA ---\n");
    printf("Digite o ID do pedido que deseja simular a entrega: ");
    scanf("%d", &idPedidoBusca);
    limparBufferEntrada();

    int indicePedido = buscarPedidoPorId(pedidos, totalPedidos, idPedidoBusca);

    if (indicePedido == -1) {
        printf("Pedido com ID %d nao encontrado.\n", idPedidoBusca);
        return;
    }

    // 1. Encontrar o local de origem do pedido
    int indiceLocalOrigem = buscarLocalPorNome(locais, totalLocais, pedidos[indicePedido].origemNome);
    if (indiceLocalOrigem == -1) {
        printf("ERRO: Local de origem do pedido (%s) nao encontrado no sistema.\n", pedidos[indicePedido].origemNome);
        return;
    }
    Local localOrigem = locais[indiceLocalOrigem];

    // 2. Encontrar o veículo disponível mais próximo
    int indiceVeiculoMaisProximo = -1;
    float menorDistancia = FLT_MAX; // Inicializa com valor máximo float

    for (int i = 0; i < *totalVeiculos; i++) {
        if (veiculos[i].status == 0) { // Se o veículo estiver disponível
            int indiceLocalVeiculo = buscarLocalPorNome(locais, totalLocais, veiculos[i].localAtualNome);
            if (indiceLocalVeiculo != -1) {
                Local localVeiculo = locais[indiceLocalVeiculo];
                float distancia = calculaDistanciaEuclidiana(
                                      localVeiculo.coordX, localVeiculo.coordY,
                                      localOrigem.coordX, localOrigem.coordY
                                  );

                if (distancia < menorDistancia) {
                    menorDistancia = distancia;
                    indiceVeiculoMaisProximo = i;
                }
            }
        }
    }

    if (indiceVeiculoMaisProximo == -1) {
        printf("Nenhum veiculo disponivel encontrado para realizar a entrega.\n");
        return;
    }

    // Veículo encontrado
    Veiculo *veiculoSelecionado = &veiculos[indiceVeiculoMaisProximo];
    Local localDestinoPedido = locais[buscarLocalPorNome(locais, totalLocais, pedidos[indicePedido].destinoNome)];

    printf("\n--- Detalhes da Entrega ---\n");
    printf("Pedido ID: %d (Origem: %s | Destino: %s | Peso: %.2f Kg)\n",
           pedidos[indicePedido].id, pedidos[indicePedido].origemNome, pedidos[indicePedido].destinoNome, pedidos[indicePedido].pesoKg);
    printf("Veiculo Selecionado: Placa %s (Modelo: %s)\n", veiculoSelecionado->placa, veiculoSelecionado->modelo);
    printf("Distancia do veiculo ao local de origem: %.2f unidades.\n", menorDistancia);

    // 3. Simular a entrega
    printf("\nSimulando a entrega do pedido %d...\n", pedidos[indicePedido].id);
    veiculoSelecionado->status = 1; // Mudar status para Ocupado

    // Simulação de tempo (poderia ser um sleep ou uma mensagem)
    printf("Veiculo %s em transito para %s...\n", veiculoSelecionado->placa, pedidos[indicePedido].destinoNome);
    // sleep(2); // Para uma pausa real (requer <unistd.h> no Linux/macOS)

    // Após a "entrega", atualizar o status e a localização do veículo
    veiculoSelecionado->status = 0; // Mudar status para Disponível novamente
    strcpy(veiculoSelecionado->localAtualNome, pedidos[indicePedido].destinoNome); // Veículo vai para o destino do pedido

    // Remover o pedido após a entrega (opcional, dependendo da lógica do negócio)
    // Para simplificar, não removemos o pedido, apenas simulamos a entrega.
    // Para remover: chamar excluirPedido(pedidos, totalPedidos, idPedidoBusca);

    printf("Entrega do pedido %d concluida com sucesso!\n", pedidos[indicePedido].id);
    printf("Veiculo %s agora esta em '%s' e esta disponivel.\n", veiculoSelecionado->placa, veiculoSelecionado->localAtualNome);
}