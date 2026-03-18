#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "equipe.h"

Equipe * lerDados(char * Arquivo){
    FILE * fp = fopen(Arquivo, "r");

    if(fp == NULL){
        printf("ERRO: Não foi possivel abrir o arquivo!");
        exit(1);
    }

    Equipe * X = malloc(20 * sizeof(Equipe)); // Vetor X de 20 elementos: X[0]

    if(X == NULL){
        printf("ERRO: Nao foi possivel alocar memoria para o conjunto!\n");
        exit(1);
    }

    char Buffer[100];
    fscanf(fp, "%s", Buffer); // Para "Pular" a linha dos cabeçalhos

    int N = 0; // Indice do Vetor

    // Pos;Estado;Equipe;Pts;J;V;E;D;GP;GC;SG

    while(fscanf(fp, "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d\n",
            &X[N].Posicao,
            X[N].Estado, // E sring, nao colocar o "&"
            X[N].Time, // E sring, nao colocar o "&"
            &X[N].Pontos,
            &X[N].J,
            &X[N].V,
            &X[N].E,
            &X[N].D,
            &X[N].GP,
            &X[N].GC,
            &X[N].SG) == 11){
        X[N].Aproveitamento = 100.0 * X[N].Pontos / (3.0 * X[N].J);
        N++;
    }

    fclose(fp);

    return X;
}

int getGP(Equipe * V, char * Time){

    for(int i = 0; i < 20; i++){
        if(strcmp(Time, V[i].Time) == 0){
            return V[i].GP;
        }
    }

    return -999;
}

// Procedimento para configurar a acentuacao

void configurarAcentuacao() {
#ifdef _WIN32
	// Habilita suporte a UTF-8 no console do Windows
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Configura locale para UTF-8
	setlocale(LC_ALL, ".UTF8");
#else
	// Para Linux/Mac, configura locale para UTF-8
	setlocale(LC_ALL, "");
#endif
}