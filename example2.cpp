#include <iostream>
using namespace std;

struct Nodo{ 
    int dato;
    Nodo* siguiente;

};

Nodo* crearNodo(int valor){ 
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};

bool listaVacia(Nodo* cabeza){ 
    return cabeza == nullptr;
};

void listarLista(Nodo* cabeza){ 
    Nodo* auxiliar = cabeza;
    while (auxiliar != nullptr)
    {
        cout << auxiliar->dato << endl;
        auxiliar = auxiliar->siguiente;
    }
    
};

void analizarLista(Nodo* cabeza){
    if (listaVacia(cabeza)){
        cout << "La lista está vacía." << endl;
    }
    Nodo* auxiliar = cabeza;
    float suma = 0;
    int contador = 0;
    while (auxiliar != nullptr){
        suma += auxiliar->dato;
        contador++;
        auxiliar = auxiliar->siguiente;
    }
    float promedio = suma / contador;
    cout << "La suma de los elementos es: " << suma << endl;
    cout << "El número de elementos es: " << contador << endl;
    cout << "El promedio es: " << promedio << endl;
}

int main(){
    Nodo* nuevoNodo = crearNodo(25);
    Nodo* otroNodo = crearNodo(10);
    Nodo* tercerNodo = crearNodo(2);

    nuevoNodo->siguiente = otroNodo;
    otroNodo->siguiente = tercerNodo;

    analizarLista(nuevoNodo);
    return 0;
}