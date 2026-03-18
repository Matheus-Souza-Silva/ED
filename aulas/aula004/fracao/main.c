#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

// Implementacao da funcao principal (main)

int main (){
    system("cls");

    Fracao F1 = criarFracao(3, 7);
    Fracao F2 = criarFracao(12, 20);
    Fracao F3 = criarFracao(6, 4);
    Fracao F4 = criarFracao(-2, 5);

    printf("F1 = ");
    exibirFracao(F1);
    printf("F2 = ");
    exibirFracao(F2);
    printf("F3 = ");
    exibirFracao(inverterFracao(F2));
    printf("F3 simplificada = ");
    exibirFracao(simplificarFracao(F3));

    printf("\nF1 + F2 = ");
    exibirFracao(somarFracoes(F1, F2));

    printf("F1 - F2 = ");
    exibirFracao(subtrairFracoes(F1, F2));

    printf("F1 * F2 = ");
    exibirFracao(multiplicarFracoes(F1, F2));

    printf("F1 / F2 = ");
    exibirFracao(dividirFracoes(F1, F2));

    printf("\nF1 em decimal = %.6f\n", converterFracao(F1));

    printf("Comparacao F1 e F4: ");
    int Cmp = compararFracao(F1, F4);
    if (Cmp < 0) printf("F1 < F4\n");
    else if (Cmp > 0) printf("F1 > F4\n");
    else printf("F1 == F4\n");

    printf("Potencia F1^3 = ");
    exibirFracao(potenciaFracao(F1, 3));

    printf("Potencia F1^-2 = ");
    exibirFracao(potenciaFracao(F1, -2));

    return 0;
}