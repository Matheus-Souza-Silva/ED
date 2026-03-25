#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    system("cls");

    FILE * in = fopen("dados.csv", "r");

    if(in == NULL){
        printf("ERRO: Não foi possivel abrir o arquivo!");
        exit(1);
    }

    int ID, Idade;
    int Cont = 0;
    char Nome[100];

    // Saltando a primeira linha

    char Buffer[100];
    fscanf(in, "%[^\n]\n", Buffer);

    while(fscanf(in, "%d,%[^,],%d\n", &ID, Nome, &Idade) == 3){
        printf("%d \t %s \t %d \n", ID, Nome, Idade);
        Cont++;
    }

    printf("\nPessoas cadastradas na base de dados: %d", Cont);

    fclose(in);

    return 0;
}