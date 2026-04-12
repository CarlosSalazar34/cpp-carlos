#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para obtener el valor del k-ésimo nodo desde el final
int obtenerK_EsimoDesdeFinal(Nodo* cabeza, int k) {
    if (cabeza == nullptr) return -1; // Caso lista vacía

    Nodo* puntero_A = cabeza;
    Nodo* puntero_B = cabeza;

    // 1. Mover puntero_A k posiciones adelante
    for (int i = 0; i < k; i++) {
        if (puntero_A == nullptr) {
            // Error: k es mayor que la longitud de la lista
            return -1; 
        }
        puntero_A = puntero_A->siguiente;
    }

    // 2. Mover ambos hasta que puntero_A llegue al final
    while (puntero_A != nullptr) {
        puntero_A = puntero_A->siguiente;
        puntero_B = puntero_B->siguiente;
    }

    // 3. El puntero_B ahora está en la posición k desde el final
    return puntero_B->dato;
}

// Función auxiliar para insertar nodos al inicio (para probar)
void insertarInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

int main() {
    Nodo* miLista = nullptr;
    
    // Creamos lista: 50 -> 40 -> 30 -> 20 -> 10
    insertarInicio(miLista, 10);
    insertarInicio(miLista, 20);
    insertarInicio(miLista, 30);
    insertarInicio(miLista, 40);
    insertarInicio(miLista, 50);

    int k = 2; // Queremos el 2do desde el final (sería el 20)
    int resultado = obtenerK_EsimoDesdeFinal(miLista, k);

    if (resultado != -1) {
        std::cout << "El valor en la posicion " << k << " desde el final es: " << resultado << std::endl;
    } else {
        std::cout << "Error: Posicion fuera de rango." << std::endl;
    }

    return 0;
}