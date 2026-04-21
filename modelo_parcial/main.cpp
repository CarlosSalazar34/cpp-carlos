#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
}

void ordenarAscendente(Nodo*& cabeza){
    Nodo* aux = cabeza;
    while(aux != nullptr){
        if (aux->valor > aux->siguiente->valor){
            int temp = aux->valor;
            aux->valor = aux->siguiente->valor;
            aux->siguiente->valor = temp;
        }
        aux = aux->siguiente;
    }
}

void ordenarDescendente(Nodo*& cabeza){
    Nodo* aux = cabeza;
    while(aux != nullptr){
        if (aux->valor < aux->siguiente->valor){
            int temp = aux->valor;
            aux->valor = aux->siguiente->valor;
            aux->siguiente->valor = temp;
        }
        aux = aux->siguiente;
    }
}   

void insertarInicio(Nodo*& cabeza, int valor){
    Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void insertarValor(Nodo*& cabeza, int valor){
    Nodo* nuevo = crearNodo(valor);

    if (listaVacia(cabeza)){
        cabeza = nuevo;
    }else {
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }   
}

void iterarLista(Nodo* cabeza){
    Nodo* aux = cabeza;
    while (aux != nullptr)
    {
        cout << aux->valor << " ";
        aux = aux->siguiente;
    }
    
}

int main(){
    Nodo* cabeza = nullptr;
    insertarValor(cabeza,23);
    insertarValor(cabeza, 2);
    insertarValor(cabeza, 45);
    insertarValor(cabeza, 15);
    insertarValor(cabeza, 909);
    iterarLista(cabeza);
    ordenarAscendente(cabeza);
    iterarLista(cabeza);
    ordenarDescendente(cabeza);
    iterarLista(cabeza);
    return 0;
}