#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

/*=========================================================
    Função que mostra os dados internos da struct
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila) {
    printf("\nCapacidade da fila: %d | Itens: %d | Inicio: %d | Fim: %d\n", 
            fila->capacidadeMaxima, fila->quantidadeElementos, fila->indiceInicio, fila->indiceFim);
}

/*=========================================================
    Função que cria e inicializa uma fila
    Parametros: 
      1 - tamanho - define a quantidade de elementos
      2 - fila - ponteiro para a struct da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila) {
    fila->capacidadeMaxima = tamanho;
    fila->quantidadeElementos = 0;
    fila->indiceInicio = -1; // Ajustado para -1 conforme sua nova lógica
    fila->indiceFim = -1;
    fila->vetorDados = (int*) malloc(tamanho * sizeof(int));
}

/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void liberarFila(TFila *const fila) {
    if (fila->vetorDados != NULL) {
        free(fila->vetorDados);
        fila->vetorDados = NULL;
    }
    fila->capacidadeMaxima = 0;
    fila->quantidadeElementos = 0;
    fila->indiceInicio = -1;
    fila->indiceFim = -1;
}

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      != 0 - fila esta vazia
      0    - fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila) {
    return (fila->quantidadeElementos == 0);
}

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      != 0 - fila esta vazia
      0    - fila não esta vazia
  =========================================================*/
int filaEstaCheia(TFila const *const fila) {
    return (fila->quantidadeElementos == fila->capacidadeMaxima);
}

/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
      1 - elemento - valor a ser inserido
      2 - fila - ponteiro para a struct da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila) { 
    if(filaEstaCheia(fila)) {
        printf("Fila esta cheia\n");
        return;
    }
    
    if(fila->indiceInicio == -1) {
        fila->indiceInicio = 0;
    }
    
    fila->indiceFim++;
    
    if(fila->indiceFim >= fila->capacidadeMaxima) {
        fila->indiceFim = 0;
    }
    
    fila->vetorDados[fila->indiceFim] = elemento;
    fila->quantidadeElementos++;
}

/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void desenfileirar(TFila *const fila) {
    if (filaEstaVazia(fila)) {
        printf("Fila esta vazia\n");
        return;
    }
    
    fila->indiceInicio++;
    
    if(fila->indiceInicio >= fila->capacidadeMaxima) {
        fila->indiceInicio = 0;
    }
    
    fila->quantidadeElementos--;
    
    if (filaEstaVazia(fila)) {
        printf("Fila esta vazia\n"); 
        fila->indiceInicio = -1;
        fila->indiceFim = -1;
    }
}

/*=========================================================
    Função para gerar uma string com os dados da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      ponteiro para a string gerada
  =========================================================*/
char* mostrarFila(TFila const *const fila) {
    if (filaEstaVazia(fila)) {
        return strdup("Fila Vazia");
    }

    char* resultado = (char*) malloc(fila->quantidadeElementos * 15 * sizeof(char));
    resultado[0] = '\0';

    int i;
    for (i = 0; i < fila->quantidadeElementos; i++) {
        int posicaoAtual = (fila->indiceInicio + i) % fila->capacidadeMaxima;
        char buffer[15];
        sprintf(buffer, "%d ", fila->vetorDados[posicaoAtual]);
        strcat(resultado, buffer);
    }
    return resultado;
}

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila) {
    if (filaEstaVazia(fila)) return -1;
    return fila->vetorDados[fila->indiceInicio];
}