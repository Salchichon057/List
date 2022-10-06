#pragma once

template<typename T>
struct Nodo {
    T _dato;
    Nodo<T>* _siguiente;
    Nodo<T>* _atras;

    // Se le inserta un tipo de dato
    Nodo(T dato) : _dato(dato) , _siguiente(nullptr) , _atras(nullptr){}
};