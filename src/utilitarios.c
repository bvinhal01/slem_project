#include <stdio.h>
#include <string.h> // Para strcspn, strlen
#include <math.h>   // Para sqrtf, powf
#include <stdlib.h> // Para system

#include "../include/utilitarios.h"

// Limpa o buffer de entrada para evitar problemas com fgets após scanf
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Calcula a distância euclidiana entre dois pontos (x1, y1) e (x2, y2)
float calculaDistanciaEuclidiana(float x1, float y1, float x2, float y2) {
    return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2));
}

// Limpa a tela do console (funciona em Windows e sistemas baseados em Unix)
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}