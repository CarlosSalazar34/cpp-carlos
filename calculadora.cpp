#include <iostream>
using namespace std;
#include <cstdlib>

void clearTerminal()
    {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }

int main()
{
    cout << "Bienvenido a la calculadora de C++" << endl;
    while (true)
    {   
        int option;
        cout << "Ingrese una opcion: \n 1. Sumar \n 2. Restar \n 3. Multiplicar \n 4. Dividir \n 5. Salir" << endl;
        cout << "Opcion: ";
        cin >> option;
        if (option == 1)
        {
            int a, b;
            cout << "Ingrese el primer numero: ";
            cin >> a;
            cout << "Ingrese el segundo numero: ";
            cin >>b;
            cout << "El resultado de la suma es: " << a + b << endl;

        }else if (option == 2)
        {
            
        }

    }

    return 0;
}