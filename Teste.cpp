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

int e=0; // entrada
int s=0; // saida
int c=0; // cliente
int v=0; // vaga

int iterarClientes(){
    for(int i=0;i<TAMMAX;i++){
        if(clientes[i].id==NULL){
            return i;
        }
    }
}

void cadastrarCliente()
{
    int esc;
    string nome, CPF, telefone, tipo;
    cout << "O cliente �:" << endl;
    cout << "1 - Mensalista" << endl;
    cout << "2 - Diarista" << endl;
    cout << "3 - Horista" << endl;
    cout << "4 - Passageiro" << endl;
    cin >> esc;
    if(esc == 4){
        nome = "";
        CPF ="";
        telefone="";
        tipo="";
    } else {
        cout << "Insira o nome do cliente:" << endl;
        while(getline(cin, nome))
            if(nome != ""){
            break;
        }
        cout << "CPF do cliente:" << endl;
        cin >> CPF;
        cout << "Telefone do Cliente" << endl;
        getline(cin, telefone);
        switch(esc){
        case(1):
            tipo="Mensalista";
        break;
        case(2):
            tipo="Diarista";
        break;
        case(3):
            tipo="Horista";
        break;
        }
    }
    clientes[c].cadastrarCliente(nome,CPF,tipo,telefone);
    c++;
}

int procurarCliente(){
    int f;
    string procurado;
    cout << "Insira algum dado do cliente, para procurar:" << endl;
    while(getline(cin, procurado))
        if(procurado != ""){
        break;
    }
    for(int i=0;i<iterarClientes();i++){
        if(procurado==clientes[i].nome){
            return i;
        }
        if(procurado==clientes[i].CPF){
            return i;
        }
        if(procurado==clientes[i].telefone){
            return i;
        }
    }

}

void entradaVeiculo()
{
    int esc, a;
    cout << "Cliente existente?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - N�o" << endl;
    cin >> esc;
    if(esc == 1){
        a = procurarCliente();
        veiculos[a];
    } else {
        cadastrarCliente();
    }
}

void listaCarros(){
    for (int i=0;i<TAM;i++){
        if(vagas[i].status){
            cout << "Vaga n�mero: " << i+1 << endl;
            cout << "Status: OCUPADO" << endl;
            cout << "Ve�culo: " << vagas[i].carro.modelo << " Placa: " << vagas[i].carro.placa << endl;
            cout << "Cliente: " << vagas[i].ocupando.nome << " Tipo: " << vagas[i].ocupando.tipoCliente << endl;
        }
    }
}

void inicio ()
{
    int esc;
    cout << "1 - Entrada de carros" << endl;
    cout << "2 - Sa�da de carros" << endl;
    cout << "3 - Lista de carros estacionados" << endl;
    cout << "4 - Cadastrar novo cliente" << endl;
    cout << "5 - Vagas dispon�veis" << endl;
    cout << "6 - Procurar ve�culo" << endl;
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

