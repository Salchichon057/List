#include <conio.h>
#include "CircularDoble.hpp"
int main(){
    CircularDoble<int> lista;

    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
    lista.pushBack(9);
    lista.pushBack(10);
    lista.display();

    lista.~CircularDoble();
    lista.display();
    getch();
    return 0;
}