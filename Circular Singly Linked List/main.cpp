#include <conio.h>
#include "ListaCircularSimple.hpp"
int main(){
    ListaCircularSimple<int> lista;

    lista.pushFront(6);
    lista.pushFront(5);
    lista.pushFront(4);
    lista.pushFront(3);
    lista.pushFront(2);
    lista.pushFront(1);
    lista.pushFront(0);
    
    lista.pushBack(8);
    lista.pushFront(9);
    lista.pushBack(10);
    lista.pushFront(11);
    lista.pushBack(8);
    lista.pushBack(9);
    lista.pushBack(1);
    lista.popBack();
    lista.popBack();
    lista.popBack();
    lista.display();
    lista.popBack();
    lista.display();
    getch();
    return 0;
}