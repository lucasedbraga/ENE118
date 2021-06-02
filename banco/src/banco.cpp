#include "banco.h"
#include <iostream>

using namespace std;

Banco::Banco()
{
    this->contas[0] = {1234, 1, "Jose", "Corrente", 300};
    this->contas[1] = {4567, 2, "João", "Poupanca", 800};
    this->contas[2] = {7890, 3, "Maria", "Corrente", 1000};
    this->contas[3] = {8956, 4, "Madalena", "Poupanca", 2000};
}

Banco::~Banco()
{
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
                    contaCliente->saque(senhain,valor);
                    break;
                case 2:
                    cout << "Digite o valor: ";
                    cin >> valor;
                    contaCliente->deposito(valor);
                    break;
                case 3:
                    cout << "Saldo R$ " << contaCliente->getSaldo(senhain) <<endl;
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
