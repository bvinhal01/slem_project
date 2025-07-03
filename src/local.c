#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para system("clear") ou system("cls")

#include "../include/local.h"
#include "../include/utilitarios.h" // Para limparBufferEntrada

// Função para buscar um local pelo nome
// Retorna o índice do local no vetor ou -1 se não encontrado
int buscarLocalPorNome(Local locais[], int totalLocais, const char *nome) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(locais[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1; // Local não encontrado
}

// Implementação das funções de CRUD para Local

void criarLocal(Local locais[], int *totalLocais) {
    if (*totalLocais >= MAX_ENTIDADES) {
        printf("Limite maximo de locais atingido!\n");
        return;
    }

    Local novoLocal;
    char nomeTemp[MAX_NOME_LOCAL];

    printf("\n--- CADASTRAR NOVO LOCAL ---\n");
    printf("Nome do Local (Max %d caracteres): ", MAX_NOME_LOCAL - 1);
    fgets(nomeTemp, MAX_NOME_LOCAL, stdin);
    nomeTemp[strcspn(nomeTemp, "\n")] = '\0'; // Remove o \n

    if (buscarLocalPorNome(locais, *totalLocais, nomeTemp) != -1) {
        printf("ERRO: Ja existe um local com este nome.\n");
        return;
    }

    strcpy(novoLocal.nome, nomeTemp);

    printf("Coordenada X: ");
    scanf("%f", &novoLocal.coordX);
    printf("Coordenada Y: ");
    scanf("%f", &novoLocal.coordY);
    limparBufferEntrada(); // Limpa o buffer após scanf

    locais[*totalLocais] = novoLocal;
    (*totalLocais)++;
    printf("Local '%s' cadastrado com sucesso!\n", novoLocal.nome);
}

void listarLocais(Local locais[], int totalLocais) {
    printf("\n--- LOCAIS CADASTRADOS ---\n");
    if (totalLocais == 0) {
        printf("Nenhum local cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalLocais; i++) {
        printf("Nome: %s | Coordenadas: (%.2f, %.2f)\n",
               locais[i].nome, locais[i].coordX, locais[i].coordY);
    }
}

void atualizarLocal(Local locais[], int totalLocais) {
    char nomeBusca[MAX_NOME_LOCAL];
    printf("\n--- ATUALIZAR LOCAL ---\n");
    printf("Digite o nome do local que deseja atualizar: ");
    fgets(nomeBusca, MAX_NOME_LOCAL, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int indice = buscarLocalPorNome(locais, totalLocais, nomeBusca);

    if (indice != -1) {
        printf("Local encontrado: Nome: %s | Coordenadas: (%.2f, %.2f)\n",
               locais[indice].nome, locais[indice].coordX, locais[indice].coordY);

        printf("\nNovas coordenadas (deixe 0 para manter a atual):\n");
        float newX, newY;
        char input[100]; // Para ler as novas coordenadas como string

        printf("Nova Coordenada X (atual: %.2f): ", locais[indice].coordX);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) > 0) { // Se algo foi digitado
            if (sscanf(input, "%f", &newX) == 1) { // Tenta converter para float
                locais[indice].coordX = newX;
            } else {
                printf("Entrada invalida. Mantendo a coordenada X atual.\n");
            }
        }

        printf("Nova Coordenada Y (atual: %.2f): ", locais[indice].coordY);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) > 0) {
            if (sscanf(input, "%f", &newY) == 1) {
                locais[indice].coordY = newY;
            } else {
                printf("Entrada invalida. Mantendo a coordenada Y atual.\n");
            }
        }

        printf("Local '%s' atualizado com sucesso!\n", locais[indice].nome);
    } else {
        printf("Local '%s' nao encontrado.\n", nomeBusca);
    }
}

void excluirLocal(Local locais[], int *totalLocais) {
    char nomeBusca[MAX_NOME_LOCAL];
    printf("\n--- EXCLUIR LOCAL ---\n");
    printf("Digite o nome do local que deseja excluir: ");
    fgets(nomeBusca, MAX_NOME_LOCAL, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int indice = buscarLocalPorNome(locais, *totalLocais, nomeBusca);

    if (indice != -1) {
        // Move os elementos seguintes uma posição para trás
        for (int i = indice; i < (*totalLocais - 1); i++) {
            locais[i] = locais[i + 1];
        }
        (*totalLocais)--;
        printf("Local '%s' excluido com sucesso!\n", nomeBusca);
    } else {
        printf("Local '%s' nao encontrado.\n", nomeBusca);
    }
}