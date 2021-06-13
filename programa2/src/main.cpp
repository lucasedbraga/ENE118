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
    int vetInt[] = {1,2,3,4};
    char charVet[] = "Teste";

    imprimeVetor(charVet,5);
    imprimeVetor(vetInt,4);

    Pilha<int>  p1(5);
    Pilha<string> pString(5);

    p1.insere(1);
    p1.insere(2);

    pString.insere("OLA MUNDO");
    pString.insere("GALO");

    int outInt;
    string outStr;
    p1.remove(outInt);
    pString.remove(outStr);
    
    cout<<"Dado removido da pilha de inteiros "<<outInt<<endl;
    cout<<"Dado removido da pilha de Strings "<<outStr<<endl;


    return 0;
} 