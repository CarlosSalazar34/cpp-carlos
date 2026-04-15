#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo* siguiente;
};

float porcentajeApariciones(Nodo* cabeza, int valor){
    int total = 0, contador = 0;
    Nodo* aux = cabeza;
    while (aux != nullptr)
    {
        if (aux->valor == valor){
            total++;
        }
        aux = aux->siguiente;
        contador ++;
    };
    return total == 0? 0:(total*100.0) / contador;
};


void escanearLista(Nodo* cabeza){ 
    Nodo* aux = cabeza;
    float apariciones;
    while (aux != nullptr)
    {
        cout << "valor" << aux->valor << endl;
        apariciones = porcentajeApariciones(cabeza, aux->valor);
        cout << "El total de apariciones de el valor " << aux->valor << "es: " << apariciones << endl;
        aux = aux->siguiente;
    }
    
}

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
};


Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};

void insertarNodo(Nodo*& cabeza, int valor){
    Nodo* nodoAgregar = crearNodo(valor);
    if(listaVacia(cabeza)){
        cabeza = nodoAgregar;
    }else { 
        Nodo* aux = cabeza;
        while (aux->siguiente != nullptr)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nodoAgregar;
        
    }
};


int main(){
    Nodo* cabeza = nullptr;
    insertarNodo(cabeza, 23);
    insertarNodo(cabeza, 23);
    insertarNodo(cabeza, 50);
    escanearLista(cabeza);
    return 0;

}