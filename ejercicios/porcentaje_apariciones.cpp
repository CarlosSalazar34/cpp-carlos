#include <iostream>
using namespace std;

struct Nodo{
    int valor;
    Nodo* siguiente;
};

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
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

bool incluidoEnLista(Nodo* cabeza, int valor){ 
    Nodo* aux = cabeza;
    while (aux != nullptr)
    {
        if (aux->valor == valor){
            return true;
        } 
        aux = aux->siguiente;
    }
    return false;
    
}

void valoresEnLista1enLista2(Nodo* cabeza1, Nodo* cabeza2){
    if (listaVacia(cabeza1) || listaVacia(cabeza2)){
        cout << "Una de las listas esta vacia" << endl;  
    }else { 
        Nodo* aux = cabeza1;
        while (aux != nullptr)
        {
            if(incluidoEnLista(cabeza2,aux->valor)){
                cout << "El valor " << aux->valor << " esta en la lista 2" <<endl;
            }else {
                return;
                // cout << "El valor " << aux->valor << " no esta en la lista 2" <<endl;
            }
            aux = aux->siguiente;
        }
        
    }
}


void iterarLista(Nodo* cabeza){ 
    Nodo* aux = cabeza;
    cout << "Valores de la lista" << endl;
    while (aux != nullptr)
    {
        cout << aux->valor;
    };
    
}

void escanearLista(Nodo* cabeza){ 
    Nodo* aux = cabeza;
    float apariciones;
    while (aux != nullptr)
    {
        cout << "valor " << aux->valor << endl;
        apariciones = porcentajeApariciones(cabeza, aux->valor);
        cout << "El total de apariciones de el valor " << aux->valor << " es: " << apariciones << "% porciento" << endl;
        aux = aux->siguiente;
    }
}


void eliminarElementoLista(Nodo*& cabeza, int valor){
    Nodo* aux = cabeza;
    while (aux != nullptr)
    {
        if (aux->valor == valor){
            cout << "elemento eliminado" << valor << endl;
            delete aux;
        } else {
            cout << "El elemento "<< valor << "no esta en la lista" << endl;
        }
        aux = aux->siguiente;
    }
    
}


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
    Nodo* cabeza1 = nullptr;
    Nodo* cabeza2 = nullptr;
    // INSERTAR VALORES EN LA LISTA 1
    insertarNodo(cabeza1, 23);
    insertarNodo(cabeza1, 23);
    insertarNodo(cabeza1, 50);
    
    // INSERTAR VALORES EN LA LISTA 2
    insertarNodo(cabeza2, 23);
    insertarNodo(cabeza2, 43);
    insertarNodo(cabeza2, 50);
    

    cout << "Lista 1" << endl;
    escanearLista(cabeza1);
    cout << "Lista 2" << endl;
    escanearLista(cabeza2);
    
    valoresEnLista1enLista2(cabeza1, cabeza2);

    return 0;

}