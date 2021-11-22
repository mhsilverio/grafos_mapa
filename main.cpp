// MILENA HELOÍSA DE AMORIM SILVÉRIO

#include <iostream>
#include <string>

#include "Grafo.h"
#include "Grafo.cpp"

using namespace std;

void cidades(Grafo &M);
void UneCidades(Grafo &M);

int main(){
    Grafo M;    // 0 cidades (vértices), inicialmente 
    string A, B;
    vector<string> caminho;

    cidades(M);
    UneCidades(M);

    cout << "----------------" << endl;
    cout << "MAPA DE CIDADES" << endl;
    cout << "  PEDA/2021.2 " << endl;
    cout << "Milena Silverio" << endl;
    cout << "----------------" << endl;

    cout << endl << "Digite a cidade A: ";
    getline (cin, A);
    cout << "\nDigite a cidade B: ";
    getline (cin, B);

    cout << "\n--------------------------------------------" << endl;
    cout << "ENCONTRAMOS A MELHOR ROTA PARA A SUA VIAGEM!" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "\nMenor distancia entre " << A << " e " << B << ": " << M.MenorCaminho(A, B, caminho) << " Km" << endl;
    
    cout << "\nMenor caminho: "; string menorCaminho = M.retornaCaminho(A, B, caminho);
    cout << endl;

    return 0;
}

void cidades(Grafo &M){
    M.adiciona_cidade("Curitiba");   
    M.adiciona_cidade("Registro"); 
    M.adiciona_cidade("Londrina");
    M.adiciona_cidade("Itarare");
    M.adiciona_cidade("Ponta Grossa");
    M.adiciona_cidade("Sao Paulo");
    M.adiciona_cidade("Porto Uniao");
    M.adiciona_cidade("Mafra");
    M.adiciona_cidade("Joinville");
    M.adiciona_cidade("Blumenau");
    M.adiciona_cidade("Itajai");
    M.adiciona_cidade("Florianopolis");
    M.adiciona_cidade("Lages");
}
    
void UneCidades(Grafo &M) {
    M.une("Curitiba", "Ponta Grossa", 114);
    M.une("Curitiba", "Registro", 221.2);
    M.une("Curitiba", "Itarare", 208);
    M.une("Curitiba", "Mafra", 115);
    M.une("Curitiba", "Joinville", 132);
    M.une("Itarare", "Sao Paulo", 342);
    M.une("Itarare", "Londrina", 310);
    M.une("Mafra", "Porto Uniao", 143);
    M.une("Mafra", "Joinville", 136);
    M.une("Mafra", "Ponta Grossa", 155);
    M.une("Ponta Grossa", "Itarare", 174);
    M.une("Ponta Grossa", "Londrina", 271);
    M.une("Blumenau", "Itajai", 52.3);
    M.une("Blumenau", "Mafra", 165);
    M.une("Florianopolis", "Itajai", 102);
    M.une("Porto Uniao", "Ponta Grossa", 209);
    M.une("Registro", "Sao Paulo", 185.9);
    M.une("Itajai", "Joinville", 86.2);
    M.une("Lages", "Florianopolis", 231);
    M.une("Lages", "Blumenau", 223);
    M.une("Lages", "Mafra", 349);
    M.une("Lages", "Porto Uniao", 271);
}
