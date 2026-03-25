#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    system("cls");
    
    // Como criar e inicializar uma variavel do tipo Tarefa?

    // 1) Iniciar elemento por elemento

    Tarefa P;

    strcpy(P.Titulo, "Finalizar materiais de lancamento");
    strcpy(P.Responsavel, "Ana Beatriz");
    P.Status = FEITO;
    P.Progresso = 0.20;
    P.Avaliacao = 2;

    // 2) Inicializando todos os elementos de uma vez

    Tarefa Q = {"Finalizar materiais de lancamento", "Ana Beatriz", FEITO, 0.20, 2};

    // 3) Usando ponteiro para struct, com elementos inicializados separadamente

    Tarefa * R = (Tarefa *) malloc(sizeof(Tarefa));

    strcpy(R->Titulo, "Finalizar materiais de lancamento");
    strcpy(R->Responsavel, "Ana Beatriz");
    R->Status = FEITO;
    R->Progresso = 0.20;
    R->Avaliacao = 2;

    printf("Endereco (em formato hexadecimal): %X\n", R);
    return 0;
}