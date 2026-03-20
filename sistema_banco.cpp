#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void crearCuenta(vector<map<string, string>> &cuentas)
{
    string nombreCompleto, numeroCuenta, saldo;
    map<string, string> cuenta;

    cout << "Ingrese el nombre completo: ";
    cin.ignore();                 // Limpia el salto de línea del menú
    getline(cin, nombreCompleto); // Permite espacios en el nombre

    cout << "Ingrese el numero de cuenta: ";
    cin >> numeroCuenta;

    cout << "Ingrese el saldo inicial: ";
    cin >> saldo;

    cuenta["nombre"] = nombreCompleto;
    cuenta["numero"] = numeroCuenta;
    cuenta["saldo"] = saldo;
    cuentas.push_back(cuenta);
    cout << "Cuenta creada con exito.\n";
}

void consultarSaldo(const vector<map<string, string>> &cuentas)
{
    string numeroCuenta;
    cout << "Ingrese el numero de cuenta a consultar: ";
    cin >> numeroCuenta;

    auto it = find_if(cuentas.begin(), cuentas.end(), [numeroCuenta](const map<string, string> &cuenta)
                      { return cuenta.at("numero") == numeroCuenta; });

    if (it != cuentas.end())
    {
        cout << "Titular: " << it->at("nombre") << endl;
        cout << "Saldo actual: $" << it->at("saldo") << endl;
    }
    else
    {
        cout << "Error: Cuenta no encontrada." << endl;
    }
}

int main()
{
    int opcion;
    vector<map<string, string>> cuentas;

    do
    {
        cout << "\n--- SISTEMA BANCARIO ---" << endl;
        cout << "1. Crear cuenta" << endl;
        cout << "2. Consultar saldo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            crearCuenta(cuentas);
            break;
        case 2:
            consultarSaldo(cuentas);
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}