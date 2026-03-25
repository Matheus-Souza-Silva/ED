#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"

int main() {
    system("cls");
    configurarAcentuacao();

    Lista * Planner = CriarLista(30);

    // Main 

    Tarefa T1 = {"Entrega do relatório de BD", "Rafael Souza", FEITO, 1.00, 4};
    Tarefa T2 = {"Revisão do código do sistema", "Carlos Henrique", FEITO, 1.00, 5};
    Tarefa T3 = {"Criação de mockups para o app", "Juliana Ribeiro", EM_ANDAMENTO, 0.40, 3};
    Tarefa T4 = {"Levantamento de requisitos", "Rafael Souza", A_FAZER, 0.00, 2};
    Tarefa T5 = {"Treinamento da equipe", "Fernanda Lima", EM_ANDAMENTO, 0.60, 4};
    Tarefa T6 = {"Testes automatizados", "Lucas Martins", A_FAZER, 0.00, 5};
    Tarefa T7 = {"Atualização da documentação técnica", "Mariana Alves", A_FAZER, 0.00, 3};
    Tarefa T8 = {"Integração com API externa", "Pedro Rocha", EM_ANDAMENTO, 0.50, 4};
    Tarefa T9 = {"Apresentação para o cliente", "Bianca Torres", FEITO, 1.00, 5};
    Tarefa T10 = {"Correção de bugs críticos", "João Victor", EM_ANDAMENTO, 0.30, 5};

    // Acrescentando tarefas na lista

    AdicionarTarefa(Planner, T1);
    AdicionarTarefa(Planner, T2);
    AdicionarTarefa(Planner, T3);
    AdicionarTarefa(Planner, T4);
    AdicionarTarefa(Planner, T5);
    AdicionarTarefa(Planner, T6);
    AdicionarTarefa(Planner, T7);
    AdicionarTarefa(Planner, T8);
    AdicionarTarefa(Planner, T9);
    AdicionarTarefa(Planner, T10);

    Tarefa T11 = {"Elaborar prova", "Beatriz", EM_ANDAMENTO, 0.80, 5};
    AdicionarTarefa(Planner, T11);

    Planner->Tamanho = 11;

    // Exibir os titulos das tarefas

    for(int i = 0; i < Planner->Tamanho; i++){
        printf("%d \t %s\n",i + 1, Planner->Dados[i].Titulo);
    }

    GerarHTMLTabela(Planner, "Planner.html");

    return 0;
}