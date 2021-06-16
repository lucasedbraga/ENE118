#include "sensorindustrial.h"
#include "sensorcomajuste.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

SensorComAjuste::SensorComAjuste(const string& id,const string& un) : SensorIndustrial::SensorIndustrial(id,un), dadosAjustados(nullptr), coefs(nullptr), numCoef(0)
{
    this->coefs = new double[2];
    this->coefs[0] = 0;
    this->coefs[1] = 1.0;
    this->numCoef = 2;
}

SensorComAjuste::~SensorComAjuste()
{
    this->limpaDados();
    this->limpaCoefs();
    cout << "Destrutor da classe SensorComAjuste invocado"<<endl;
}

void SensorComAjuste::setCoef(const double* coefs, const int& numcoefs)
{
    this->limpaCoefs();
    this->numCoef = numcoefs;
    this->coefs = new double[this->numCoef];

    for(int i=0; i<this->numCoef;i++)
    {
        this->coefs[i] = coefs[i];
    }
    this->ajustarDados();
}

void SensorComAjuste::getCoef(int& ncoef, double* coefs)
{
    ncoef = this->numCoef;
    coefs = this->coefs;
}

void SensorComAjuste::lerDados(const Medicao* m, const int& ndados)
{
    this->limpaDados();
    SensorIndustrial::lerDados(m,ndados);
    this->dadosAjustados = new Medicao[ndados];
    this->ajustarDados();
}

void SensorComAjuste::limpaDados()
{
    SensorIndustrial::limpaDados();
    if(this->dadosAjustados!=nullptr)
    {
        delete[] this->dadosAjustados;
        this->dadosAjustados = nullptr;
    }
}

void SensorComAjuste::limpaCoefs()
{
    if(this->coefs != nullptr)
    {
        delete[] this->coefs;
        this->numCoef = 0;
    }
}

void SensorComAjuste::ajustarDados()
{
    if(this->dadosAjustados != nullptr)
    {
        memset(this->dadosAjustados,0,this->getNumMed()*sizeof(Medicao));       
        for(int i = 0; i<this->getNumMed(); i++)
        {
            this->dadosAjustados[i].horario = this->dados[i].horario;
            for(int c=0; c<this->numCoef; c++)
            {
                this->dadosAjustados[i].valor += this->coefs[c]*pow(this->dados[i].valor,c);
            }
        }
    }
}

void SensorComAjuste::imprimeDados()
{
     cout<<" Dados ajustados do Sensor " << this->getId() << " : " <<endl;
    for(int i=0; i < this->getNumMed(); i++)
    {
    cout<<"Horario: "<< this->dadosAjustados[i].horario <<"h | Valor: "<<this->dadosAjustados[i].valor<< " "<< this->getUnidade()<<endl;
    }

}
