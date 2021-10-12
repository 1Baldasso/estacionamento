#include <iostream>
#include <locale.h>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "classes.h"

#define PAUSE system("pause")
#define CLS system("CLS")
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

string mes, dia, hora, ano, diaSem, minuto;

using namespace std;

void inicio();

void atualizarHora(){
    time_t agora = time(0);
    char* agoraC = ctime(&agora);
    string agoraS = agoraC;
    diaSem = agoraS.substr(0,3);
    mes = agoraS.substr(4,3);
    dia = agoraS.substr(8,2);
    hora = agoraS.substr(11,2);
    minuto = agoraS.substr(14,2);
    ano = agoraS.substr(20,4);
}

void cadastrarCarro(){
    string placa, cor, modelo, marca;
    cout << "Digite a placa do carro" << endl;
    cin >> placa;
    cout << "Digite a cor do carro" << endl;
    cin >> cor;
    cout << "Digite a marca do carro" << endl;
    cin >> marca;
    cout << "Digite o modelo do carro" << endl;
    cin >> modelo;
    clientes[c].carro.cor=cor;
    clientes[c].carro.modelo=modelo;
    clientes[c].carro.marca=marca;
    clientes[c].carro.placa=placa;
}

int MestoInt(string mes){
    if(mes=="Jan"){
        return 1;
    }
    if(mes=="Feb"){
        return 2;
    }
    if(mes=="Mar"){
        return 3;
    }
    if(mes=="Apr"){
        return 4;
    }
    if(mes=="May"){
        return 5;
    }
    if(mes=="Jun"){
        return 6;
    }
    if(mes=="Jul"){
        return 7;
    }
    if(mes=="Aug"){
        return 8;
    }
    if(mes=="Sep"){
        return 9;
    }
    if(mes=="Oct"){
        return 10;
    }
    if(mes=="Nov"){
        return 11;
    }
    if(mes=="Dec"){
        return 12;
    }
    return -1;
}

double valorSaida(int ent, int sai){
    int tempo;
    if(entrada[ent].minuto<saida[sai].minuto){
        tempo = (entrada[ent].hora-saida[sai].hora)*60;
        tempo = tempo + (entrada[ent].minuto-saida[sai].minuto);
    }
    tempo = tempo/60;
    return tempo*6;
}

int iterarClientes(){
    for(int i=0;i<TAMMAX;i++){
        if(clientes[i].id==NULL){
            return i;
        }
    }
}

void cadastrarCliente(bool cont)
{
    int esc;
    string nome, CPF, telefone, tipo;
    cout << "O cliente é:" << endl;
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
        while(getline(cin, telefone))
            if(telefone != ""){
            break;
        }
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
    cadastrarCarro();
    clientes[c].cadastrarCliente(nome,CPF,tipo,telefone);
    c++;
    if (!cont){
        inicio();
    }
}

int procurarCliente(){
    CLS;
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
    CLS;
    int esc, a;
    cout << "Cliente existente?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Não" << endl;
    cin >> esc;
    if(esc == 1){
        a = procurarCliente();
        entrada[e].consumidor.nome=clientes[a].nome;
        entrada[e].consumidor.carro.placa=clientes[a].carro.placa;
    } else {
        cadastrarCliente(1);
    }
    atualizarHora();
    entrada[e].data = (dia+"/"+mes+"/"+ano);
    entrada[e].horario = hora;
    cout << "Vaga em que o carro foi estacionado?" << endl;
    cin >> esc;
    entrada[e].lugar.id=esc;
    e++;
    cout << "Carro estacionado na vaga " << esc << endl;
    PAUSE;
    inicio();
}

int procurarPlaca(string placa){
    for (int i=0;i<TAMMAX;i++){
        if(placa==entrada[i].lugar.ocupando.carro.placa){
            return i+1;
        }
    }
}

void saidaVeiculo(){
    CLS;
    int a;
    string placa;
    double valor;
    cout << "Digite a placa do carro que está saindo" << endl;
    cin >> placa;
    a = procurarPlaca(placa);
    atualizarHora();
    saida[s].data = (dia+"/"+MestoInt(mes)+"/"+ano);
    saida[s].horario = hora;
    valor=valorSaida(a,s);
    cout << setprecision(2) << "O valor do estacionamento ficou em: R$" << valor << endl;
    s++;
    PAUSE;
    inicio();
}

void listaCarros(){
    for (int i=0;i<TAM;i++){
        if(vagas[i].status){
            cout << "Vaga número: " << i+1 << endl;
            cout << "Status: OCUPADO" << endl;
            cout << "Veículo: " << vagas[i].ocupando.carro.modelo << " Placa: " << vagas[i].ocupando.carro.placa << endl;
            cout << "Cliente: " << vagas[i].ocupando.nome << " Tipo: " << vagas[i].ocupando.tipoCliente << endl;
        }
    }
}

int vagasDisp(){
    int nT=0;
    for(int i=0;i<TAM;i++){
        if(!vagas[i].status){
            cout << "Vaga nº " << i+1 << " disponível" << endl;
            nT++;
        }
    }
    return nT;
}

void verVagas(){
    CLS;
    int n = vagasDisp();
    cout << endl << "Existem " << n <<  " vagas disponíveis" << endl << endl;

    PAUSE;
    inicio();
 }

void inicio ()
{
    CLS;
    int esc;
    cout << "1 - Entrada de carros" << endl;
    cout << "2 - Saída de carros" << endl;
    cout << "3 - Lista de carros estacionados" << endl;
    cout << "4 - Cadastrar novo cliente" << endl;
    cout << "5 - Vagas disponíveis" << endl;
    cin >> esc;
    switch(esc){
    case(1):
        entradaVeiculo();
    break;
    case(2):
        saidaVeiculo();
    break;
    case(3):
        listaCarros();
    break;
    case(4):
        cadastrarCliente(0);
    break;
    case(5):
        verVagas();
    break;
    }
}

int main(){

    setlocale(LC_ALL,"portuguese");

    atualizarHora();

    cout << diaSem << ", " << dia << " de " << mes << " de " << ano << " às " << hora << ":" << minuto << endl;


    inicio();

    return 0;
}

