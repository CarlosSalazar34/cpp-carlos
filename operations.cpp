#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void clearTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Nodo *crearNodo(int valor)
{
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
};

bool listaVacia(Nodo *cabeza)
{
    return cabeza == nullptr;
};

void insertarPrimero(Nodo *&cabeza, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
};

void eliminarNodo(Nodo *&cabeza, int valor)
{
    if (listaVacia(cabeza))
    {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo *auxiliar = cabeza;
    Nodo *nodoAnterior = nullptr;
    while (auxiliar != nullptr && auxiliar->dato != valor)
    {
        nodoAnterior = auxiliar;
        auxiliar = auxiliar->siguiente;
    }

    if (auxiliar == nullptr)
    {
        cout << "El nodo con valor " << valor << " no se encuentra en la lista." << endl;
        return;
    }

    if (nodoAnterior == nullptr)
    {
        cabeza = cabeza->siguiente;
    }
    else
    {
        nodoAnterior->siguiente = auxiliar->siguiente;
    }
    delete auxiliar;
}

bool buscarElemento(Nodo *cabeza, int valor)
{
    if (listaVacia(cabeza))
    {
        cout << "La lista está vacía." << endl;
        return false;
    }

    Nodo *auxiliar = cabeza;
    while (auxiliar != nullptr)
    {
        if (auxiliar->dato == valor)
        {
            cout << "Elemento encontrado: " << auxiliar->dato << endl;
            return true;
        }
        auxiliar = auxiliar->siguiente;
    }

    cout << "Elemento no encontrado en la lista." << endl;
    return false;
};

void insertarNodo(Nodo *&cabeza, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    if (listaVacia(cabeza))
    {
        cabeza = nuevoNodo;
    }
    else
    {
        Nodo *auxiliar = cabeza;
        while (auxiliar->siguiente != nullptr)
        {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoNodo;
    }
}

void listarLista(Nodo *cabeza)
{
    Nodo *auxiliar = cabeza;
    while (auxiliar != nullptr)
    {
        cout << auxiliar->dato << endl;
        auxiliar = auxiliar->siguiente;
    };
}

int main()
{
    int option;
    cout << "BIENVENIDO AL PROGRAMA DE LISTAS ENLAZADAS" << endl;
    Nodo *cabeza = nullptr;
    while (true)
    {
        cout << "1. Insertar nodo" << endl;
        cout << "2. Listar nodos" << endl;
        cout << "3. Insertar primero el nodo" << endl;
        cout << "4. Eliminar nodo" << endl;
        cout << "5. Buscar nodo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> option;
        if (option == 1)
        {
            clearTerminal();
            int valor;
            cout << "Ingrese el valor del nodo: ";
            cin >> valor;
            insertarNodo(cabeza, valor);
        }
        else if (option == 2)
        {
            clearTerminal();
            if (!listaVacia(cabeza))
            {
                cout << "Lista enlazada:" << endl;
                listarLista(cabeza);
            }
            else
            {
                cout << "La lista está vacía." << endl;
            }
        }
        else if (option == 3)
        {
            clearTerminal();
            int valor;
            cout << "Ingrese el valor del nodo: ";
            cin >> valor;
            insertarPrimero(cabeza, valor);
        }
        else if (option == 4)
        {
            clearTerminal();
            int valor;
            cout << "Ingrese el valor del nodo a eliminar: ";
            cin >> valor;
            eliminarNodo(cabeza, valor);
        }
        else if (option == 5)
        {
            clearTerminal();
            int valor;
            cout << "Ingrese el valor del nodo a buscar: ";
            cin >> valor;
            buscarElemento(cabeza, valor);
        }
        else if (option == 0)
        {
            clearTerminal();
            cout << "Saliendo del programa..." << endl;
            break;
        }
        else
        {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}

