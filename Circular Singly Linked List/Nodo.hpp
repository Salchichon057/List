#pragma once

template <typename T>
struct Nodo
{
    T _dato;
    Nodo<T>* _siguiente;

    Nodo(T dato) : _dato(dato) , _siguiente(nullptr) {}
};