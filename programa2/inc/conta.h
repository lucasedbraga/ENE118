#ifndef CONTA_H
#define CONTA_H
#include <string>

class Conta
{
private:
    double saldo;
    int senha;
public:
    Conta();
    Conta(int senha, int numero, std::string titular, double saldo);
    ~Conta();
    int numero;
    std::string titular;
    void exibeDados();
    double getSaldo(int senha);
    void setSaldo(double valor);
    void setSenha(int novaSenha);
    void deposito(double valor);
    void saque(int senha, double valor);
    void transferencia(int senha, Conta* remetente, double valor, int numero_destinatario, Conta* destinatario);  // Transferência Entre Contas

};

#endif 