#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char Titulo[50];
    char Autor[100];
    int Ano;
    struct Item * Anterior;
    struct Item * Proximo;
} Item;

typedef Item Musica;

// Definindo a estrutura da Lista (duplamente encadeada)

typedef struct Lista{
    int Tamanho; // E qualquer outra informação relevante
    Item * Inicio; // Endereço de memória (uo referência) para o primeiro elemento da lista
} Lista;

Item * CriarItem(char * Titulo, char * Autor, int Ano);
Lista * CriarLista();
void ExibirLista(Item * I);

int main() {

    system ("cls");

    // Reservando memória para as músicas

    Item * D = CriarItem("Aquarela", "Toquinho", 1983);
    Item * E = CriarItem("Romaria", "Renato Teixeira", 1978);
    Item * F = CriarItem("Eu nasci ha dez mil anos atras", "Raul Seixas", 1976);
    Item * G = CriarItem("Calice", "Chico Buarque e Gilberto Gil", 1978);
    Item * H = CriarItem("Tempo Perdido", "Renato Russo", 1986);

    // Construindo o encadeamento em ordem alfabetica (D -> G -> F -> E -> H)

    D->Anterior = NULL;
    D->Proximo = G;

    G->Anterior = D;
    G->Proximo = F;

    F->Anterior = G;
    F->Proximo = E;

    E->Anterior = F;
    E->Proximo = H;

    H->Anterior = E;
    H->Proximo = NULL;

    // Exibindo todos os elementos da lista

    ExibirLista(D);

    // Criando uma Lista para armazenar as músicas

    Lista * Playlist = CriarLista();

    Playlist->Inicio = D;
    Playlist->Tamanho = 5;

    // Como acessar o 3º elemento da lista a partir da variável Playlist?

    Item * Atual = Playlist->Inicio; // Atual = D
    Atual = Atual->Proximo; // Atual passa a apontar para o 2º item
    Atual = Atual->Proximo; // Atual passa a apontar para o 3º item

    printf("\n%s\n",Atual->Titulo);
    printf("%s \n",Playlist->Inicio->Proximo->Proximo);
    return 0;
}

Item * CriarItem(char * Titulo, char * Autor, int Ano) {
    Item * I = (Item *) malloc(sizeof(Item));

    if(I == NULL) {
        printf("ERRO: Nao foi possivel alocar memoria para o Item!\n");
        return NULL;
    }

    strcpy(I->Titulo, Titulo);
    strcpy(I->Autor, Autor);
    I->Ano = Ano;
    I->Anterior = NULL;
    I->Proximo = NULL;

    return I;
}

void ExibirLista(Item * I) {
    Item * Atual = I; // Atual aponta para o primeiro elemento da lista

    while(Atual != NULL) { 
        printf("%x \t %s \n", Atual, Atual->Titulo);
        Atual = Atual->Proximo;
    }
}

Lista * CriarLista() {
    Lista * L = (Lista *) malloc(sizeof(Lista));

    if(L == NULL){
        printf("ERRO: Nao existe memoria para armazenar a lista!\n");
        return NULL;
    }

    L->Tamanho = 0;
    L->Inicio = NULL;

    return L;
}