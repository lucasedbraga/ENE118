#include "conta.h"
#include <iostream>

Conta::Conta()
{
    this->numero =0;
    this->senha = 1111;
    this->titular = "Nenhum";
    this->saldo = 0;
}

Conta::Conta(int senha, int numero, std::string titular, double saldo)
{
    this->numero = numero;
    this->senha = senha;
    this->titular = titular;
    if(saldo>0)
    {
        this->saldo = saldo;
    }
    else
    {
        std::cout<<"Saldo Inválido"<<std::endl;
        this->saldo = 0;
        std::cout<<"Saldo Padrão Definido"<<std::endl;
    }
}

Conta::~Conta()
{
    std::cout<<"Destrutor da conta "<<this->numero<<" foi invocado"<<std::endl;
}


void Conta::exibeDados()
{
    std::cout<<"Titular: "<<this->titular<<std::endl;
    std::cout<<"Numero: "<<this->numero<<std::endl;
    std::cout<<"Saldo Atual: "<<this->saldo<<std::endl;

}

double Conta::getSaldo(int senha)
{
    if(senha==this->senha)
    {
        return this->saldo;
    }
    else
    {
        std::cout<<"Senha Incorreta"<<std::endl;
        return -10000000;
    } 
}

void Conta::setSaldo(double valor)
{
    this->saldo = valor;
}

void Conta::setSenha(int novaSenha)
{
    this->senha = novaSenha;
}

void Conta::deposito(double valor)
{
    if(valor>0)
    {
        this->saldo+=valor;
    }
    else
    {
        std::cout<<"Valor Inválido"<<std::endl;
    }
}


void Conta::saque(int senha, double valor)
{
    if(senha==this->senha)
    {
        if(this->saldo>valor)
        {
            this->saldo-=valor;
            std::cout<<"Saque de R$ "<<valor<<" realizado com sucesso."<<std::endl;
        }
        else
        {
            std::cout<<"Saldo Insuficiente"<<std::endl;
        }

    }
    else
    {
        std::cout<<"Senha Inválida"<<std::endl;
    }
}

void Conta::transferencia(int senha, Conta* remetente, double valor, int numero_destinatario, Conta* destinatario)
{   
    int senha_remetente = remetente->senha;
    if(senha==senha_remetente)    
    {
        if(valor<=this->saldo)
        {
            if(remetente->numero==this->numero)
            {
               if(numero_destinatario==destinatario->numero)
                {
                    this->saldo-=valor;
                    destinatario->deposito(valor);
                    std::cout<<">>> Transferencia Realizada <<<"<<std::endl;
                }
            }  
            else
            {
                std::cout<<"Erro na Transferencia"<<std::endl;
            }

        }
        else
        {
            std::cout<<">>> Saldo Insuficiente! <<<"<<std::endl;
        }
    }
    else
    {
        std::cout<<"Senha Inválida!"<<std::endl;
    } 
}