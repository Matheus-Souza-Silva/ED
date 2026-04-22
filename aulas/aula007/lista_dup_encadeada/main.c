#include <stdio.h>
#include <stdlib.h>

// Definindo cada Item de uma lista duplamente encadeada

typedef struct Item{
    int Chave; // Ou qualquer informação de interesse
    struct Item * Anterior; // Endereço de memoria para o item anterior
    struct Item * Proximo; // Endereço de memoria para o proximo item da lista
} Item;

Item * CriarItem(int Chave);

int main () {
    system("cls");

    Item * A = CriarItem(10);
    Item * B = CriarItem(20);
    Item * C = CriarItem(30);
    Item * D = CriarItem(40);
    Item * E = CriarItem(50);
    Item * F = CriarItem(60);

    A->Anterior = NULL;
    A->Proximo = B;

    B->Anterior = A;
    B->Proximo = C;

    C->Anterior = B;
    C->Proximo = D;

    D->Anterior = C;
    D->Proximo = E;

    E->Anterior = D;
    E->Proximo = F;

    F->Anterior = E;
    F->Proximo = NULL;

    // Acessando o Item B, a partir do Item D

    Item * Atual;

    Atual = D;
    Atual = Atual->Anterior; // Atual aponta para C
    Atual = Atual->Anterior; // Atual aponta para B

    printf("Atual apontando para o item com chave %d\n",Atual->Chave);
    printf("Outra solucao: %d\n", D->Anterior->Anterior->Chave);

    // Acessando o Item E, a partir do Item C

    Atual = C;
    Atual = Atual->Proximo; // Atual aponta para D;
    Atual = Atual->Proximo; // Atual aponta para E;

    printf("\nAtual apontando para o item com chave: %d\n", Atual->Chave);
    printf("Outra solucao: %d", C->Proximo->Proximo->Chave);

    

    return 0;
}

Item * CriarItem(int Chave) {
    Item * I = (Item *) malloc(sizeof(Item));

    if (I == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o item\n");
        return NULL;
    }

    I->Chave = Chave;
    I->Anterior = NULL;
    I->Proximo = NULL;

    return I;
}