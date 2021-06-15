#include <iostream>
#include "sensorindustrial.h"
#include "medicao.h"

using namespace std;

int main()
{
    Medicao meds[] = {{"10:00:00",10},{"10:00:01",11},{"10:00:02",12},{"10:00:03",13},{"10:00:04",14},{"10:00:05",15},{"10:00:06",16},{"10:00:07",17},{"10:00:08",18},{"10:00:09",19},{"10:00:10",20}};

    int numMed = sizeof(meds)/sizeof(meds[0]);

    SensorIndustrial si("S01V","L/s");
    si.lerDados(meds,numMed);
    si.imprimeDados();
    string h = "10:00:04";
    Medicao m1;
    if(si.getDado(h,m1))
    {
        cout<<"Dado obtido no horario "<<h<<" h -> "<< m1.valor<<" "<<si.getUnidade() << endl;
    }
    else
    {
        cout << "Dado nao encontrado" << endl;
    }

    return 0;
} 