#ifndef BANCO_H
#define BANCO_H
#include "conta.h"
#define MAXCONTAS 100

class Banco
{
private:
    //Vetor que armazena as informações das contas do banco
    Conta contas[MAXCONTAS];
public:
    Banco();
    ~Banco();
    // Funcionalidade que permite obter o ponteiro de uma conta a partir de seu número
    Conta* buscaConta(int numero);
    // Funcionalidade que cria uma interface de atendimento ao cliente
    void atendimento();
};

#endif