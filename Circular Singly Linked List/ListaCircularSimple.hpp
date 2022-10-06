#pragma once
#include <functional>
#include <iostream>
#include "Nodo.hpp"

template<typename T>
class ListaCircularSimple
{
private:
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;

    unsigned int longitudNodo;
    
public:
    ListaCircularSimple() : _cabeza(nullptr) , _cola(nullptr) , longitudNodo(0){}
    ~ListaCircularSimple();

// insertar
    void pushFront(const T& value);
    void pushBack(const T& value);

// eliminar
    void popFront();
    void popBack();

//  mostrar
    void display();
};

template <typename T>
ListaCircularSimple<T>::~ListaCircularSimple(){}

template <typename T>
void ListaCircularSimple<T>::pushFront(const T& value){
    Nodo<T>* nuevoNodo  = new Nodo<T>(value);
    if (longitudNodo == 0) {
        _cabeza = _cola = nuevoNodo;
        _cola->_siguiente = _cabeza;
        longitudNodo++;
        return;
    }
    nuevoNodo->_siguiente = _cabeza; // conectando
    _cabeza = nuevoNodo; // Reposicionando
    _cola->_siguiente = _cabeza;
    longitudNodo++;
    return;
}

template <typename T>
void ListaCircularSimple<T>::pushBack(const T& value){
    Nodo<T>* nuevoNodo  = new Nodo<T>(value);
    Nodo<T>* aux = _cabeza;
    if (longitudNodo == 0) {
        _cabeza = _cola = nuevoNodo;
        _cola->_siguiente = _cabeza;
        longitudNodo++;
        return;
    }
    while (aux->_siguiente != _cabeza){
        aux = aux->_siguiente;
    }
    aux->_siguiente = nuevoNodo;
    _cola = nuevoNodo;
    nuevoNodo->_siguiente = _cabeza;
    aux = nullptr;
    longitudNodo++;
    delete aux;
    return;
}

template <typename T>
void ListaCircularSimple<T>::popFront(){
    Nodo<T>* aux = _cabeza;
    if (_cabeza == _cola){
        aux = nullptr;
        delete aux;
        return;
    }
    _cabeza = _cabeza->_siguiente;
    aux = nullptr;
    _cola->_siguiente = _cabeza;
    delete aux;
    longitudNodo--;
}

template <typename T>
void ListaCircularSimple<T>::popBack(){
    Nodo<T>* final  = _cabeza;
    Nodo<T>* aux = nullptr;
    if (final == nullptr) {
        return;
    }
    while (final->_siguiente != _cabeza) {
        aux = final;
        final = final->_siguiente;
    }
    aux->_siguiente = _cabeza;
    _cola = aux;

    final = nullptr;
    aux = nullptr;
    delete final;
    delete aux;
    longitudNodo--;
}

template <typename T>
void ListaCircularSimple<T>:: display() {
    Nodo<T>* aux = _cabeza;
    do
    {
        if (longitudNodo == 0) {
            break;
        }
        std::cout << aux->_dato << " ";
        aux = aux->_siguiente;
    } while (aux != _cabeza);
    
    std::cout << "\nLa longitud del nodo es: " << longitudNodo;
    std::cout << "\n";
}
