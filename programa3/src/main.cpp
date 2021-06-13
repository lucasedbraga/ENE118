#include <iostream>
#include "fila.hpp"
#include <stdlib.h>
#include <cstring>
#include <string>

using namespace std;

template<typename T>
void imprimeVetor(T*  p,int tam)
{
    for(int i=0; i<tam;i++)
    {
        cout<<"Posicao["<<i<<"] = "<<*(p+i)<<endl;
    }
}

int main()
{
    Fila<int>  p1(5);
    Fila<string> pString(5);

    p1.insere(13);
    p1.insere(49);  
    pString.insere("GALO");
    pString.insere("DOIDO");
    pString.insere("Atletico MG");
    

    int outInt;
    string outStr;
    p1.remove(outInt);
    cout<<"Dado removido da Fila de inteiros "<<outInt<<endl;
    pString.remove(outStr);
    cout<<"Dado removido da Fila de Strings "<<outStr<<endl;
    pString.remove(outStr);
    cout<<"Dado removido da Fila de Strings "<<outStr<<endl;
    pString.remove(outStr);    
    cout<<"Dado removido da Fila de Strings "<<outStr<<endl;


    return 0;
} 