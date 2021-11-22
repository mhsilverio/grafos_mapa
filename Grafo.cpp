// MILENA HELOÍSA DE AMORIM SILVÉRIO

#include <iostream>

#include "Grafo.h"

Grafo::Grafo(){

 for(int i = 0; i < MAXNOS; i++)
        for(int j = 0; j < MAXNOS; j++)
            adj[i][j] = false;

    for(int i = 0; i < MAXNOS; i++)
        for(int j = 0; j < MAXNOS; j++)
            distancia[i][j] = -1;
    N = 0;
}

void Grafo::une(string a, string b, float dist){
    int A = PegaCidade(a);
    int B = PegaCidade(b);

    if (validos(a,b)) {
		adj[A][B] = true;
        adj[B][A] = true;
		distancia[A][B] = dist;
        distancia[B][A] = dist;
	}
}

bool Grafo::validos(string a, string b) const{
    int A = PegaCidade(a);
    int B = PegaCidade(b);

	return (A > -1 && A < MAXNOS && B > -1 && B < MAXNOS);
}

bool Grafo::adjacente(string a, string b) const{
    int A = PegaCidade(a);
    int B = PegaCidade(b);

    if(validos(a, b))
        return adj[A][B];
    else
        return false;
}

void Grafo::imprime() const{
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void Grafo::adiciona_cidade(string cidade){
    ArmazenaCidade[N++] = cidade;
}

int Grafo::PegaCidade(string cidade) const{
	int cidadei = -1;

    for(int i = 0; i < MAXNOS; i++){
        if(ArmazenaCidade[i] == cidade)
            cidadei = i; 
    }
    return cidadei;
}

float Grafo::PegaDistancia(string a, string b) const{
    int A = PegaCidade(a);
    int B = PegaCidade(b);

    if (adj[A][B])
        return (distancia[A][B]);
    else 
        return INFINITO;
    // return (adj[A][B]) ? distancia[A][B] : INFINITO;
}

float Grafo::MenorCaminho(string a, string b, vector<string> &caminho){
    float distancia[MAXNOS];
    bool calculado[MAXNOS];
    int precede[N];

    int A = PegaCidade(a);
    int B = PegaCidade(b);

    for (int i=0; i<N; ++i){
        distancia[i] = INFINITO;
        calculado[i] = false;
    }

    distancia[A] = 0;                               // A para A é igual a 0.
    calculado[A] = true;
    int corrente = A;

    while(corrente != B){
        float menordist = INFINITO;                   // é a menor distancia das novas distâncias calculadas
        int k;                                      // próximo corrente é a que tem a menor distância
        float dcalculada = distancia[corrente];       // distância calculada é igual a distancia de A até o nó corrente

        for (int i=0; i<N; ++i){
            if(!calculado[i]){
                float novadist = dcalculada + PegaDistancia(ArmazenaCidade[corrente], ArmazenaCidade[i]);
                if(novadist < distancia[i]){
                    distancia[i] = novadist;
                    precede[i] = corrente;
                }
                if (distancia[i] < menordist){
                    menordist = distancia[i];
                    k = i;
                }
            }
        }
        corrente = k;
        calculado[corrente] = true;
    }

    int iAtual = B;
    string cidadeAtual = ArmazenaCidade[iAtual];
    while(cidadeAtual != a){
        caminho.push_back(cidadeAtual);                     // Coloca no caminho a localização atual.
        cidadeAtual = ArmazenaCidade[precede[iAtual]];      // Localização atual retrocederá 1 posição (para o que precede esta cidade).
        iAtual = PegaCidade(cidadeAtual);                   // Atualiza o indice da cidade retornando em 1 o indice
    }
    caminho.push_back(cidadeAtual);
    return distancia[B];
}

string Grafo::retornaCaminho(string a, string b, vector<string> &caminho) {
	for (int i = caminho.size() - 1; i > -1; --i) {
        cout << caminho[i] << " ";
        if(i != 0) 
            cout << "-> ";
	}
    cout << endl;
}
