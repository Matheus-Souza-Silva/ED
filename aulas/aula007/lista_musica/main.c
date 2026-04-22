#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo cada Item de uma lista duplamente encadeada

typedef struct Item{
    char Titulo[50];
    char Autor[100];
    int Ano;
    struct Item * Anterior; // Endereço de memoria para o item anterior
    struct Item * Proximo; // Endereço de memoria para o proximo item da lista
} Item;

typedef Item Musica; // Se quiser "trocar" o nome do tipo para "musica"

int main () {
    system("cls");

    // Reservando memória para uma música

    Musica * D = (Musica *) malloc(sizeof(Musica));

    if(D == NULL){
        printf("ERRO: Nao ha memoria para mais uma musica!\n");
        exit(1);
    }

    strcpy(D->Titulo, "Aquarela");
    strcpy(D->Autor, "Toquinho");
    D->Ano = 1983;
    D->Anterior = NULL;
    D->Proximo = NULL;

    Musica * E = (Musica *) malloc(sizeof(Musica));

    if(E == NULL){
        printf("ERRO: Nao ha memoria para mais uma musica!\n");
        exit(1);
    }

    strcpy(E->Titulo, "Romaria");
    strcpy(E->Autor, "Renato Texeira");
    E->Ano = 1978;
    E->Anterior = NULL;
    E->Proximo = NULL;

    Musica * F = (Musica *) malloc(sizeof(Musica));

    if(F == NULL){
        printf("ERRO: Nao ha memoria para mais uma musica!\n");
        exit(1);
    }

    strcpy(F->Titulo, "Eu nasci ha dez mil anos atras");
    strcpy(F->Autor, "Raul Seixas");
    F->Ano = 1976;
    F->Anterior = NULL;
    F->Proximo = NULL;

    Musica * G = (Musica *) malloc(sizeof(Musica));

    if(G == NULL){
        printf("ERRO: Nao ha memoria para mais uma musica!\n");
        exit(1);
    }

    strcpy(G->Titulo, "Calice");
    strcpy(G->Autor, "Chico Buarque e Gilberto Gil");
    G->Ano = 1978;
    G->Anterior = NULL;
    G->Proximo = NULL;

    Musica * H = (Musica *) malloc(sizeof(Musica));

    if(H == NULL){
        printf("ERRO: Nao ha memoria para mais uma musica!\n");
        exit(1);
    }

    strcpy(H->Titulo, "Tempo Perdido");
    strcpy(H->Autor, "Renato Russo");
    H->Ano = 1986;
    H->Anterior = NULL;
    H->Proximo = NULL;

    D->Anterior = NULL;
    D->Proximo = E;
    
    E->Anterior = D;
    E->Proximo = F;

    F->Anterior = E;
    F->Proximo = G;

    G->Anterior = F;
    G->Proximo = H;

    H->Anterior = G;
    H->Proximo = NULL;
    
    Musica * Atual = D;

    printf("\n");

    while(Atual != NULL) {
        printf("%s | %s | %d \n", Atual->Titulo, Atual->Autor, Atual->Ano);
        Atual = Atual->Proximo;
    }

    return 0;
}