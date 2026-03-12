#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

typedef struct {
    int *vetorDados;
    int capacidadeMaxima;
    int quantidadeElementos;
    int indiceInicio;
    int indiceFim;
} TFila;

/*=========================================================
    Função que cria e inicializa uma fila
    Parametros: 
      1 - tamanho - define a quantidade de elementos
      2 - fila - ponteiro para a struct da fila
  =========================================================*/
void criarFila(int tamanho, TFila *const fila);

/*=========================================================
    Função que libera o espaco de memória usado pela fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void liberarFila(TFila *const fila);

/*=========================================================
    Função que verifica se a fila esta vazia
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      != 0 - fila esta vazia
      0    - fila não esta vazia
  =========================================================*/
int filaEstaVazia(TFila const *const fila);

/*=========================================================
    Função que verifica se a fila esta cheia
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      != 0 - fila esta cheia
      0    - fila não esta cheia
  =========================================================*/
int filaEstaCheia(TFila const *const fila);

/*=========================================================
    Função para incluir um elemento na fila
    Parametros: 
      1 - elemento - valor a ser inserido
      2 - fila - ponteiro para a struct da fila
  =========================================================*/
void enfileirar(int elemento, TFila *const fila);

/*=========================================================
    Função para retirar um elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void desenfileirar(TFila *const fila);

/*=========================================================
    Função para acessar o primeiro elemento da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      elemento do inicio da fila
  =========================================================*/
int acessar(TFila const *const fila);

/*=========================================================
    Função para gerar uma string com os dados da fila
    Parametros: 
      1 - fila - ponteiro para a struct da fila
    Retorno:
      ponteiro para a string gerada
  =========================================================*/
char* mostrarFila(TFila const *const fila);

/*=========================================================
    Função que mostra os dados internos da struct
    Parametros: 
      1 - fila - ponteiro para a struct da fila
  =========================================================*/
void dadosDaFila(TFila const * const fila);

#endif