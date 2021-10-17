#include <iostream>
#include <locale.h>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string.h>
#include <string>
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
int iterarClientes();


void iterarAPI(){
    ifstream api;
    api.open("clientes.txt");
    string a;
    if(api.is_open()){
        for(c=0;!api.eof();c++){
            getline(api,a);
            clientes[c].id = stoi(("0"+a));
            getline(api,clientes[c].nome);
            getline(api,clientes[c].CPF);
            getline(api,clientes[c].telefone);
            getline(api,clientes[c].tipoCliente);
            getline(api,clientes[c].carro.placa);
            getline(api,clientes[c].carro.modelo);
            getline(api,clientes[c].carro.marca);
            getline(api,clientes[c].carro.cor);
            getline(api,a);
        }
    }
    api.close();
    api.open("entradas_outubro.txt");
    if (api.is_open()){
        for(e=0;!api.eof();e++){
            getline(api,a);
            entrada[e].id=stoi(("0"+a));
            getline(api,entrada[e].data);
            getline(api,entrada[e].horario);
            getline(api,a);
            entrada[e].lugar.id=stoi(("0"+a));
            vagas[entrada[e].lugar.id-1].status=true;
            getline(api,entrada[e].lugar.ocupando.nome);
            getline(api,entrada[e].lugar.ocupando.carro.placa);
            getline(api,a);
        }
    }api.close();
    api.open("saida_outubro.txt");
    if (api.is_open()
        ){
        for(s=0;!api.eof();s++){
            getline(api,a);
            saida[s].id=stoi(("0"+a));
            getline(api,saida[s].data);
            getline(api,saida[s].horario);
            getline(api,a);
            saida[s].lugar.id=stoi(("0"+a));
            vagas[saida[s].lugar.id-1].status=false;
            getline(api,saida[s].lugar.ocupando.nome);
            getline(api,saida[s].lugar.ocupando.carro.placa);
            getline(api,a);
        }
    }

}
void adicionarAPI(string nome){
    ofstream api;
    api.open((nome+".txt"));
    if(api.is_open()){
        for(int i=0;i<c;i++){
            api << clientes[i].id << '\n';
            api << clientes[i].nome << '\n';
            api << clientes[i].CPF << '\n';
            api << clientes[i].telefone << '\n';
            api << clientes[i].tipoCliente << '\n';
            api << clientes[i].carro.placa << '\n';
            api << clientes[i].carro.modelo << '\n';
            api << clientes[i].carro.marca << '\n';
            api << clientes[i].carro.cor << '\n';
            api << '\n';
        }
    }
}
void adicionarAPIentrada(string nome){
    ofstream api;
    api.open((nome+".txt"));
    if(api.is_open()){
        for(int i=0;i<e;i++){
            api << entrada[i].id << '\n';
            api << entrada[i].data << '\n';
            api << entrada[i].horario << '\n';
            api << entrada[i].lugar.id << '\n';
            api << entrada[i].lugar.ocupando.nome << '\n';
            api << entrada[i].lugar.ocupando.carro.placa << '\n';
            api << '\n';
        }
    }
}
void adicionarAPIsaida(string nome){
    ofstream api;
    api.open((nome+".txt"));
    if(api.is_open()){
        for(int i=0;i<s;i++){
            api << saida[i].id << '\n';
            api << saida[i].data << '\n';
            api << saida[i].horario << '\n';
            api << saida[i].lugar.id << '\n';
            api << saida[i].lugar.ocupando.nome << '\n';
            api << saida[i].lugar.ocupando.carro.placa << '\n';
            api << '\n';
        }
    }
}

void atualizarHora(){
    time_t agora = time(0);
    char* agoraC = ctime(&agora);
    string agoraS = agoraC;
    diaSem = agoraS.substr(0,3);
    mes = agoraS.substr(4,3);
    dia = agoraS.substr(8,2);
    hora = agoraS.substr(11,5);
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
    if(entrada[ent].mes!=saida[sai].mes){
        if(entrada[ent].dia!=saida[sai].dia){
            if(entrada[ent].dia<saida[sai].dia && (saida[sai].mes-entrada[ent].mes)<1){
                tempo=entrada[ent].dia-saida[sai].dia;
                return tempo*25;
            }else{
                tempo = (entrada[ent].mes-saida[sai].mes);
                return tempo * 600;
            }
        }
    } else if(entrada[ent].dia!=saida[sai].dia){
        tempo=entrada[ent].dia-saida[sai].dia;
        return tempo*25;
    }else{
        if(entrada[ent].minuto<saida[sai].minuto){
            tempo = (entrada[ent].hora-saida[sai].hora)*60;
            tempo = tempo + (entrada[ent].minuto-saida[sai].minuto);
        }
        tempo = tempo/60;
        if (tempo < 30 ){
            return 3.5;
        }
        return tempo*6;
    }

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
    clientes[c].cadastrarCliente(nome,CPF,tipo,telefone,c+1);
    c++;
    adicionarAPI("clientes");
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

void atribuirClienteVaga(int aVaga, int aCliente){
    vagas[aVaga].ocupando.nome=clientes[aCliente].nome;
    vagas[aVaga].ocupando.tipoCliente=clientes[aCliente].tipoCliente;
    vagas[aVaga].ocupando.telefone=clientes[aCliente].telefone;
    vagas[aVaga].ocupando.carro.placa=clientes[aCliente].carro.placa;
    vagas[aVaga].ocupando.carro.modelo=clientes[aCliente].carro.modelo;
    entrada[e].lugar.ocupando.nome=clientes[aCliente].nome;
    entrada[e].lugar.ocupando.tipoCliente=clientes[aCliente].tipoCliente;
    entrada[e].lugar.ocupando.telefone=clientes[aCliente].telefone;
    entrada[e].lugar.ocupando.carro.placa=clientes[aCliente].carro.placa;
    entrada[e].lugar.ocupando.carro.modelo=clientes[aCliente].carro.modelo;
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
        entrada[e].lugar.ocupando.nome=clientes[a].nome;
        entrada[e].lugar.ocupando.carro.placa=clientes[a].carro.placa;
    } else {
        a = c;
        cadastrarCliente(1);
    }
    atualizarHora();
    entrada[e].data = (dia+"/"+mes+"/"+ano);
    entrada[e].id = e+1;
    entrada[e].dia = stoi(dia);
    entrada[e].mes = MestoInt(mes);
    entrada[e].horario = hora;
    cout << "Vaga em que o carro foi estacionado?" << endl;
    cin >> esc;
    entrada[e].lugar.id=esc;
    vagas[esc-1].status=true;
    atribuirClienteVaga(esc-1,a);
    e++;
    adicionarAPIentrada("entradas_outubro");
    cout << "Carro estacionado na vaga " << esc << endl;
    PAUSE;
    inicio();
}

int procurarVagas(string placa){
    for(int i=0;i<TAMMAX;i++){
        if(vagas[i].ocupando.carro.placa==placa){
            return i;
        }
    }
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
    saida[s].data = (dia+"/"+mes+"/"+ano);
    saida[s].mes = MestoInt(mes);
    saida[s].dia = stoi(dia);
    saida[s].horario = hora;
    valor=valorSaida(a,s);
    vagas[procurarVagas(placa)].status=false;

    cout << setprecision(2) << "O valor do estacionamento ficou em: R$" << valor << endl;

    s++;
    adicionarAPIsaida("saidas_outubro");
    PAUSE;
    inicio();
}

void listaCarros(){
    for (int i=0;i<TAM;i++){
        if(vagas[i].status){
            cout << "Vaga número: " << i+1 << endl;
            cout << "Status: OCUPADO" << endl;
            cout << "Veículo: " << vagas[i].ocupando.carro.modelo << "          Placa: " << vagas[i].ocupando.carro.placa << endl;
            cout << "Cliente: " << vagas[i].ocupando.nome << "          Tipo: " << vagas[i].ocupando.tipoCliente << endl;
        }
    }
    PAUSE;
    inicio();
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

void visualizarEeS(){
        cout << "\t\tENTRADA\t\t" << endl;
    for(int i=0;i<e-1;i++){
        cout << entrada[i].id << " - " << entrada[i].data << " às " << entrada[i].horario << endl;
        cout << "Nome: " << entrada[i].lugar.ocupando.nome << "\tCarro: " << entrada[i].lugar.ocupando.carro.modelo << "\tPlaca: " << entrada[i].lugar.ocupando.carro.placa << endl;
        cout << "Estacionado na vaga " << entrada[i].lugar.id << endl;
        cout << "------------------" << endl;
    }
        cout << "\t\tSAIDA\t\t" << endl;
        for(int i=0;i<s;i++){
        cout << saida[i].id << " - " << saida[i].data << " às " << saida[i].horario << endl;
        cout << "Nome: " << saida[i].lugar.ocupando.nome << "\tCarro: " << saida[i].lugar.ocupando.carro.modelo << "\tPlaca: " << saida[i].lugar.ocupando.carro.placa << endl;
        cout << "Estacionado na vaga " << saida[i].lugar.id << endl;
        cout << "------------------" << endl;
    }
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
    cout << "6 - Visualizar Entradas e Saidas" << endl;
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
    case(6):
        visualizarEeS();
    }
}

int main(){

    setlocale(LC_ALL,"portuguese");
    iterarAPI();
    inicio();

    return 0;
}

