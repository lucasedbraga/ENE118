#ifndef BANCO_H
#define BANCO_H
#include "conta.h"
#include "gerente.h"
#include <vector>
#include <fstream>
#include "contascadastradas.h"
#define MAXCONTAS 100

class Banco
{
private:
    //Vetor que armazena as informações das contas do banco
    Conta contas[MAXCONTAS];
    Gerente* gerente;
    vector<string> header;
    vector<Conta> dados;
    ifstream file;
    double numCadastro;
    ContasCadastradas *bancodedados;
    
public:
    Banco();
    ~Banco();
    bool abrirBancoDados(const string&);
    // Funcionalidade que permite obter o ponteiro de uma conta a partir de seu número
    Conta* buscaConta(int numero);
    void CriarConta(int senha);
    bool ValidaGerente(int id, int);
    // Funcionalidades que de Banco de Dados
    bool lerContas();
    void CadastroCliente();
    void VerContasCadastradas(); 
    // Funcionalidade que cria uma interface de atendimento ao cliente
    void atendimento();
    void atendimento_gerente();
    void login();
};

#endif