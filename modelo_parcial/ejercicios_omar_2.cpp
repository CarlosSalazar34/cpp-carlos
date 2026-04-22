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
    };
    cout << endl;
};

void eliminarValor(Nodo*& cabeza, int valor){
    if(listaVacia(cabeza)){
        cout << "La lista esta vacia "<< endl;
    }else {
        Nodo* aux = cabeza;
        Nodo* anterior = nullptr;
        while(aux != nullptr && aux->valor != valor){
            anterior = aux;
            aux = aux->siguiente;
        }
        if (aux == nullptr){
            cout << "El valor no se encuentra en la lista"<< endl;
        }else{
            if(anterior == nullptr){
                cabeza = aux->siguiente;
            }else {
                anterior->siguiente = aux->siguiente;
            }
            delete aux;
        }

    }
}

int main(){
    Nodo* cabeza = nullptr;
    insertarValor(cabeza, 23);
    insertarValor(cabeza, 2);
    insertarValor(cabeza, 25);
    insertarInicio(cabeza, 50); 
    insertarValor(cabeza, 100);
    iterarLista(cabeza);
    eliminarValor(cabeza, 50);
    iterarLista(cabeza);
    return 0;
}