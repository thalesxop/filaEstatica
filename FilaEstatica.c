#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

/*=========================================================
    Função que mostra os dados da struct de uma fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila){
    printf("Capacidade Maxima: %d\n", fila->capacidadeMaxima);
    printf("Quantidade de Elementos: %d\n", fila->quantidadeElementos);
    printf("Indice do Inicio: %d\n", fila->indiceInicio);
    printf("Indice do Fim: %d\n", fila->indiceFim);
}

/*=========================================================
    Função que cria e inicializa uma fila
    Parametros: 
      1 - tamanho - define a quantidade de elementos
      2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila){
    fila->capacidadeMaxima = tamanho;
    fila->quantidadeElementos = 0;
    fila->indiceInicio = 0;
    fila->indiceFim = -1;
    fila->vetorDados = malloc(tamanho * sizeof(int));
}

/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void liberarFila(TFila *const fila){
    if (fila->vetorDados != NULL) {
        free(fila->vetorDados);
        fila->vetorDados = NULL;
    }
    fila->capacidadeMaxima = 0;
    fila->quantidadeElementos = 0;
    fila->indiceInicio = 0;
    fila->indiceFim = -1;
}

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
      1 - fila esta vazia
      0 - fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila){
    if (fila->quantidadeElementos == 0) return 1;
    return 0;
}

/*=========================================================
    Função que verifica se a fila esta cheia
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
      1 - fila esta cheia
      0 - fila não esta cheia
  =========================================================*/
int filaEstaCheia(TFila const *const fila){
    if (fila->quantidadeElementos == fila->capacidadeMaxima) return 1;
    return 0;
}

/*=========================================================
    Função para gerar uma string com os dados da fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
      ponteiro para a string com os dados da fila
  =========================================================*/
char* mostrarFila(TFila const *const fila){
    if (filaEstaVazia(fila)) return "Fila Vazia";

    /* Aloca espaco para a string (estimativa de 12 caracteres por numero) */
    char* resultado = (char*) malloc(fila->quantidadeElementos * 12 * sizeof(char));
    resultado[0] = '\0';

    int i;
    for (i = 0; i < fila->quantidadeElementos; i++) {
        int posicaoAtual = fila->indiceInicio + i;
        
        /* Ajuste circular manual */
        if (posicaoAtual >= fila->capacidadeMaxima) {
            posicaoAtual = posicaoAtual - fila->capacidadeMaxima;
        }

        char buffer[12];
        sprintf(buffer, "%d ", fila->vetorDados[posicaoAtual]);
        strcat(resultado, buffer);
    }
    return resultado;
}

/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
      1 - elemento - valor a ser incluido na fila
      2 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila){
    if (filaEstaCheia(fila)) return;

    fila->indiceFim++;

    /* Se o indice estourar a capacidade, volta para o inicio */
    if (fila->indiceFim >= fila->capacidadeMaxima) {
        fila->indiceFim = 0;
    }

    fila->vetorDados[fila->indiceFim] = elemento;
    fila->quantidadeElementos++;
}

/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
  =========================================================*/
void desenfileirar(TFila *const fila){
    if (filaEstaVazia(fila)) return;

    fila->indiceInicio++;

    /* Se o indice estourar a capacidade, volta para o inicio */
    if (fila->indiceInicio >= fila->capacidadeMaxima) {
        fila->indiceInicio = 0;
    }

    fila->quantidadeElementos--;

    /* Reseta os indices caso a fila fique vazia */
    if (filaEstaVazia(fila)) {
        fila->indiceInicio = 0;
        fila->indiceFim = -1;
    }
}

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct com os dados da fila
    Retorno:
      elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila){
    if (filaEstaVazia(fila)) return -1;
    return fila->vetorDados[fila->indiceInicio];
}