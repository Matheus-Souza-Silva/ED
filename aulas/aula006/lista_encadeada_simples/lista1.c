#include <stdio.h>
#include <stdlib.h>

// Definindo cada item de uma lista ENCADEADA

typedef struct Item{
    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;
} Item;

// Utilizando a estrutura para criar um novo item

int main() {
    system("cls");

    Item * A = (Item *) malloc (sizeof(Item));

    if(A == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o item");
        exit(1);
    }

    A->Chave = 25;
    A->Proximo = NULL;

    printf("%X \t %d \t %X", A, A->Chave, A->Proximo); // %X mostra o hexadecimal correspondente

    return 0;
}