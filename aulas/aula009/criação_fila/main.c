#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3 // Usando uma constante para simplificar a quantidade de elementos do vetor

// Implementar uma FILA usando ARRAY (vetor)

typedef struct {
    int Chave;
} Item;

typedef struct {
    Item * Dados; // Ponteiro de Itens
    int Inicio; // Índice do primeiro item
    int Fim; // Índice onde o próximo item será inserido
    int Tamanho; // Quantidades de elementos atualmente na fila
    int Capacidade; // Capacidade total da fila
} Fila;

Item CriarItem(int Chave);
Fila * CriarFila(int Capacidade);
void DestruirFila(Fila * F);
void Enfileirar(Fila * F, Item I);
void Desenfileirar(Fila * F);
void ExibirFila(Fila * F);

int main() {
    system("cls");

    // Criando uma Fila com capacidade 10

    Fila * Exemplo = CriarFila(10);

    // Inserindo 4 elementos na fila

    Enfileirar(Exemplo, CriarItem(10));
    Enfileirar(Exemplo, CriarItem(20));
    Enfileirar(Exemplo, CriarItem(30));
    Enfileirar(Exemplo, CriarItem(40));

    ExibirFila(Exemplo);
    Desenfileirar(Exemplo);
    ExibirFila(Exemplo);

    return 0;
}

Item CriarItem(int Chave) {
    Item I;
    I.Chave = Chave;
    return I;
}

Fila * CriarFila(int Capacidade){
    Fila * F = (Fila *) malloc(sizeof(Fila));

    if(F == NULL) return NULL;

    F->Capacidade = Capacidade;
    F->Tamanho = 0;
    F->Inicio = -1;
    F->Fim = -1;
    F->Dados = (Item *) malloc(Capacidade * sizeof(Item));

    if(F->Dados == NULL) {
        free(F); // Liberando memória da estrutura da lista
        return NULL;
    }

    return F;
}

void DestruirFila(Fila * F){
    if (F == NULL) return;
    free(F->Dados);
    free(F);
}

void Enfileirar(Fila * F, Item I){
    if(F->Fim == F->Capacidade - 1) return; // Overflow
    if(F->Inicio == -1) F->Inicio = 0;

    F->Fim = F->Fim + 1;
    F->Dados[F->Fim] = I;
    F->Tamanho++;
}

void ExibirFila(Fila * F){
    printf("Fila: \t");
    
    for(int i = F->Inicio; i <= F->Fim; i++) {
        printf("%d \t", F->Dados[i].Chave);
    }

    printf("\n");
}

void Desenfileirar(Fila * F){
    if(F->Tamanho == 0) return; // Para evitar o Underflow
    F->Inicio = F->Inicio + 1;
    F->Tamanho--;
}