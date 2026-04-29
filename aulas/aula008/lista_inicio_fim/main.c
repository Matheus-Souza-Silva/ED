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
    Item * Fim; // Referência para o último elemento da lista
} Lista;

Item * CriarItem(char * Titulo, char * Autor, int Ano);
Lista * CriarLista();
void ExibirLista(Lista * I);

int main() {

    system ("cls");

    // Reservando memória para as músicas

    Item * D = CriarItem("Aquarela", "Toquinho", 1983);
    Item * E = CriarItem("Romaria", "Renato Teixeira", 1978);
    Item * F = CriarItem("Eu nasci ha dez mil anos atras", "Raul Seixas", 1976);
    Item * G = CriarItem("Calice", "Chico Buarque e Gilberto Gil", 1978);
    Item * H = CriarItem("Tempo Perdido", "Renato Russo", 1986);

    // Novo encadeamento (D -> E -> F -> G -> H)

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

    // Inserindo nova música no encadeamento logo após a música "Cálice"

    Item * I = CriarItem("E", "Gonzaguinha", 1990);

    G->Proximo = I;

    I->Anterior = G;
    I->Proximo = H;

    H->Anterior = I;

    Item * J = CriarItem("Velha infancia", "Nando Reis", 2002);

    H->Proximo = J;
    J->Anterior = H;
    J->Proximo = NULL;

    Item * K = CriarItem("O mundo e um moinho", "Cartola", 1962);

    D->Anterior = K;
    K->Proximo = D;
    K->Anterior = NULL;

    // Criando uma Lista para armazenar as músicas

    Lista * Playlist = CriarLista();

    Playlist->Inicio = K;
    Playlist->Fim = J;
    Playlist->Tamanho = 8;

    // Exibindo todos os elementos da lista

    ExibirLista(Playlist);

    // Como acessar o 3º elemento da lista a partir da variável Playlist?

    // Item * Atual = Playlist->Inicio; // Atual = D
    // Atual = Atual->Proximo; // Atual passa a apontar para o 2º item
    // Atual = Atual->Proximo; // Atual passa a apontar para o 3º item

    // printf("\n%s\n",Atual->Titulo);

    // Alternativamente

    // printf("%s \n",Playlist->Inicio->Proximo->Proximo);

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

void ExibirLista(Lista * I) {
    Item * Atual = I->Inicio; // Atual aponta para o primeiro elemento da lista

    while(Atual != NULL) { 
        printf("%x \t %s \n", Atual, Atual->Titulo);
        Atual = Atual->Proximo; // A exibição vai começar pelo último item da lista
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
    L->Fim = NULL;

    return L;
}