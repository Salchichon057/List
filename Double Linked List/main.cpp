#include <conio.h>
#include "Lista_Doble.hpp"
int main(){
    ListaDoble<int> lista;

    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
    lista.pushBack(6);
    lista.pushBack(7);
    lista.pushBack(8);
 
    lista.display();
    lista.~ListaDoble();
    lista.display();
    getch();
    return 0;
}