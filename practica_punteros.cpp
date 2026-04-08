#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo {
    int valor;
    Nodo *siguiente;
};

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void insertar(Nodo*& cabeza, int valor){
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
};

void mostrarNodo(Nodo* cabeza){
    while (cabeza != nullptr)
    {
        cout << cabeza->valor << " "<< endl;
        cabeza = cabeza->siguiente;
    };
    
}

main(){
    Nodo* cabeza = nullptr;
    int option;
    int valor;
    while (true)
    {
        printf("BIENVENIDO AL PROGRAMA DE PUNTEROS\n");
        printf("1. Insertar un nuevo nodo\n");
        printf("2. Mostrar la lista\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        cin >> option;
        switch (option)
        {
        case 1:
            clearScreen();
            printf("Ingrese el valor del nodo: ");
            cin >> valor;
            insertar(cabeza, valor);
            clearScreen();
            break;

        case 2:
            clearScreen();
            mostrarNodo(cabeza);
            printf("Presione enter para continuar...");
            cin.ignore();
            cin.get();
            clearScreen();
            break;  
        
        case 3:
            printf("Saliendo del programa...\n");
            return 0;
        
        default:
            break;
        }
        
    };
    

    // insertar(cabeza, 10);
    // insertar(cabeza, 20);
    // insertar(cabeza, 30);

    // Nodo* actual = cabeza;
    // while (actual != nullptr) {
    //     cout << actual->valor << " ";
    //     actual = actual->siguiente;
    // }
    // cout << endl;

}