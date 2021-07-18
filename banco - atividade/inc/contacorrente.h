#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include "conta.h"

class ContaCorrente : public Conta
{
private:
    int numCartao;
public:
    ContaCorrente(int senha, const int numero, std::string titular, std::string tipo, double saldo, int& numCartao);
    ~ContaCorrente();
};

#endif