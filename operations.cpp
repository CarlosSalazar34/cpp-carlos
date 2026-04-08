#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
    int dato;
    Nodo* siguiente;
};

void clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

Nodo* crearNodo(int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};

bool listaVacia(Nodo* cabeza){
    return cabeza == nullptr;
};

void insertarNodo(Nodo*& cabeza, int valor){
    Nodo* nuevoNodo = crearNodo(valor);
    if (listaVacia(cabeza)){
        cabeza = nuevoNodo;
    } else {
        Nodo* auxiliar = cabeza;
        while (auxiliar->siguiente != nullptr){
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoNodo;
    }
}

void listarLista(Nodo* cabeza){
    Nodo* auxiliar = cabeza;
    while (auxiliar != nullptr){
        cout << auxiliar->dato << endl;
        auxiliar = auxiliar->siguiente;
    };  
}

int main(){
    int option;
    cout << "BIENVENIDO AL PROGRAMA DE LISTAS ENLAZADAS" << endl;
    Nodo* cabeza = nullptr;
    while (true)
    {
        cout << "1. Insertar nodo" << endl;
        cout << "2. Listar nodos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> option;
        if (option == 1){ 
            clearTerminal();
            int valor;
            cout << "Ingrese el valor del nodo: ";
            cin >> valor;
            insertarNodo(cabeza, valor);
        }else if (option  == 2){ 
            clearTerminal();
            if (!listaVacia(cabeza)){
                cout << "Lista enlazada:" << endl;
                listarLista(cabeza);
            } else {
                cout << "La lista está vacía." << endl;
            }
        }else if (option == 0){
            clearTerminal();
            cout << "Saliendo del programa..." << endl;
            break;
    }else { 
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
    
    return 0;
}

// int main(){
//     Nodo* nuevoNodo = crearNodo(15);
//     Nodo* otroNodo = crearNodo(20);
//     Nodo* tercerNodo = crearNodo(25);
//     nuevoNodo->siguiente = otroNodo;
//     otroNodo->siguiente = tercerNodo;
//     cout << "Lista enlazada:" << endl;
//     cout << "Presione enter para correr el programa..."<< endl;
//     cin.ignore();
//     cin.get();  
//     if (!listaVacia(nuevoNodo)){
//         listarLista(nuevoNodo);
//     } else {
//         cout << "La lista está vacía." << endl;
//         return 0;
//     }
//     // Nodo* auxiliar = nuevoNodo;
//     // while (auxiliar != nullptr){
//     //     cout << auxiliar->dato << endl;
//     //     auxiliar = auxiliar->siguiente;
//     // };
//     return 0;
// }