#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h>

// Inclui os headers das structs e funções
#include "include/utilitarios.h"
#include "include/local.h"
#include "include/veiculo.h"
#include "include/pedido.h"
#include "include/roteamento.h"
#include "include/persistencia.h"

// Variáveis globais para armazenar os dados (vetores estáticos)
Local locais[MAX_ENTIDADES];
int totalLocais = 0;

Veiculo veiculos[MAX_ENTIDADES];
int totalVeiculos = 0;

Pedido pedidos[MAX_ENTIDADES];
int totalPedidos = 0;

// Protótipos das funções do menu
void exibirMenuPrincipal();
void gerenciarLocais();
void gerenciarVeiculos();
void gerenciarPedidos();

int main() {
    // Tenta restaurar dados ao iniciar o programa
    restaurarDados(locais, &totalLocais, veiculos, &totalVeiculos, pedidos, &totalPedidos);

    int opcao;
    do {
        exibirMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o buffer de entrada

        // Limpa a tela (compatível com Windows e Linux/macOS)
        // system("cls || clear");

        switch (opcao) {
            case 1:
                gerenciarLocais();
                break;
            case 2:
                gerenciarVeiculos();
                break;
            case 3:
                gerenciarPedidos();
                break;
            case 4:
                simularEntrega(pedidos, totalPedidos, veiculos, &totalVeiculos, locais, totalLocais);
                break;
            case 5:
                backupDados(locais, totalLocais, veiculos, totalVeiculos, pedidos, totalPedidos);
                break;
            case 0:
                printf("Saindo do sistema. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        printf("\nPressione ENTER para continuar...");
        limparBufferEntrada(); // Espera o ENTER do usuário
        // system("cls || clear"); // Limpa a tela novamente
    } while (opcao != 0);

    // Salva os dados automaticamente ao sair (ou pode ser uma opção do menu)
    backupDados(locais, totalLocais, veiculos, totalVeiculos, pedidos, totalPedidos);

    return 0;
}

void exibirMenuPrincipal() {
    printf("\n--- SISTEMA DE LOGISTICA DE ENTREGA DE MERCADORIAS (SLEM) ---\n");
    printf("1. Gerenciar Locais\n");
    printf("2. Gerenciar Veiculos\n");
    printf("3. Gerenciar Pedidos\n");
    printf("4. Simular Entrega (Atribuir Pedido a Veiculo e Atualizar Status)\n");
    printf("5. Realizar Backup dos Dados\n");
    printf("0. Sair\n");
    printf("----------------------------------------------------------\n");
}

void gerenciarLocais() {
    int opcao;
    do {
        printf("\n--- GERENCIAR LOCAIS ---\n");
        printf("1. Criar Local\n");
        printf("2. Listar Locais\n");
        printf("3. Atualizar Local\n");
        printf("4. Excluir Local\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: criarLocal(locais, &totalLocais); break;
            case 2: listarLocais(locais, totalLocais); break;
            case 3: atualizarLocal(locais, totalLocais); break;
            case 4: excluirLocal(locais, &totalLocais); break;
            case 0: printf("Voltando ao Menu Principal...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            limparBufferEntrada();
        }
    } while (opcao != 0);
}

void gerenciarVeiculos() {
    int opcao;
    do {
        printf("\n--- GERENCIAR VEICULOS ---\n");
        printf("1. Criar Veiculo\n");
        printf("2. Listar Veiculos\n");
        printf("3. Atualizar Veiculo\n");
        printf("4. Excluir Veiculo\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: criarVeiculo(veiculos, &totalVeiculos, locais, totalLocais); break;
            case 2: listarVeiculos(veiculos, totalVeiculos); break;
            case 3: atualizarVeiculo(veiculos, totalVeiculos, locais, totalLocais); break;
            case 4: excluirVeiculo(veiculos, &totalVeiculos); break;
            case 0: printf("Voltando ao Menu Principal...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            limparBufferEntrada();
        }
    } while (opcao != 0);
}

void gerenciarPedidos() {
    int opcao;
    do {
        printf("\n--- GERENCIAR PEDIDOS ---\n");
        printf("1. Criar Pedido\n");
        printf("2. Listar Pedidos\n");
        printf("3. Atualizar Pedido\n");
        printf("4. Excluir Pedido\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: criarPedido(pedidos, &totalPedidos, locais, totalLocais); break;
            case 2: listarPedidos(pedidos, totalPedidos); break;
            case 3: atualizarPedido(pedidos, totalPedidos, locais, totalLocais); break;
            case 4: excluirPedido(pedidos, &totalPedidos); break;
            case 0: printf("Voltando ao Menu Principal...\n"); break;
            default: printf("Opcao invalida. Tente novamente.\n");
        }
        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            limparBufferEntrada();
        }
    } while (opcao != 0);
}