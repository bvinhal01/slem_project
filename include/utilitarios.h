#ifndef UTILITARIOS_H
#define UTILITARIOS_H

// Constantes de tamanho máximo para strings e vetores
#define MAX_NOME_LOCAL 50
#define MAX_PLACA_VEICULO 10
#define MAX_MODELO_VEICULO 30
#define MAX_ENTIDADES 100 // Número máximo de locais, veículos ou pedidos

// Protótipos das funções utilitárias
void limparBufferEntrada();
float calculaDistanciaEuclidiana(float x1, float y1, float x2, float y2);
void limparTela();

#endif // UTILITARIOS_H