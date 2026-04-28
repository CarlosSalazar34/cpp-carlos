#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    return nuevoNodo;
}

bool listaVacia(Nodo* cabeza) {
    return cabeza == nullptr;
}

void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (!listaVacia(cabeza)) {
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
    cabeza = nuevo;
}

void insertarUltimo(Nodo*& cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (listaVacia(cabeza)) {
        cabeza = nuevo;
    } else {
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        // Conexión doble
        aux->siguiente = nuevo;
        nuevo->anterior = aux; 
    }
}

// Función para imprimir en ambos sentidos
void imprimirLista(Nodo* cabeza) {
    if (listaVacia(cabeza)) {
        cout << "La lista está vacía" << endl;
        return;
    }

    Nodo* aux = cabeza;
    Nodo* ultimo = nullptr;

    // 1. Imprimir al derecho
    cout << "Al derecho: ";
    while (aux != nullptr) {
        cout << aux->dato << " ";
        if (aux->siguiente == nullptr) ultimo = aux;
        aux = aux->siguiente;
    }
    cout << endl;

    // 2. Imprimir al revés
    cout << "Al revés:   ";
    aux = ultimo; // Empezamos desde el final
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->anterior; // Retrocedemos
    }
    cout << endl;
}

int main() {
    Nodo* cabeza = nullptr;
    insertarUltimo(cabeza, 10);
    insertarUltimo(cabeza, 20);
    insertarInicio(cabeza, 5);
    
    imprimirLista(cabeza);
    
    return 0;
}