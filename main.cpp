#include <conio.h>
#include "Lista_simple.hpp"
int main(){

    ListaSimple<int> lista;
    lista.pushFront(2);
    lista.pushFront(3);
    lista.pushFront(4);
    lista.pushFront(5);

    lista.pushBack(6);
    lista.pushBack(7);
    // lista.pushBack(8);
    // lista.display();
    // lista.popFront();
    lista.display();

    lista.popBack();
    lista.display();
    getch();
    return 0;
}