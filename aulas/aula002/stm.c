#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    system("cls");

    FILE * in = fopen("STM.csv", "r");

    if(in == NULL){
        printf("ERRO: Não foi possivel abrir o arquivo!");
        exit(1);
    }

    int Cont = 0;

    // Saltando a primeira linha

    char Buffer[10000];
    fscanf(in, "%[^\n]\n", Buffer);

    while(fscanf(in, "%[^\n]\n", Buffer) == 1){
        Cont++;
    }

    printf("\nPessoas cadastradas na base de dados: %d", Cont);

    fclose(in);

    return 0;
}