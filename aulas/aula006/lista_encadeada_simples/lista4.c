#include <stdio.h>
#include <stdlib.h>

// Definindo cada item de uma lista ENCADEADA

typedef struct Item{
    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;
} Item;

Item * CriarItem(int Chave);
void ExibirLista(Item * I);

// Utilizando a estrutura para criar um novo item

int main() {
    system("cls");

    Item * A = CriarItem(25);
    Item * B = CriarItem(36);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);

    // Construindo o encadeamento A -> C -> D -> B

    A->Proximo = C;
    C->Proximo = D;
    D->Proximo = B;

    ExibirLista(A);

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

void ExibirLista(Item * I) {

    Item * Atual = I; // Atual aponta para o inicio da lista (I)

    printf("\n");

    while(Atual != NULL){ // Essa função pode ser criada tanto com for quanto com while
        printf("%X \t %d \t %X \n", Atual, Atual->Chave, Atual->Proximo);
        Atual = Atual->Proximo; // Avançar para a proxima posição da lista
    }
}