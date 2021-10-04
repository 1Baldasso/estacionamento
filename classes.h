using namespace std;

class estacionamento
{
    public:

    int numVagas;
    double valorHora;
    int vagasReservadas;

    void sair(double horas)
    {
        vagasReservadas--;
        numVagas++;
        cout << "O valor a ser pago �:" << valorHora*horas << endl;
    }
    void entrar ()
    {
        numVagas--;
        vagasReservadas++;
    }
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
    public:

    int id;
    string descricao;
};


class movimentacao
{
    public:

    int id;
    string horario;
    string data;
};

