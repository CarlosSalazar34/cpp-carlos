#include <iostream>
using namespace std;

// Usamos & para indicar que recibimos la referencia del puntero original
void intercambiarPuntero(int* &a, int* &b) {
    int* temp = a;
    a = b;
    b = temp;
}

int main() {
    int vida = 100;
    int vida2 = 50;

    int* ptrVida = &vida;
    int* ptrVida2 = &vida2;

    cout << "--- ANTES DEL INTERCAMBIO ---" << endl;
    cout << "ptrVida apunta a un valor de: " << *ptrVida << endl;   // Imprime 100
    cout << "ptrVida2 apunta a un valor de: " << *ptrVida2 << endl; // Imprime 50

    // Llamamos a la función pasando los punteros
    intercambiarPuntero(ptrVida, ptrVida2);

    cout << "\n--- DESPUES DEL INTERCAMBIO ---" << endl;
    cout << "ptrVida ahora apunta a: " << *ptrVida << endl;      // Imprime 50
    cout << "ptrVida2 ahora apunta a: " << *ptrVida2 << endl;    // Imprime 100

    // Nota: Las variables 'vida' y 'vida2' NO han cambiado sus valores, 
    
    return 0;
}