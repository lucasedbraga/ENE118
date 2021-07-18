#ifndef CONTASCADASTRADAS_H
#define CONTASCADASTRADAS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ContasCadastradas
{
private:
    string senha;
    string numero;
    string titular;
    string tipo;
    string saldo;
    string numero_cartao;

public:
    ContasCadastradas(vector<string>& v);
    ~ContasCadastradas();
    void salvarDados(vector<string>& v);

};

#endif
