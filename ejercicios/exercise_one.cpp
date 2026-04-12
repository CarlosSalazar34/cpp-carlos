#include <iostream>
using namespace std;

struct Nodo { 
    int valor;
    Nodo* siguiente;
};

bool listaVacia(Nodo* cabeza) {
    return cabeza == nullptr;
}

Nodo* crearNodo(int valor) {
    Nodo* item = new Nodo;
    item->valor = valor;
    item->siguiente = nullptr;
    return item;
}

void insertarValor(Nodo*& cabeza, int valor) { 
    Nodo* nuevo = crearNodo(valor);
    if (listaVacia(cabeza)) {
        cabeza = nuevo;
    } else { 
        Nodo* aux = cabeza;
        // CORRECCIÓN: Nos detenemos en el último nodo real, no en el vacío
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        // Ahora aux es el último, podemos colgar el nuevo nodo
        aux->siguiente = nuevo;
    }
}

void mostrarLista(Nodo* cabeza) { 
    if (listaVacia(cabeza)) {
        cout << "La lista esta vacia" << endl;
    } else { 
        Nodo* aux = cabeza;
        while (aux != nullptr) {
            cout << "[" << aux->valor << "] -> ";
            aux = aux->siguiente;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    // Es vital inicializar en nullptr
    Nodo* miLista = nullptr;

    insertarValor(miLista, 10);
    insertarValor(miLista, 20);
    insertarValor(miLista, 30);

    cout << "Contenido de la lista:" << endl;
    mostrarLista(miLista);

    return 0;
}