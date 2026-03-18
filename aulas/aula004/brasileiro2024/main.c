#include <stdio.h>
#include <stdlib.h>
#include "equipe.h"
#include <locale.h>

int main(){
    system("cls");
    configurarAcentuacao();

    Equipe * Tabela = lerDados("tabela2024.csv");

    for(int i = 0; i < 20; i++){
        printf("%d \t %s \t %.2f\n",
            Tabela[i].Posicao, 
            Tabela[i].Time,
            Tabela[i].Aproveitamento);
    }

    int t_1 = getGP(Tabela, "Palmeiras");

    printf("\nPalmeiras fez %d gols", t_1);
    return 0;
}