#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 43

int main() {

    system("cls");

    FILE * fp = fopen("bloco.txt", "r");

    if (fp == NULL){
        printf("ERRO ao abrir o arquivo!");
        exit(1);
    }

    int numero;
    char nome[50];

    for(int i = 0; i < 3; i++){
        fscanf(fp, "%d %[^\n]", &numero, nome);
        printf("%d) %d %s \n", i + 1, numero, nome);
    }

    // for(int i = 1; i <= 10; i++) {
    //     fprintf(fp, "%d * %d = %d\n", NUM, i, NUM * i);
    // }

    fclose(fp);
    
    return 0;
}

/*
Comando para compilar o codigo
    gcc main.c -o main.exe

Comando para executar o codigo
    ./main

Comando para Terminal Windows
    cls - limpar terminal
    dir - mostrar informacoes dos arquivos dentro do diretorio
    del - deletar
    mkdir e md - criar uma pasta no diretorio
    rmdir e rm - remover uma pasta no diretorio
    
Comandos para manipulação de Arquivos
    FILE * - Criar um ponteiro do tipo arquivo
    *ponteiro* = fopen("nome", forma de abrir)
*/