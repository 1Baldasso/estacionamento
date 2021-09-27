class estacionamento
{
    int numVagas;
    double valorHora;
    int vagasReservadas;

    public:
    void estacionar (){
        numVagas--;
        vagasReservadas++;
    }
    void pagar(double horas){
        vagasReservadas--;
        numVagas++;
        cout << "O valor a ser pago é:" << valorHora*horas << endl;
    }

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
};



class cliente
{
    int id;
    string nome;
    string CPF;
    string tipoCliente;
    string telefone;

    public:
    void cadastrarCliente(string aNome, string aCPF, string aTipo, string aTelefone){
       nome=aNome;
       CPF=aCPF;
       tipoCliente=aTipo;
       telefone=aTelefone;
    }
        class veiculo
        {
        string placa;
        string cor;
        string modelo;
        string marca;
        char tipo;

        public:

        void cadastrarVeiculo(string aPlaca, string aCor, string aModelo, string aMarca, char aTipo){
            placa=aPlaca;
            cor=aCor;
            modelo=aModelo;
            marca=aMarca;
            tipo=aTipo;
        }
    };
};

