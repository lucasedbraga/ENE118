#include "sensorvazao.h"
#include <iostream>

using namespace std;

SensorVazao::SensorVazao(const string &path, const vector<string> &h) : id("desconhecido"), unidade("desconhecida"), numMed(0)
{
    this->headers.assign(h.begin(), h.end());
    this->abrirArquivo(path);
}

SensorVazao::~SensorVazao()
{
    this->file.close();
}

bool SensorVazao::abrirArquivo(const string &path)
{
    try
    {
        this->file.open(path);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return false;
}

bool SensorVazao::lerDados() //*****
{
    try
    {
        if (this->file.is_open())
        {
            string d;
            getline(this->file, d);
            int n = 0;
            int idx;
            vector<string> dadosHeader(this->headers.size());
            while (n < this->headers.size())
            {
                getline(this->file, d);
                idx = d.find(":");
                if (d.substr(0, idx) == this->headers[n])
                {
                    dadosHeader[n] = d.substr(idx + 1, d.length() - idx);
                    n++;
                }
                else
                {
                    return false;
                }
            }
            this->id = dadosHeader[0];
            this->unidade = dadosHeader[1];
            this->numMed = stod(dadosHeader[2]);
            this->Ts = stod(dadosHeader[3]);

            Medicao m;
            getline(this->file, d);
            for (int i = 0; i < this->numMed; i++)
            {
                getline(this->file, d);
                idx = d.find(",");
                m.horario = d.substr(0, idx);
                m.valor = stod(d.substr(idx + 1, d.length() - idx));
                this->dados.push_back(m);
            }
        }
        else
        {
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Arquivo corrompido. Erro:" << e.what() << '\n';
    }
    return true;
}

void SensorVazao::imprimeDados()
{
    cout << "Sensor Vazão" << endl;
    cout << "ID : " << this->getId() << endl;
    cout << "Numero de Amostras : " << this->getNumMed() << endl;
    cout << "Periodo de Amostragem : " << this->getPeriodoAmostragem() << endl;

    for (auto it = this->dados.begin(); it != this->dados.end(); it++)
    {

        cout << "Horario : " << it->horario << "h | Valor" << it->valor << " " << this->getUnidade() << endl;
    }
}

string SensorVazao::getId()
{
    return this->id;
}

string SensorVazao::getUnidade()
{
    return this->unidade;
}

int SensorVazao::getNumMed()
{
    return this->numMed;
}

int SensorVazao::getPeriodoAmostragem()
{
    return this->Ts;
}

bool SensorVazao::getDado(const string &horario, double &dado)
{
    for (auto it = this->dados.begin(); it != this->dados.end(); it++)
    {

        if (it->horario == horario)
        {
            dado = it->valor;
            return true;
        }
    }
    return false;
}

int SensorVazao::salvarDados(const string &path, const string &horai, const string &horaf)
{
    bool flags[2] = {false, false};
    try
    {
        ofstream ofile;
        ofile.open(path, std::ios_base::out | std::ios_base::trunc);
        if (ofile.is_open())
        {
            ofile << "Dados sensor de vazão" << endl;
            ofile << "ID: " << this->getId() << endl;
            ofile << "Unidade: " << this->getUnidade() << endl;
            ofile << "Numero de Amostras: " << this->getNumMed() << endl;
            ofile << "Periodo de Amostragem: " << this->getPeriodoAmostragem() << endl;
            ofile << "Horario,dado " << endl;
            for (auto it = this->dados.begin(); it != this->dados.end(); it++)
            {

                if (it->horario == horai)
                {
                    flags[0] = true;
                }
                if (flags[0] && ~flags[1])
                {
                    ofile << it->horario << "," << it->valor << endl;
                }
                if (it->horario == horaf)
                {
                    flags[1] == true;
                    return 0;
                }
            }
        }
        else
        {
            return -1;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    if (flags[0] && ~flags[1])
    {
        return 1; //apenas o horario inicial encontrado
    }
    else
    {
        return 2; //nenhum horario encontrado ou apenas o final
    }
}