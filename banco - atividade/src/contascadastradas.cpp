#include "contascadastradas.h"
#include <string>
#include <vector>
using namespace std;

ContasCadastradas::ContasCadastradas(vector<string> &v)
{
    this->senha = v[0];
    this->numero = v[1];
    this->titular = v[2];
    this->tipo = v[3];
    this->saldo = v[4];
    this->numero_cartao = v[5];
    this->salvarDados(v);
}

ContasCadastradas::~ContasCadastradas()
{
}

void ContasCadastradas::salvarDados(vector<string> &v)
{
    bool flags[2] = {false, false};
    string path = "C:\\Users\\lucas\\Lucas\\scripts\\ENE118\\banco - atividade\\dados\\cadastro.csv";
    try
    {
        ofstream ofile;
        ofile.open(path, std::ios_base::out | std::ios_base::trunc);
        if (ofile.is_open())
        {
            ofile << "CONTAS CADASTRADAS" << endl;
            ofile << "Senha: " << this->senha << endl;
            ofile << "Numero: " << this->numero << endl;
            ofile << "Titular: " << this->titular << endl;
            ofile << "Tipo: " << this->tipo << endl;
            ofile << "TSaldo: " << this->saldo << endl;
            ofile << "Numero_Cartao: " << this->numero_cartao << endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
