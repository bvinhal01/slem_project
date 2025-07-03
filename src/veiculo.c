#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para system("clear") ou system("cls")

#include "../include/veiculo.h"
#include "../include/utilitarios.h"
#include "../include/local.h" // Para usar buscarLocalPorNome

// Função para buscar um veículo pela placa
// Retorna o índice do veículo no vetor ou -1 se não encontrado
int buscarVeiculoPorPlaca(Veiculo veiculos[], int totalVeiculos, const char *placa) {
    for (int i = 0; i < totalVeiculos; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
            return i;
        }
    }
    return -1; // Veículo não encontrado
}

// Implementação das funções de CRUD para Veiculo

void criarVeiculo(Veiculos veiculos[], int *totalVeiculos, Local locais[], int totalLocais) {
    if (*totalVeiculos >= MAX_ENTIDADES) {
        printf("Limite maximo de veiculos atingido!\n");
        return;
    }

    Veiculo novoVeiculo;
    char placaTemp[MAX_PLACA_VEICULO];
    char localNomeTemp[MAX_NOME_LOCAL];

    printf("\n--- CADASTRAR NOVO VEICULO ---\n");
    printf("Placa do Veiculo (Max %d caracteres): ", MAX_PLACA_VEICULO - 1);
    fgets(placaTemp, MAX_PLACA_VEICULO, stdin);
    placaTemp[strcspn(placaTemp, "\n")] = '\0';

    if (buscarVeiculoPorPlaca(veiculos, *totalVeiculos, placaTemp) != -1) {
        printf("ERRO: Ja existe um veiculo com esta placa.\n");
        return;
    }

    strcpy(novoVeiculo.placa, placaTemp);

    printf("Modelo do Veiculo (Max %d caracteres): ", MAX_MODELO_VEICULO - 1);
    fgets(novoVeiculo.modelo, MAX_MODELO_VEICULO, stdin);
    novoVeiculo.modelo[strcspn(novoVeiculo.modelo, "\n")] = '\0';

    // Status inicial: Disponível
    novoVeiculo.status = 0; // 0 = Disponível

    printf("Nome do Local Atual do Veiculo: ");
    fgets(localNomeTemp, MAX_NOME_LOCAL, stdin);
    localNomeTemp[strcspn(localNomeTemp, "\n")] = '\0';

    if (buscarLocalPorNome(locais, totalLocais, localNomeTemp) == -1) {
        printf("ERRO: Local '%s' nao encontrado. O veiculo deve estar em um local existente.\n", localNomeTemp);
        return;
    }
    strcpy(novoVeiculo.localAtualNome, localNomeTemp);

    veiculos[*totalVeiculos] = novoVeiculo;
    (*totalVeiculos)++;
    printf("Veiculo com placa '%s' cadastrado com sucesso!\n", novoVeiculo.placa);
}

void listarVeiculos(Veiculo veiculos[], int totalVeiculos) {
    printf("\n--- VEICULOS CADASTRADOS ---\n");
    if (totalVeiculos == 0) {
        printf("Nenhum veiculo cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalVeiculos; i++) {
        printf("Placa: %s | Modelo: %s | Status: %s | Local Atual: %s\n",
               veiculos[i].placa, veiculos[i].modelo,
               (veiculos[i].status == 0 ? "Disponivel" : "Ocupado"),
               veiculos[i].localAtualNome);
    }
}

void atualizarVeiculo(Veiculo veiculos[], int totalVeiculos, Local locais[], int totalLocais) {
    char placaBusca[MAX_PLACA_VEICULO];
    char novoLocalNome[MAX_NOME_LOCAL];
    int novoStatus;

    printf("\n--- ATUALIZAR VEICULO ---\n");
    printf("Digite a placa do veiculo que deseja atualizar: ");
    fgets(placaBusca, MAX_PLACA_VEICULO, stdin);
    placaBusca[strcspn(placaBusca, "\n")] = '\0';

    int indice = buscarVeiculoPorPlaca(veiculos, totalVeiculos, placaBusca);

    if (indice != -1) {
        printf("Veiculo encontrado: Placa: %s | Modelo: %s | Status: %s | Local: %s\n",
               veiculos[indice].placa, veiculos[indice].modelo,
               (veiculos[indice].status == 0 ? "Disponivel" : "Ocupado"),
               veiculos[indice].localAtualNome);

        printf("\nNovas informacoes (deixe em branco para manter a atual):\n");

        printf("Novo Modelo (atual: %s): ", veiculos[indice].modelo);
        char modeloTemp[MAX_MODELO_VEICULO];
        fgets(modeloTemp, MAX_MODELO_VEICULO, stdin);
        modeloTemp[strcspn(modeloTemp, "\n")] = '\0';
        if (strlen(modeloTemp) > 0) {
            strcpy(veiculos[indice].modelo, modeloTemp);
        }

        printf("Novo Status (0=Disponivel, 1=Ocupado) (atual: %d): ", veiculos[indice].status);
        char statusStr[5];
        fgets(statusStr, sizeof(statusStr), stdin);
        statusStr[strcspn(statusStr, "\n")] = '\0';
        if (strlen(statusStr) > 0) {
            if (sscanf(statusStr, "%d", &novoStatus) == 1 && (novoStatus == 0 || novoStatus == 1)) {
                veiculos[indice].status = novoStatus;
            } else {
                printf("Status invalido. Mantendo o status atual.\n");
            }
        }

        printf("Novo Local Atual (atual: %s): ", veiculos[indice].localAtualNome);
        fgets(novoLocalNome, MAX_NOME_LOCAL, stdin);
        novoLocalNome[strcspn(novoLocalNome, "\n")] = '\0';
        if (strlen(novoLocalNome) > 0) {
            if (buscarLocalPorNome(locais, totalLocais, novoLocalNome) != -1) {
                strcpy(veiculos[indice].localAtualNome, novoLocalNome);
            } else {
                printf("Local '%s' nao encontrado. Mantendo o local atual.\n", novoLocalNome);
            }
        }

        printf("Veiculo com placa '%s' atualizado com sucesso!\n", veiculos[indice].placa);
    } else {
        printf("Veiculo com placa '%s' nao encontrado.\n", placaBusca);
    }
}


void excluirVeiculo(Veiculo veiculos[], int *totalVeiculos) {
    char placaBusca[MAX_PLACA_VEICULO];
    printf("\n--- EXCLUIR VEICULO ---\n");
    printf("Digite a placa do veiculo que deseja excluir: ");
    fgets(placaBusca, MAX_PLACA_VEICULO, stdin);
    placaBusca[strcspn(placaBusca, "\n")] = '\0';

    int indice = buscarVeiculoPorPlaca(veiculos, *totalVeiculos, placaBusca);

    if (indice != -1) {
        // Move os elementos seguintes uma posição para trás
        for (int i = indice; i < (*totalVeiculos - 1); i++) {
            veiculos[i] = veiculos[i + 1];
        }
        (*totalVeiculos)--;
        printf("Veiculo com placa '%s' excluido com sucesso!\n", placaBusca);
    } else {
        printf("Veiculo com placa '%s' nao encontrado.\n", placaBusca);
    }
}