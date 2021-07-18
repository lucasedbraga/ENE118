#include "gerente.h"
#include <iostream>

using namespace std;


Gerente::Gerente(int id, int senha) : id(id),senha(senha)
{

}

Gerente::~Gerente()
{
}

bool Gerente::ValidaSenha(int d)
{
    if(this->senha==d)
    {
        return true;
    }
    else
    {
        cout << "Senha incorreta" <<endl;
        return false;
    }
}





