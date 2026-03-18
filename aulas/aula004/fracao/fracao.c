#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

// Implementacao das funcoes Complementares

int absoluto(int N) {
    if (N < 0) return -N;
    return N;
}

int mdc(int A, int B) {
    A = absoluto(A);
    B = absoluto(B);

    if (A == 0) return B;
    if (B == 0) return A;

    while (B != 0) {
        int Resto = A % B;
        A = B;
        B = Resto;
    }

    return A;
}

Fracao criarFracao(int N, int D) {
    if(D == 0){
        printf("ERRO: nao e possivel criar fracao com denominador 0!");
        exit(1);
    }

    Fracao F;
    F.Numerador = N;
    F.Denominador = D;

    if (F.Denominador < 0) {
        F.Numerador = -F.Numerador;
        F.Denominador = -F.Denominador;
    }

    return F;
}

void exibirFracao(Fracao F) {
    printf("%d / %d \n", F.Numerador, F.Denominador);
}

Fracao inverterFracao(Fracao F){
    if (F.Numerador == 0) {
        printf("ERRO: nao e possivel inverter fracao com numerador 0!");
        exit(1);
    }

    Fracao G;
    G.Numerador = F.Denominador;
    G.Denominador = F.Numerador;

    return criarFracao(G.Numerador, G.Denominador);
}

Fracao simplificarFracao(Fracao F) {
    if (F.Numerador == 0) return criarFracao(0, 1);

    int Divisor = mdc(F.Numerador, F.Denominador);
    return criarFracao(F.Numerador / Divisor, F.Denominador / Divisor);
}

Fracao somarFracoes(Fracao F1, Fracao F2) {
    int N = (F1.Numerador * F2.Denominador) + (F2.Numerador * F1.Denominador);
    int D = F1.Denominador * F2.Denominador;
    return simplificarFracao(criarFracao(N, D));
}

Fracao subtrairFracoes(Fracao F1, Fracao F2) {
    int N = (F1.Numerador * F2.Denominador) - (F2.Numerador * F1.Denominador);
    int D = F1.Denominador * F2.Denominador;
    return simplificarFracao(criarFracao(N, D));
}

Fracao multiplicarFracoes(Fracao F1, Fracao F2) {
    int N = F1.Numerador * F2.Numerador;
    int D = F1.Denominador * F2.Denominador;
    return simplificarFracao(criarFracao(N, D));
}

Fracao dividirFracoes(Fracao F1, Fracao F2) {
    if (F2.Numerador == 0) {
        printf("ERRO: nao e possivel dividir por fracao equivalente a 0!");
        exit(1);
    }

    int N = F1.Numerador * F2.Denominador;
    int D = F1.Denominador * F2.Numerador;
    return simplificarFracao(criarFracao(N, D));
}

double converterFracao(Fracao F) {
    return (double)F.Numerador / F.Denominador;
}

int compararFracao(Fracao F1, Fracao F2) {
    long long Esquerda = (long long)F1.Numerador * F2.Denominador;
    long long Direita = (long long)F2.Numerador * F1.Denominador;

    if (Esquerda < Direita) return -1;
    if (Esquerda > Direita) return 1;
    return 0;
}

Fracao potenciaFracao(Fracao F, int Expoente) {
    if (Expoente == 0) return criarFracao(1, 1);

    if (Expoente < 0) {
        if (F.Numerador == 0) {
            printf("ERRO: nao e possivel elevar 0 a expoente negativo!");
            exit(1);
        }
        F = inverterFracao(F);
        Expoente = -Expoente;
    }

    int N = 1;
    int D = 1;

    for (int i = 0; i < Expoente; i++) {
        N *= F.Numerador;
        D *= F.Denominador;
    }

    return simplificarFracao(criarFracao(N, D));
}