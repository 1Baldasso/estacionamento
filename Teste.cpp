#include <iostream>
#include <locale.h>
#include <fstream>
#include "classes.h"

#define TAM 10
#define TAMMAX 100

estacionamento RBKV;
movimentacao entrada[TAMMAX];
movimentacao saida[TAMMAX];
vaga vagas[TAM];

cliente clientes[TAMMAX];
veiculo veiculos[TAMMAX];

int e=0;
int s=0;
int c=0;
int v=0;


void inicio ()
{
    int esc;
    cout << "1 - Entrada de carros" << endl;
    cout << "2 - Saída de carros" << endl;
    cout << "3 - Lista de carros estacionados" << endl;
    cout << "4 - Cadastrar novo cliente" << endl;
    cout << "5 - Vagas disponíveis" << endl;
    cout << "6 - Procurar veículo" << endl;
    cin >> esc;
    switch(esc){
    case(1):
    break;
    case(2):
    break;
    case(3):
    break;
    case(4):
    break;
    case(5):
    break;
    case(6):
    break;
    }
}

int main(){
    setlocale(LC_ALL,"portuguese");
    ifstream in;
    ofstream out;

    inicio();

    return 0;
}

