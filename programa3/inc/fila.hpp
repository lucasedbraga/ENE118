#ifndef FILA_H
#define FILA_H

template<typename T>
class Fila
{
    private:
        int tam;
        int top;
        int bottom;
        T *pPtr;
        T *pSaida;
    public:
        Fila(int = 10);
        ~Fila();
        bool insere(const T&);
        bool remove(T&);
        bool estaVazia() const;
        bool estaCheia() const;
};



template <typename T>
Fila<T>::Fila(int t)
{
    this->tam = t > 0 ? t:10;
    this->top = -1;
    this->bottom = 0;
    this->pPtr = new T[this->tam];
    this->pSaida = this->pPtr;
};

template<typename T>
Fila<T>::~Fila()
{
    delete[] this->pPtr;
    delete[] this->pSaida;
};


template<typename T>
bool Fila<T>::insere(const T& valor)
{
    if(!estaCheia())
    {
        pPtr[++top] = valor; // Operação de pré incremento em top, antes da instrução aula4-20min
        return true;
    }
    else
    {
        return false;
    }
};


template<typename T>
bool Fila<T>::remove(T& var)
{
    if(!estaVazia())
    {
        var = pSaida[bottom++]; // Operação de pós incremento em top, após retirar o valor aula4-22min
        return true;
    }
    else
    {
        return false;
    }
};

template<typename T>
bool Fila<T>::estaVazia() const
{
    return top == -1;
};


template<typename T>
bool Fila<T>::estaCheia() const
{
    return top == tam -1;
};

#endif