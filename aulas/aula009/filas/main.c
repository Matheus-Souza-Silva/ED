#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

// Implementar uma FILA usando ARRAY (vetor)

typedef struct {
    int Chave;
} Item;

Item CriarItem(int Chave);

int main() {
    system("cls");

    Item A = CriarItem(137);
    Item B = CriarItem(241);
    Item C = CriarItem(339);

    Item Vetor[TAM]; // Alocação ESTÁTICA

    Vetor[0] = A;
    Vetor[1] = B;
    Vetor[2] = C;

    for(int i = 0; i < TAM; i++) printf("%d \t", Vetor[i].Chave);
    
    return 0;
}

Item CriarItem(int Chave) {
    Item I;
    I.Chave = Chave;
    return I;
}