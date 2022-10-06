#pragma once
#include <functional>
#include <iostream>
#include "Nodo.hpp"

template <typename T>
class ListaDoble {
private:
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;
    unsigned int longitudNodo;
public:
    ListaDoble() {
        _cabeza = nullptr;
        _cola = nullptr;
        longitudNodo = 0;
    }
    ~ListaDoble();

// Para insertar
    void pushFront(const T& value);
    void pushBack(const T& value);

// Para eliminar
    void popFront();
    void popBack();

// Para imprimir
    void display();
};


template <typename T>
ListaDoble<T>::~ListaDoble() {
    while (_cabeza != nullptr) {
        popBack();
    }
    
}
template <typename T>
void ListaDoble<T>::pushFront(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);

    nuevoNodo->_siguiente = _cabeza;
    nuevoNodo->_atras = nullptr;

    if (_cabeza != nullptr) {
        _cabeza->_atras = nuevoNodo;
    }
    _cabeza = nuevoNodo;
    longitudNodo++;
    return;
}

template <typename T>
void ListaDoble<T>::pushBack(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);

// Se puede implementar de esta forma:
// FORMA 01:
    // Nodo<T>* aux = _cabeza;

    // nuevoNodo->_siguiente = nullptr;    

    // if (_cabeza == nullptr) {
    //     nuevoNodo->_atras = nullptr;
    //     _cabeza = nuevoNodo;
    //     longitudNodo++;
    //     // delete aux;
    //     return;
    // }

    // while (aux->_siguiente != nullptr) {
    //     aux = aux->_siguiente;
    // }
    // aux->_siguiente = nuevoNodo;
    // nuevoNodo->_atras = aux;
    // longitudNodo++;
    // aux = nullptr;
    // delete aux;

// O de esta otra forma:
// FORMA 02:
    if (longitudNodo == 0) {
        _cabeza = _cola = nuevoNodo;
        longitudNodo++;
        return;
    }
    _cola->_siguiente = nuevoNodo;
    nuevoNodo->_atras = _cola;
    _cola = nuevoNodo;
    nuevoNodo->_siguiente = nullptr;
    longitudNodo++;
    return;
}

template <typename T>
void ListaDoble<T>::popFront() {
    if (longitudNodo != 0) {
        Nodo<T>* aux = _cabeza;
        if (_cabeza == _cola)
            _cola = nullptr;
        _cabeza = _cabeza->_siguiente;
        if (_cabeza != nullptr) 
            _cabeza->_atras = nullptr;
        delete aux;
        longitudNodo--;
    }
}

template <typename T>
void ListaDoble<T>::popBack() {
    if (longitudNodo != 0) {
        Nodo<T>* aux = _cola;
        if (_cabeza == _cola) 
            _cabeza = nullptr;
        _cola = _cola->_atras;
        if(_cola != nullptr)
            _cola->_siguiente = nullptr;
        delete aux;
        longitudNodo--;
    }
}

template <typename T>
void ListaDoble<T>:: display() {
    Nodo<T>* aux = _cabeza;
    while (aux != nullptr) {
        std::cout << aux->_dato << " ";
        aux = aux->_siguiente;
    }
    std::cout << "\nLa longitud del nodo es: " << longitudNodo;
    std::cout << "\n";
}