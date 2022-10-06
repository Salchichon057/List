#pragma once
#include <functional>
#include "Nodo.hpp"

template<typename T>
class ListaSimple    
{
private:
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;
    int longitudNodo;
public:
    ListaSimple() : _cabeza(nullptr), _cola(nullptr) , longitudNodo(0) {}
    ~ListaSimple ();

    void pushFront(const T& value);
    void pushBack(const T& value);
    void popFront();
    void popBack();
    void eliminaPosicion(int posicion);
    void display();
};

// ----------
template <typename T>
ListaSimple<T>::~ListaSimple(){
    Nodo<T>* temporal;
    while (_cabeza != nullptr){
        temporal = _cabeza;
        _cabeza = _cabeza->_siguiente;
        delete temporal;
        temporal = nullptr;
    }
    longitudNodo = 0;
    delete _cabeza;
}

template <typename T>
void ListaSimple<T>::pushFront(const T& value){
    Nodo<T>* nuevo_Nodo  = new Nodo<T>(value);
    if (_cabeza == nullptr) {
        _cabeza = _cola= nuevo_Nodo;
        longitudNodo++;
        return;
    }
    nuevo_Nodo->_siguiente = _cabeza; // conectando
    _cabeza = nuevo_Nodo; // Reposicionando
    longitudNodo++;
    return;
}

template <typename T>
void ListaSimple<T>::pushBack(const T& value){
    Nodo<T>* nuevo_Nodo  = new Nodo<T>(value);
    if (_cabeza == nullptr) {
        _cabeza = _cola= nuevo_Nodo;
        longitudNodo++;
        return;
    }

    _cola->_siguiente= nuevo_Nodo;
    nuevo_Nodo->_siguiente = nullptr;
    _cola = nuevo_Nodo;
    longitudNodo++;
    return;
}

template <typename T>
void ListaSimple<T>::popFront(){
    Nodo<T>* temporal = _cabeza;
    if (_cabeza == nullptr){
        return;
    }
    _cabeza = _cabeza->_siguiente;
    longitudNodo--;
    delete temporal;
}
template <typename T>
void ListaSimple<T>::eliminaPosicion(int posicion) {
    // Profe
    if (posicion < longitudNodo){
        if (posicion == 0){
            popFront();
        }
        else {
            // Mover los punteros a la posición a eliminar | Mover los punteros a la posición anterior
            Nodo<T>* aux = _cabeza;
            Nodo<T>* aux2;
            // Porque ya se había inicializado se pone i = 1
            for (int i = 1; i < posicion; i++) {
                aux = aux->_siguiente;
            }
            aux2 = aux->_siguiente;
            // actualizar punteros
            aux->_siguiente = aux2->_siguiente;
            delete aux2;
            longitudNodo--;
        }
    }
}

template <typename T>
void ListaSimple<T>::popBack(){
    //  eliminaPos(longitudNodo - 1);
    Nodo<T>* final  = _cabeza;
    Nodo<T>* aux = nullptr;
    if (final == nullptr) {
        return;
    }
    while (final->_siguiente != nullptr) {
        aux = final;
        final = final->_siguiente;
    }
    aux->_siguiente = nullptr;
    _cola = aux;
    aux = nullptr;
    final = nullptr;
    delete aux;
    delete final;
    longitudNodo--;
}

template <typename T>
void ListaSimple<T>:: display() {
    Nodo<T>* aux = _cabeza;
    while (aux != nullptr) {
        std::cout << aux->_dato << " ";
        aux = aux->_siguiente;
    }
    std::cout << "\nLa longitud del nodo es: " << longitudNodo;
    std::cout << "\n";
}