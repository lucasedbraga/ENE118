#ifndef GERENTE_H
#define GERENTE_H

using namespace std;

class Gerente
{
private:
    int senha;
public:
    Gerente(int id, int senha);
    ~Gerente();
    const int id;
    bool ValidaSenha(int d);
};


#endif