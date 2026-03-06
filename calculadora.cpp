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
        int a, b;
        if (option == 1)
        {
            cout << "Ingrese el primer numero: ";
            cin >> a;
            cout << "Ingrese el segundo numero: ";
            cin >>b;
            cout << "El resultado de la suma es: " << a + b << endl;

        }else if (option == 2)
        {
            cout << "Ingrese el primer numero: ";
            cin >> a;
            cout << "Ingrese el segundo numero: ";
            cin >>b;
            cout << "El resultado de la resta es: " << a - b << endl;
        }
        else if (option == 3)
        {
            cout << "Ingrese el primer numero: ";
            cin >> a;
            cout << "Ingrese el segundo numero: ";
            cin >>b;
            cout << "El resultado de la multiplicacion es: " << a * b << endl;
        }
        else if (option == 4)
        {
            cout << "Ingrese el primer numero: ";
            cin >> a;
            cout << "Ingrese el segundo numero: ";
            cin >>b;
            if (b != 0)
                cout << "El resultado de la division es: " << a / b << endl;
            else
                cout << "Error: No se puede dividir por cero." << endl;
        }
        else if (option == 5)
        {
            cout << "Gracias por usar la calculadora. ¡Hasta luego!" << endl;
            break;
        }
        else
        {
            cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }

    }

    return 0;
}