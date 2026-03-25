#ifndef LISTA_H
#define LISTA_H

// Inclusao de bibliotecas especificas para Windows
#ifdef _WIN32
#	include <fcntl.h>
#	include <io.h>
#	include <windows.h>
#endif

// Definindo cada elemento da lista

#define TAM_TITULO 96
#define TAM_NOME 48

#define A_FAZER 0
#define EM_ANDAMENTO 1
#define FEITO 2

typedef struct {
    char Titulo[TAM_TITULO];
    char Responsavel[TAM_NOME];
    int Status; // Varia de 0 (A_FAZER) ate 2 (FEITO)
    float Progresso; // De 0,0 (0%) ate 1,0 (100%)
    int Avaliacao; // De 0 (Pouco Importante) ate 5 (Prioridade Maxima)
} Tarefa;

// Definindo a estrutura da lista ("Moldura da Lista")

typedef struct {
    Tarefa * Dados; // Endereco onde sera armazenado o conjunto de tarefas
    int Tamanho; // Quantas tarefas estão na lista
    int Capacidade; // Maximo de tarefas que podem ser cadastrados
} Lista;

Lista * CriarLista(int C); // Para criar lista de capacidade C
void configurarAcentuacao();
void AdicionarTarefa(Lista * L, Tarefa T);
void GerarHTMLTabela(Lista *Lista, char *CaminhoArquivo);

#endif