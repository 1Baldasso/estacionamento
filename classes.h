using namespace std;

class estacionamento
{
    public:

    int numVagas;
    double valorHora;
    int vagasReservadas;

};

class veiculo
{
    public:

    string placa;
    string cor;
    string modelo;
    string marca;
    char tipo;


    void cadastrarVeiculo(string aPlaca, string aCor, string aModelo, string aMarca, char aTipo)
    {
        placa=aPlaca;
        cor=aCor;
        modelo=aModelo;
        marca=aMarca;
        tipo=aTipo;
    }
};



class cliente
{
    public:

    int id;
    string nome;
    string CPF;
    string tipoCliente;
    string telefone;
    veiculo carro;


    void cadastrarCliente(string aNome, string aCPF, string aTipo, string aTelefone, int aID)
    {
        nome=aNome;
        CPF=aCPF;
        id=aID;
        tipoCliente=aTipo;
        telefone=aTelefone;
    }

};

class vaga
{
    public:

    int id;
    string descricao;
    bool status;
    cliente ocupando;

};


class movimentacao
{
    public:

    int id;
    int hora;
    int minuto;
    int dia;
    int mes;
    string horario;
    string data;
    vaga lugar;
};

