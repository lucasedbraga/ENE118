#ifndef SENSOR_VAZAO_H
#define SENSOR_VAZAO_H

#include <vector>
#include <fstream>
#include "medicao.h"

using namespace std;

class SensorVazao
{
private:
   vector<Medicao> dados;
   vector<string> headers;
   string id;
   string unidade;
   int numMed;
   int Ts;
   ifstream file;
public:
    SensorVazao(const string&, const vector<string>&);
    ~SensorVazao();
    bool abrirArquivo(const string&);
    bool lerDados();
    void imprimeDados();
    string getId();
    string getUnidade();
    int getNumMed();
    int getPeriodoAmostragem();
    bool getDado(const string&, double&);
    int salvarDados(const string&, const string&, const string&);
};

#endif