#include <iostream>
using namespace std;

struct Nodo{ 
    int dato;
    Nodo* siguiente;
};

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
}

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void insertarUltimo(Nodo*& cabeza, int valor){
    Nodo* nuevo = crearNodo(valor);
    if (listaVacia(cabeza)){
        cabeza = nuevo;
    }else { 
        Nodo* aux = cabeza;
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

int voltearYObtener(Nodo*& cabeza, int indice){
    Nodo* anterior = nullptr;
    Nodo* actual = cabeza;
    Nodo* siguiente = nullptr;
    while(actual != nullptr){
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    cabeza = anterior;

    // Obtener el valor en el indice dado
    Nodo* aux = cabeza;
    for(int i = 0; i < indice; i++){
        if(aux == nullptr){
            cout << "Indice fuera de rango" << endl;
            return -1;
        }
        aux = aux->siguiente;
    }
    if(aux == nullptr){
        cout << "Indice fuera de rango" << endl;
        return -1;
    }
    return aux->dato;
}

int main(){
    Nodo* cabeza = nullptr;
    insertarUltimo(cabeza, 1);
    insertarUltimo(cabeza, 2);
    insertarUltimo(cabeza, 3);
    insertarUltimo(cabeza, 6);
    insertarUltimo(cabeza, 4);
    insertarUltimo(cabeza, 5);

    int valor = voltearYObtener(cabeza, 2);
    cout << "Valor en indice 2 (lista volteada): " << valor << endl; // Imprime 6

    return 0;
}