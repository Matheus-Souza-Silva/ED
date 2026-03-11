#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int N); // Prototipo da funcao ehPrimo

int main() {
    // Algoritmo para teste de Primalidade
    system("cls");

    int numero = 0;

    INICIO:

        printf("Digite um numero: ");
        scanf("%d",&numero);

        if(ehPrimo(numero) == 1) printf("%d e PRIMO!", numero);
        else printf("%d NAO e PRIMO!", numero);

        fflush(stdin);
        getchar();
        system("cls");

        goto INICIO;

    return 0;
}

// Implementacao da funcao ehPrimo

int ehPrimo(int N) {
    if (N <= 1) return 0;

    int Contador = 0;

    // Algoritmo versao 1 (testa todos os numeros de 2 ate N)

    // for(int i = 2; i < N; i++){
    //     Contador++;
    //     if(N % i == 0){
    //         if(Contador == 1) printf("%d if | ",Contador);
    //         else printf("%d ifs | ",Contador);
    //         return 0;
    //     }
    // }

    // Algoritmo versao 2 (i nunca vai ser maior que a metade de N)

    for(int i = 2; i * i <= N; i++){
        Contador++;
        if(N % i == 0){
            if(Contador == 1) printf("%d if | ",Contador);
            else printf("%d ifs | ",Contador);
            return 0;
        }
    }

    printf("%d ifs | ",Contador);
    return 1; // Se todos os testes (ifs) falharem, o numero e primo
}