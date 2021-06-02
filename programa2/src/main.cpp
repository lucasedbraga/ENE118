#include <iostream>
#include "conta.h"
#include <stdlib.h>
#include <cstring>

using namespace std;

int main()
{
   Conta contas[3]={{1234, 01, "Lucas", 500},{1234, 02, "Liliam", 200},{1234, 03, "Tardelli", 100}};
   contas[0].exibeDados();
   contas[1].exibeDados();  
   contas[0].transferencia(1234,&contas[0],200,02,&contas[1]);
   contas[0].exibeDados();
   contas[1].exibeDados();
   contas[0].exibeDados();
   contas[2].exibeDados();
   contas[0].transferencia(1234,&contas[0],400,03,&contas[2]);
   contas[0].exibeDados();
   contas[2].exibeDados();

    

    return 0;
} 