#include <iostream>
using namespace std;

struct Lista{ 
    int dato;
    Lista* siguiente;
};

int main(){
    Lista *primerPuntero, *segundoPuntero, *tercerPuntero;
    primerPuntero = new Lista;
    primerPuntero->dato = 15;
    primerPuntero->siguiente = nullptr;
    segundoPuntero = new Lista;
    segundoPuntero->dato = 20;
    segundoPuntero->siguiente = nullptr;
    primerPuntero->siguiente = segundoPuntero;
    Lista *auxiliar = primerPuntero;
    while (auxiliar != nullptr)
    {
        cout << auxiliar->dato << endl;
        auxiliar = auxiliar->siguiente;
        /* code */
    }
    
    cout << "hola mundo" << endl;
    return 0;
}