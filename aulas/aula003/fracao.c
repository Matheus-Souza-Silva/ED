#include <stdio.h>
#include <stdlib.h>

// Definicao dos DADOS do TAD Fracao

typedef struct {
    int Numerador;
    int Denominador;
} Fracao;

// Definicao das OPERACOES (funcoes) do TAD Fracao

Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
Fracao inverterFracao(Fracao F);

// Implementacao da funcao principal (main)

int main (){
    system("cls");

    Fracao F1 = criarFracao(3, 7);
    Fracao F2 = criarFracao(12, 20);
    Fracao F3 = criarFracao(6, 4);

    exibirFracao(F1);
    exibirFracao(inverterFracao(F2));
    exibirFracao(F3);
    return 0;
}

// Implementacao das funcoes Complementares

Fracao criarFracao(int N, int D) {
    if(D == 0){
        printf("ERRO: nao e possivel criar fracao com denominador 0!");
        exit(1);
    }

    Fracao F;
    F.Numerador = N;
    F.Denominador = D;

    return F;
}

void exibirFracao(Fracao F) {
    printf("%d / %d \n", F.Numerador, F.Denominador);
}

Fracao inverterFracao(Fracao F){
    Fracao G;
    G.Numerador = F.Denominador;
    G.Denominador = F.Numerador;

    return G;
}