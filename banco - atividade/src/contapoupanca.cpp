#include "contapoupanca.h"
#include "conta.h"
#include <iostream>
#include <cmath>

ContaPoupanca::ContaPoupanca(int senha, const int numero, std::string titular, std::string tipo, double saldo, float taxa) : Conta::Conta(senha, numero, titular, tipo, saldo),taxa(taxa)
{
}

ContaPoupanca::~ContaPoupanca()
{
}

void ContaPoupanca::SimulaRendimento(int num_meses, int senha)
{
    if (validaSenha(senha))
    {
        float i = this->taxa;
        double c = this->getSaldo(senha);
        float M = c*pow(((1 + i)), num_meses);

        std::cout << "Rendimento do saldo " << c << "$ em " << num_meses << "meses a uma taxa de " << i << " tera montante = " << M << "$ " << std::endl;
    }
}
