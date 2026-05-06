#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3 // Usando uma constante para simplificar a quantidade de elementos do vetor

// Implementar uma FILA usando ARRAY (vetor)

typedef struct {
    int Chave;
} Item;

Item CriarItem(int Chave);

// Simplificando a função principal (eliminando as variáveis A, B e C)

int main() {
    system("cls");

    Item * Vetor = (Item *) malloc(TAM * sizeof(Item)); // Alocação DINÂMICA

    Vetor[0] = CriarItem(137);
    Vetor[1] = CriarItem(241);
    Vetor[2] = CriarItem(339);

    // Exibindo o vetor de struct's

    for(int i = 0; i < TAM; i++) printf("%d \t", Vetor[i].Chave);
    
    return 0;
}

Item CriarItem(int Chave) {
    Item I;
    I.Chave = Chave;
    return I;
}