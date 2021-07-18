#include  "contacorrente.h"
#include "conta.h"
#include <iostream>


ContaCorrente::ContaCorrente(int senha, const int numero, std::string titular, std::string tipo, double saldo, int& numCartao) : Conta::Conta(senha, numero, titular, tipo,saldo)
{
    this->numCartao;
}
