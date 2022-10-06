#include <conio.h>
#include "Lista_Doble.hpp"
int main(){
    ListaDoble<int> lista;

    lista.pushFront(6);
    lista.pushFront(7);
    // lista.pushFront(8);
 
    lista.display();
    lista.~ListaDoble();
    lista.display();
    getch();
    return 0;
}