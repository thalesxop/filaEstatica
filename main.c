#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FilaEstatica.h"

int main() {
    TFila minhaFila;
    int i, valorAleatorio;
    int capacidade = 10;

    /* Semente para gerar numeros diferentes a cada execucao */
    srand(time(NULL));

    criarFila(capacidade, &minhaFila);

    /* Preenchimento da fila com valores aleatorios entre 0 e 99 */
    for (i = 0; i < capacidade; i++) {
        valorAleatorio = rand() % 100;
        enfileirar(valorAleatorio, &minhaFila);
    }

    char* strFila = mostrarFila(&minhaFila);
    printf("Fila Aleatoria: [ %s]\n", strFila);
    free(strFila);

    liberarFila(&minhaFila);

    return 0;
}