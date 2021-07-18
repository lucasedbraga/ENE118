#include "banco.h"
#include "gerente.h"
#include "separa.h"
#include <iostream>
#include <fstream>

using namespace std;

Banco::Banco()
{
    this->header = {"Contas cadastradas"};
    this->abrirBancoDados("C:\\Users\\lucas\\Lucas\\scripts\\ENE118\\banco - atividade\\dados\\contasbanco.csv");
    this->gerente = new Gerente(12, 13);
}

Banco::~Banco()
{
    this->file.close();
    delete this->gerente;
    delete[] this->bancodedados;
}

Conta *Banco::buscaConta(int numero)
{
    for (int i = 0; i < MAXCONTAS; ++i)
    {
        if (numero == this->contas[i].numero)
        {
            return &contas[i];
        }
    }
    return nullptr;
}

void Banco::atendimento()
{
    Conta *contaCliente;
    int numC = 0;
    int senhain;
    bool atendimento = true;

    cout << "Bem vindo ao sistema de atendimento do banco" << endl;
    cout << "Digite o numero de sua conta: ";
    cin >> numC;

    contaCliente = buscaConta(numC);

    if (contaCliente == nullptr)
    {
        cout << "Conta invalida" << endl;
    }
    else
    {
        cout << "Digite sua senha: ";
        cin >> senhain;
        if (contaCliente->validaSenha(senhain))
        {
            cout << "Ola " << contaCliente->titular << endl;
            while (atendimento)
            {
                int op;
                double valor;
                cout << "Qual operacao deseja realizar? (1 - Saque, 2 - Deposito, 3 - Ver Saldo, 4 - Voltar ao menu inicial, 5 - Sair): ";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "Digite o valor: ";
                    cin >> valor;
                    contaCliente->saque(senhain, valor);
                    break;
                case 2:
                    cout << "Digite o valor: ";
                    cin >> valor;
                    contaCliente->deposito(valor);
                    break;
                case 3:
                    cout << "Saldo R$ " << contaCliente->getSaldo(senhain) << endl;
                    break;
                case 4:
                    this->atendimento();
                    break;
                case 5:
                    atendimento = false;
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "Senha invalida, acesso negado" << endl;
        }
    }
}

void Banco::login()
{
    bool status = true;
    while (status)
    {
        int key = 0;
        cout << "Voce eh? " << endl;
        cout << "1- Cliente " << endl;
        cout << "2- Gerente" << endl;
        cin >> key;
        switch (key)
        {
        case 1:
            status = false;
            atendimento();
        case 2:
            try
            {
                int id;
                int senha;
                cout << "Informe o Id" << endl;
                cin >> id;
                cout << "Informe a senha" << endl;
                cin >> senha;
                if (ValidaGerente(id, senha))
                {
                    status = false;
                    atendimento_gerente();
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
    }
}

void Banco::atendimento_gerente()
{

    int numC = 0;
    int senhain;
    bool atendimento = true;

    cout << "Ola Gerente ID:" << this->gerente->id << endl;
    while (atendimento)
    {
        int op;
        double valor;
        cout << "Qual operacao deseja realizar? (1 - Contas Cadastradas, 2 - Criar Conta, 3 - Sair): ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Contas Cadastradas " << endl;
            lerContas();
            cout << this->numCadastro;
            break;
        case 2:
            cout << "Criar Conta" << endl;
            cout << "Insira a senha" << endl;
            int senha;
            cin >> senha;
            CriarConta(senha);
            break;
        case 3:
            atendimento = false;
            break;
        default:
            break;
        }
    }
}

bool Banco::abrirBancoDados(const string &path)
{
    try
    {
        this->file.open(path);
        try
        {
            if (this->file.is_open())
            {
                string d;
                getline(this->file, d);
                int n = 0;
                int idx;
                vector<string> dadosHeader(this->header.size());
                while (n < this->header.size())
                {
                    getline(this->file, d);
                    idx = d.find(":");
                    if (d.substr(0, idx) == this->header[n])
                    {
                        dadosHeader[n] = d.substr(idx + 1, d.length() - idx);
                        n++;
                    }
                    else
                    {
                        return false;
                    }
                }
                this->numCadastro = stod(dadosHeader[0]);
                cout << this->numCadastro << endl;
                int tam = this->numCadastro;
                vector<string> cadastros[tam];
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Arquivo corrompido. Erro:" << e.what() << '\n';
        }
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return false;
}

bool Banco::lerContas()
{

    try
    {

        if (this->file.is_open())
        {
            string d;
            for (int i = 0; i < this->numCadastro; i++)
            {
                getline(this->file, d);
                string leitura = d;
                vector<string> v = separar_csv(leitura);
                cout << " " << endl;
                cout << "senha = " << v[0] << endl;
                cout << "numero = " << v[1] << endl;
                cout << "titular = " << v[2] << endl;
                cout << "tipo = " << v[3] << endl;
                cout << "saldo = " << v[4] << endl;
                cout << "numero cartao = " << v[5] << endl;
                cout << " " << endl;
                this->bancodedados = new ContasCadastradas(v);
            }
        }
    }

    catch (const std::exception &e)
    {
        std::cout << "Arquivo corrompido. Erro:" << e.what() << '\n';
    }
    return true;
}

void Banco::CriarConta(int senha)
{

    if (this->gerente->ValidaSenha(senha))
    {
        cout << "Qual o tipo de conta? " << endl;
    }
    else
    {
        cout << "Senha invalida " << endl;
    }
}

bool Banco::ValidaGerente(int id, int senha)
{

    if (id == this->gerente->id)
    {
        if (this->gerente->ValidaSenha(senha))
        {
            return true;
        }
    }
    else
    {
        cout << "Id inexistente" << endl;
    }
    return false;
}