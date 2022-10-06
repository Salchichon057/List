#include <conio.h>
#include "Lista_simple.hpp"
int main(){

    ListaSimple<int> lista;
    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(2);
    lista.pushFront(2);
    lista.pushFront(3);
    lista.pushFront(4);
    lista.pushFront(5);

    lista.display();
    lista.popFront();
    // lista.popBack();
    // lista.popBack();
    // lista.popBack();
    // lista.popFront();
    // lista.popFront();
    // lista.popFront();
    lista.display();

    // lista.popBack();
    // lista.display();
    // lista.~ListaSimple();
    // lista.display();
    getch();
    return 0;
}