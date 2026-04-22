#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo cada Item de uma lista duplamente encadeada

typedef struct Item{
    char Time[20];
    struct Item * Anterior; // Endereço de memoria para o item anterior
    struct Item * Proximo; // Endereço de memoria para o proximo item da lista
} Item;

Item * CriarItem(char * Time);
void ExibirLista(Item * I);

int main () {
    system("cls");

    // Criando os Itens (nós), 

    Item * N1 = CriarItem("Real Madrid");
    Item * N2 = CriarItem("Roma");
    Item * N3 = CriarItem("Barcelona");
    Item * N4 = CriarItem("Bayer");
    Item * N5 = CriarItem("Chelsea");

    N1->Anterior = N4;
    N1->Proximo = N2;

    N2->Anterior = N1;
    N2->Proximo = NULL; // N2 é o último time da lista

    N3->Anterior = NULL; // N3 é o primeiro time da lista
    N3->Proximo = N5;

    N4->Anterior = N5;
    N4->Proximo = N1;

    N5->Anterior = N3;
    N5->Proximo = N4;

    ExibirLista(N3);
    return 0;
}

Item * CriarItem(char * Time) {
    Item * I = (Item *) malloc(sizeof(Item));

    if (I == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o item\n");
        return NULL;
    }

    strcpy(I->Time, Time); // Copiando Time em I->Time
    I->Anterior = NULL;
    I->Proximo = NULL;

    return I;
}

void ExibirLista(Item * I) {
    Item * Atual = I;

    printf("\n");

    while(Atual != NULL){
        printf("%s\n", Atual->Time);
        Atual = Atual->Proximo; // Avançar para a próxima posição
    }
}