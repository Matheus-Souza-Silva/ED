#ifndef EQUIPE_H
#define EQUIPE_H

// Inclusao de bibliotecas especificas para Windows
#ifdef _WIN32
#	include <fcntl.h>
#	include <io.h>
#	include <windows.h>
#endif

typedef struct {
    int Posicao;
    char Estado[32];
    char Time[32];
    int Pontos;
    int J; // N° de jogos V + E + D
    int V; // N° de vitórias
    int E; // N° de empates
    int D; // N° de derrotas
    int GP; // Gols marcados
    int GC; // Gols sofridos
    int SG; // Saldo de gols
    float Aproveitamento; // % de pontos conquistados em relação ao total de pontos disputados
} Equipe;

Equipe * lerDados(char * Arquivo); // Retorna um vetor de Equipes
int getGP(Equipe * V, char * Time);
void configurarAcentuacao();

#endif