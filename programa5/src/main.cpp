#include <iostream>
#include "sensorvazao.h"
#include <vector>

using namespace std;

int main()
{
    vector<string> h = {"id","unidade","Numero de amostras","Periodo de amostragem (s)"};
    SensorVazao sensor("C:\\Users\\lucas\\Lucas\\scripts\\ENE118\\programa5\\dados\\dados.csv",h);
    sensor.lerDados();
    sensor.imprimeDados();
    string hora = "07:17:00";
    double d;
    if(sensor.getDado(hora,d))
    {
        cout << "Dado encontrado. Valor: "<<d<<sensor.getUnidade()<<endl;
    }
    else
    {
        cout <<"Dado nao encontrado"<<endl;
    }

    int resp = sensor.salvarDados("C:\\Users\\lucas\\Lucas\\scripts\\ENE118\\programa5\\dados\\dadosSalvos.csv","07:16:55","07:16:57");

    if(resp==0)
    {
        cout<<"Dados salvos com sucesso"<<endl;
    }
    else
    {
    cout<<"ERRO: "<<resp;
    }

    return 0;
}