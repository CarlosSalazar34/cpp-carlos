#include <iostream>
using namespace std;
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

Nodo *crearNodo(int valor)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};


bool listaVacia(Nodo *cabeza)
{
    return cabeza == nullptr;
};

void listarLista(Nodo *cabeza)
{
    Nodo *auxiliar = cabeza;
    while (auxiliar != nullptr)
    {
        cout << auxiliar->dato << endl;
        auxiliar = auxiliar->siguiente;
    };
}

int main(){
    Nodo* nuevoNodo = crearNodo(15);
    Nodo* otroNodo = crearNodo(20);
    Nodo* tercerNodo = crearNodo(25);
    nuevoNodo->siguiente = otroNodo;
    otroNodo->siguiente = tercerNodo;
    cout << "Lista enlazada:" << endl;
    cout << "Presione enter para correr el programa..."<< endl;
    cin.ignore();
    cin.get();
    if (!listaVacia(nuevoNodo)){
        listarLista(nuevoNodo);
    } else {
        cout << "La lista está vacía." << endl;
        return 0;
    }
    // Nodo* auxiliar = nuevoNodo;
    // while (auxiliar != nullptr){
    //     cout << auxiliar->dato << endl;
    //     auxiliar = auxiliar->siguiente;
    // };
    return 0;
}