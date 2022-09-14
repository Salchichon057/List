#ifndef __LISTA__
#define __LISTA__
#include <functional>
#include "Nodo.hpp"

template<typename T>
class ListaSimple    
{
private:
    Nodo<T>* _cabeza;
    int longitudNodo;
public:
    ListaSimple() : _cabeza(nullptr), longitudNodo(0) {}
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
    while (_cabeza != nullptr)
    {
        temporal = _cabeza;
        _cabeza = _cabeza->_siguiete;
        delete temporal;
        temporal = nullptr;
    }
    delete _cabeza;
    _cabeza = nullptr;
}

template <typename T>
void ListaSimple<T>::pushFront(const T& value){
    Nodo<T>* nuevo_Nodo  = new Nodo<T>(value);
    if (_cabeza == nullptr) {
        _cabeza = nuevo_Nodo;
        longitudNodo++;
        return;
    }
    else {
        nuevo_Nodo->_siguiete = _cabeza; // conectando
        _cabeza = nuevo_Nodo;
    }
    longitudNodo++;
}

template <typename T>
void ListaSimple<T>::pushBack(const T& value){
    Nodo<T>* nuevo_Nodo  = new Nodo<T>(value);
    Nodo<T>* aux = _cabeza;
    if (_cabeza == nullptr) {
        _cabeza = nuevo_Nodo;
        return;
    }
    while (aux->_siguiete != nullptr)
    {
        aux = aux->_siguiete;
    }
    aux->_siguiete = nuevo_Nodo;
    aux = nullptr;
    longitudNodo++;
    delete aux;
}

template <typename T>
void ListaSimple<T>::popFront(){
    Nodo<T>* temporal = _cabeza;
    _cabeza = _cabeza->_siguiete;
    longitudNodo--;
    delete temporal;
}
template <typename T>
void ListaSimple<T>::eliminaPosicion(int posicion) {
    // Profe
    if (posicion < longitudNodo)
    {
        if (posicion == 0)
        {
            popFront();
        }
        else {
            // Mover los punteros a la posición a eliminar | Mover los punteros a la posición anterior
            Nodo<T>* aux = _cabeza;
            Nodo<T>* aux2;
            // Porque ya se había inicializado se pone i = 1
            for (int i = 1; i < posicion; i++)
            {
                aux = aux->_siguiete;
            }
            aux2 = aux->_siguiete;
            // actualizar punteros
            aux->_siguiete = aux2->_siguiete;
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
    while (final->_siguiete != nullptr)
    {
        aux = final;
        final = final->_siguiete;
    }
    aux->_siguiete = nullptr;
    delete final;
    longitudNodo--;
}
template <typename T>
void ListaSimple<T>:: display() {
    Nodo<T>* aux = _cabeza;
    while (aux != nullptr)
    {
        std::cout << aux->_dato << " ";
        aux = aux->_siguiete;
    }
    std::cout << "\nLa longitud del nodo es: " << longitudNodo;
    std::cout << "\n";
}
#endif 