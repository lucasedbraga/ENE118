#ifndef SENSOR_COM_AJUSTE_H
#define SENSOR_COM_AJUSTE_H
#include "sensorindustrial.h"
#include "medicao.h"

class SensorComAjuste : public SensorIndustrial
{
    private:
        double* coefs;
        int numCoef;
        Medicao* dadosAjustados;
        void ajustarDados();
    public:
        SensorComAjuste(const string&,const string&);
        ~SensorComAjuste();

    //funcoes set
    void setCoef(const double*, const int&);
    void getCoef(int&,double*);

    void lerDados(const Medicao*,const int&);
    void limpaDados();
    void limpaCoefs();
    void imprimeDados();
};

#endif