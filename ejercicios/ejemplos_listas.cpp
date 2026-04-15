#include <iostream>
#include <ctime>

using namespace std;

struct Nodo {
    int dato;
    Nodo *prox;
};

Nodo *crearNodo(int valor) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool listaVacia(Nodo *inicio) {
    return inicio == NULL;
}

void imprimirLista(Nodo *inicio) {
    if (listaVacia(inicio)) {
        cout << "Lista esta vacia" << endl;
        return;
    }
    Nodo *mover = inicio;
    while (mover != NULL) {
        cout << mover->dato << "->";
        mover = mover->prox;
    }
    cout << "NULL" << endl;
}

void insertarPrimero(Nodo *&inicio, int valor) {
    Nodo *nuevo = crearNodo(valor);
    nuevo->prox = inicio;
    inicio = nuevo;
}

void insertarOrdenado(Nodo *&inicio, int valor) {
    if (listaVacia(inicio) || valor < inicio->dato) {
        insertarPrimero(inicio, valor);
    } else {
        Nodo *nuevo = crearNodo(valor);
        Nodo *aux = inicio;
        while (aux->prox != NULL && aux->prox->dato < valor) {
            aux = aux->prox;
        }
        nuevo->prox = aux->prox;
        aux->prox = nuevo;
    }
}

float porcentajeApariciones(Nodo *inicio, int valor) {
    if (listaVacia(inicio)) return 0;
    int contador = 0, total = 0;
    Nodo *aux = inicio;
    while (aux != NULL) {
        if (aux->dato == valor) contador++;
        total++;
        aux = aux->prox;
    }
    return (total == 0) ? 0 : ((float)contador / total * 100);
}

Nodo* buscarPuntero(Nodo *inicio, int valor) {
    Nodo *aux = inicio;
    while (aux != NULL) {
        if (aux->dato == valor) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void eliminarApariciones(Nodo *&inicio, int valor) {
    while (inicio != NULL && inicio->dato == valor) {
        Nodo *eliminar = inicio;
        inicio = inicio->prox;
        delete eliminar;
    }
    Nodo *actual = inicio;
    while (actual != NULL && actual->prox != NULL) {
        if (actual->prox->dato == valor) {
            Nodo *eliminar = actual->prox;
            actual->prox = eliminar->prox;
            delete eliminar;
        } else {
            actual = actual->prox;
        }
    }
}

void vaciarLista(Nodo *&inicio) {
    while (inicio != NULL) {
        Nodo *aux = inicio;
        inicio = inicio->prox;
        delete aux;
    }
}

void generarAleatorios(Nodo *&inicio, int n) {
    for (int i = 0; i < n; i++) {
        insertarOrdenado(inicio, rand() % 100); 
    }
}

int main() {
    Nodo *miLista = NULL; 
    int opcion, valor, n;


    srand((unsigned) time(NULL));

    do {
        cout << "1. Insertar ordenadamente" << endl;
        cout << "2. Ver porcentaje de apariciones" << endl;
        cout << "3. Buscar ubicacion (Puntero)" << endl;
        cout << "4. Eliminar todas las apariciones" << endl;
        cout << "5. Mostrar lista" << endl;
        cout << "6. Vaciar lista (Reiniciar)" << endl;
        cout << "7. Generar lista" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                insertarOrdenado(miLista, valor);
                cout << "Insertado." << endl;
                break;

            case 2:
                if (listaVacia(miLista)) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    cout << "Valor a calcular %: ";
                    cin >> valor;
                    float porc = porcentajeApariciones(miLista, valor);
                    cout << "El valor " << valor << " aparece el " << porc << "% de las veces." << endl;
                }
                break;

            case 3:
                cout << "Valor para obtener puntero: ";
                cin >> valor;
                {
                    Nodo* ptr = buscarPuntero(miLista, valor); 
                    if (ptr) 
                        cout << "Encontrado en la direccion de memoria: " << ptr << endl;
                    else 
                        cout << "Valor no encontrado." << endl;
                }
                break;

            case 4:
                cout << "Valor a eliminar por completo: ";
                cin >> valor;
                eliminarApariciones(miLista, valor);
                cout << "Proceso de eliminacion terminado." << endl;
                break;

            case 5:
                cout << "Contenido de la lista: ";
                imprimirLista(miLista);
                break;

            case 6:
                vaciarLista(miLista);
                cout << "Memoria liberada. Lista reiniciada." << endl;
                break;

            case 7:
                cout << "Ingrese la cantidad de elementos a generar: ";
                cin >> n;
                if (n > 0) {
                    generarAleatorios(miLista, n);
                    cout << n << " elementos aleatorios insertados ordenadamente." << endl;
                } else {
                    cout << "Cantidad no valida." << endl;
                }
                break; 

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);
    vaciarLista(miLista);
    return 0;
}