#include <iostream>
#include "Nodo.hpp"

template<typename T>
class CircularDoble
{
private:
    Nodo<T>* _cabeza;
    Nodo<T>* _cola;
    unsigned int longitudNodo;
public:
    CircularDoble() : _cabeza(nullptr) , _cola(nullptr) , longitudNodo(0) { }
    ~CircularDoble();

// Para insertar
    void pushFront(const T& value);
    void pushBack(const T& value);

// Para eliminar
    void popFront();
    void popBack();

// Para imprimir
    void display();
};

template<typename T>
CircularDoble<T>::~CircularDoble() {
    while (_cabeza != nullptr) {
        popBack();
    }
}

template <typename T>
void CircularDoble<T>::pushFront(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);

    nuevoNodo->_siguiente = _cabeza;

    if (_cabeza == nullptr) {
        _cabeza = _cola = nuevoNodo;
        _cola->_siguiente = _cabeza;
        _cabeza->_atras =_cola;
        longitudNodo++;
        return;
    }
    
    _cabeza->_atras = nuevoNodo;
    _cola->_siguiente = nuevoNodo;
    nuevoNodo->_atras = _cola;
    _cabeza = nuevoNodo;
    longitudNodo++;
    return;
}

template <typename T>
void CircularDoble<T>::pushBack(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if (longitudNodo == 0) {
        _cabeza = _cola = nuevoNodo;
        _cola->_siguiente = _cabeza;
        _cabeza->_atras =_cola;
        longitudNodo++;
        return;
    }
    _cola->_siguiente = nuevoNodo;
    nuevoNodo->_atras = _cola;
    _cola = nuevoNodo;
    nuevoNodo->_siguiente = _cabeza;
    _cabeza->_atras = nuevoNodo;    
    longitudNodo++;
    return;
}

template <typename T>
void CircularDoble<T>::popFront() {
    if (longitudNodo != 0) {
        Nodo<T>* aux = _cabeza;
        if (_cabeza == _cola) {
            _cabeza =  _cola = nullptr;
            aux = nullptr;
            delete aux;
            longitudNodo--;
            return;
        }
        _cabeza = _cabeza->_siguiente; // Reposicion
        _cabeza->_atras = _cola;
        _cola->_siguiente = _cabeza;

        aux = nullptr;
        delete aux;
        longitudNodo--;
    }
}

template <typename T>
void CircularDoble<T>::popBack() {
    if (longitudNodo != 0) {
        Nodo<T>* aux = _cola;
        if (_cabeza == _cola){
            _cabeza =  _cola = nullptr;
            aux = nullptr;
            delete aux;
            longitudNodo--;
            return; 
        }
        _cola = _cola->_atras;
        _cola->_siguiente = _cabeza;
        _cabeza->_atras = _cola;
        aux = nullptr;
        delete aux;
        longitudNodo--;
    }
}

template <typename T>
void CircularDoble<T>:: display() {
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