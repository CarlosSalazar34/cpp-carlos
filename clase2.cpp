#include <iostream>
using namespace std;

int main() {
    // 1. Creamos una variable normal
    int vida = 100;

    // 2. "Llamamos" a su dirección de memoria y la guardamos en un puntero
    // Usamos & para obtener la dirección
    int* ptrVida = &vida;

    cout << "--- INFORMACION INICIAL ---" << endl;
    cout << "Valor de 'vida': " << vida << endl;             // Imprime 100
    cout << "Direccion de 'vida' (&vida): " << &vida << endl;  // Imprime la dir. (ej: 0x61ff08)
    cout << "Valor del puntero (donde apunta): " << ptrVida << endl; // Es la misma dirección

    cout << "\n--- MODIFICACION VIA PUNTERO ---" << endl;
    // 3. Usamos el puntero para cambiar el valor original
    // Ponemos el * antes del puntero para entrar a esa dirección
    *ptrVida = 85; 

    cout << "Nuevo valor de 'vida': " << vida << endl; // ¡Ahora es 85!

    cout << "\n--- ARITMETICA Y ARREGLOS ---" << endl;
    // 4. Direcciones en un arreglo (verás que están pegadas)
    int niveles[] = {1, 2, 3};
    int* ptrNivel = niveles; // Apunta al primer elemento

    cout << "Direccion del nivel 1: " << ptrNivel << " (Valor: " << *ptrNivel << ")" << endl;
    
    // Sumamos 1 al puntero para saltar a la siguiente dirección de memoria
    ptrNivel++; 
    cout << "Direccion del nivel 2: " << ptrNivel << " (Valor: " << *ptrNivel << ")" << endl;

    return 0;
}