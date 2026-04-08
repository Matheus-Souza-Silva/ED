#include <stdio.h>
#include <stdlib.h>

// Definindo cada item de uma lista ENCADEADA

typedef struct Item{
    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;
} Item;

typedef struct {
    int Tamanho;
    Item * Inicio;
} Lista;

Item * CriarItem(int Chave);
Lista * CriarLista();
void InserirItem(Lista * L, Item * I, int Posicao);

// Utilizando a estrutura para criar um novo item

int main() {
    system("cls");

    Lista * M = CriarLista();

    InserirItem(M, CriarItem(25), 0);
    InserirItem(M, CriarItem(36), 1);
    InserirItem(M, CriarItem(40), 2);
    InserirItem(M, CriarItem(10), 3);

    return 0;
}

Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc(sizeof(Item));

    if(I == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o item");
        return NULL; // Tambem pode ser exit(1)
    }

    I->Chave = Chave;
    I->Proximo = NULL; // Não existe item depois do I

    printf("%X \t %d \t %X \n", I, I->Chave, I->Proximo);

    return I;
}

Lista * CriarLista() {
    Lista * L = (Lista *) malloc(sizeof(Lista));

    if(L == NULL){
        printf("ERRO");
        return NULL;
    }

    printf("A lista esta armazenada no endereco %X.\n", L);

    L->Tamanho = 0;
    L->Inicio = NULL;

    return L;
}

void InserirItem(Lista * L, Item * I, int Posicao) {

    if(Posicao < 0 || Posicao > L->Tamanho){
        printf("ERRO: Posicao na lista invalida");
        return ;
    }

    if(Posicao == 0){
        I->Proximo = L->Inicio;
        L->Inicio = I;
    } else{
        Item * Atual = L->Inicio;
        for(int i = 0; i < Posicao - 1; i++) Atual = Atual->Proximo;
        I->Proximo = Atual->Proximo;
        Atual->Proximo = I;
    }

    L->Tamanho++;
}