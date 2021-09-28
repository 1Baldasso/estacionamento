using namespace std;

class estacionamento
{
    int numVagas;
    double valorHora;
    int vagasReservadas;
public:
    void sair(double horas)
    {
        vagasReservadas--;
        numVagas++;
        cout << "O valor a ser pago é:" << valorHora*horas << endl;
    }
    void entrar ()
    {
        numVagas--;
        vagasReservadas++;
    }
};

class veiculo
{
    string placa;
    string cor;
    string modelo;
    string marca;
    char tipo;

public:

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
    int id;
    string nome;
    string CPF;
    string tipoCliente;
    string telefone;
    veiculo carro;

public:
    void cadastrarCliente(string aNome, string aCPF, string aTipo, string aTelefone)
    {
        nome=aNome;
        CPF=aCPF;
        tipoCliente=aTipo;
        telefone=aTelefone;
    }

};

class vaga
{
    int id;
    string descricao;
};


class movimentacao
{
    int id;
    string horario;
    string data;
};

