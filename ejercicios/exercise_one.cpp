#include <iostream>
using namespace std;

struct Nodo{ 
    int valor;
    Nodo* siguiente;
};

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
};

Nodo* crearNodo(int valor){
    Nodo* item = new Nodo;
    item->valor = valor;
    item->siguiente = nullptr;
    return item;
}

void insertarValor(Nodo*& cabeza, int valor){ 
    Nodo* nuevo = crearNodo(valor);
    if (listaVacia(cabeza)){
        cabeza = nuevo;
    }else { 
        Nodo* aux = cabeza;
        while (aux != nullptr)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void mostrarLista(Nodo* cabeza){ 
    if (listaVacia(cabeza)){
        cout << "La lista esta vacia "<< endl;
    }else { 
        Nodo* aux = cabeza;
        while (aux != nullptr)
        {
            cout << aux->valor <<endl;
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }
}

void retornarValor(Nodo*& cabeza, int posicion){
    if (listaVacia(cabeza)){ 
        cout << "No hay valores en la lista" << endl;
    }else { 
        while (cabeza != nullptr)
        {
            cout << cabeza->valor << endl;
            cabeza =  cabeza->siguiente;  
        };
        
    }
};

int main(){

    return 0;
}