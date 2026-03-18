#ifndef FRACAO_H
#define FRACAO_H

// Definicao dos DADOS do TAD Fracao

typedef struct {
    int Numerador;
    int Denominador;
} Fracao;

// Definicao das OPERACOES (funcoes) do TAD Fracao

int absoluto(int N);
int mdc(int A, int B);
Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
Fracao inverterFracao(Fracao F);
Fracao simplificarFracao(Fracao F);
Fracao somarFracoes(Fracao F1, Fracao F2);
Fracao subtrairFracoes(Fracao F1, Fracao F2);
Fracao multiplicarFracoes(Fracao F1, Fracao F2);
Fracao dividirFracoes(Fracao F1, Fracao F2);
double converterFracao(Fracao F);
int compararFracao(Fracao F1, Fracao F2);
Fracao potenciaFracao(Fracao F, int Expoente);

#endif