#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo *siguiente;
};

void insertar(Nodo*& cabeza, int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
};

main(){
    Nodo* cabeza = nullptr;

    insertar(cabeza, 10);
    insertar(cabeza, 20);
    insertar(cabeza, 30);

    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << endl;

}