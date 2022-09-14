#ifndef __NODO__
#define __NODO__

template<typename T>
struct Nodo
{
    T _dato;
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;
    Nodo(T dato) : _dato(dato) , _cabeza(nullptr) , _cola(nullptr){}
};
#endif