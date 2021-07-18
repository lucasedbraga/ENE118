#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include "conta.h"

class ContaPoupanca : public Conta
{
private:
    float taxa;
public:
    ContaPoupanca(int senha, const int numero, std::string titular, std::string tipo, double saldo, float taxa);
    ~ContaPoupanca();
    void SimulaRendimento(int num_meses, int senha);
};

#endif