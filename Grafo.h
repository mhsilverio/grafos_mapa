// MILENA HELOÍSA DE AMORIM SILVÉRIO

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

constexpr int MAXNOS = 100;
constexpr float INFINITO = 10000000;

using namespace std;

class Grafo {

public:
    Grafo();
    void une(string a, string b, float dist);
    bool validos(string a, string b) const;             // Verificacao da validacao entre as cidades
    bool adjacente(string a, string b) const;           // Verificacao se as cidades sao adj 
    void imprime() const;
    void adiciona_cidade(string cidade);                // Adciona uma cidade
    float MenorCaminho(string a, string b, vector<string> &caminho);   //Encontra o menor caminho entre as duas cidades apresentadas
    // vector<string> &caminho = vetor onde se localiza o caminho entre as cidades
    string retornaCaminho(string a, string b, vector<string> &caminho);
    
private:
    bool adj[MAXNOS][MAXNOS];                    
    float distancia[MAXNOS][MAXNOS];                    // Distancia entre cidades
    string ArmazenaCidade[MAXNOS];                      // Armaza as cidades

    int N;                                             // número de nós do grafo
    int PegaCidade(string cidade) const;               // Pega (encontra) o indice de uma dada cidades
    float PegaDistancia(string a, string b) const;     // Retorna a distância entre duas cidades.     
};
#endif