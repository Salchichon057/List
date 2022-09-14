#ifndef __NODO__
#define __NODO__
#include <iostream>

template <typename T>
struct Nodo
{
    T _dato;    
    Nodo<T>* _siguiete;
    Nodo(T dato) : _dato(dato) , _siguiete(nullptr){}
};

#endif