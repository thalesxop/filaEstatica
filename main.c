#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

int main(void)
{
    TFila filaTeste;
    
    //Primeiro Teste
    printf("Primeiro teste\n");
    printf("\nFila Declarada\n");
    
    criarFila(4, &filaTeste);
    
    printf("\nFila Criada e Inicializada\n");
    dadosDaFila(&filaTeste);
    
    char *str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);

    //Segundo teste
    printf("Segundo teste\n");
    enfileirar(105, &filaTeste);
    enfileirar(205, &filaTeste);
    enfileirar(305, &filaTeste);
    enfileirar(405, &filaTeste);
    
    printf("Fila esta cheia? %d\n", filaEstaCheia(&filaTeste));
    
    enfileirar(505, &filaTeste);
    
    printf("\nFila com dados incluidos\n");
    dadosDaFila(&filaTeste);
    
    str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);    
    
    dadosDaFila(&filaTeste);

    //Apagando dados da Fila
    printf("\nApagando dados da Fila\n");
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);
    desenfileirar(&filaTeste);
    
    enfileirar(550, &filaTeste);
    enfileirar(660, &filaTeste);
    
    str = mostrarFila(&filaTeste);
    printf("\n%s\n", str);
    free(str);  
    
    printf("\nFila com dados incluidos/excluidos\n");
    dadosDaFila(&filaTeste);

    liberarFila(&filaTeste);

    printf("\nProcesso concluido.");
    getchar(); 

    return 0;
}