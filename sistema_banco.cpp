#include <iostream>
#include <string>
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

void crearCuenta(vector<map<string, string>>& cuentas){ 
    string nombreCompleto, numeroCuenta, saldo;
    map<string, string> cuenta;
    cout << "Ingrese el nombre completo del titular de la cuenta: ";
    cin >> nombreCompleto;
    cout << "Ingrese el numero de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese el saldo inicial: ";
    cin >> saldo;
    cuenta["nombre"] = nombreCompleto;
    cuenta["numero"] = numeroCuenta;
    cuenta["saldo"] = saldo;
    cuentas.push_back(cuenta);
}

int main(){ 
    int opcion;
    vector<map<string, string>> cuentas;

    cout << "BIENVENIDO AL SISTEMA DE BANCO" << endl << 
        "n1. Crear cuenta" << endl <<
        "n2. Consultar saldo" << endl <<
        "n3. Retirar dinero" << endl <<
        "n4. Depositar dinero"<< endl <<
        "n0. Salir" << endl <<
        "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        crearCuenta(cuentas);
        break;

    case 0:
        cout << "Gracias por usar el sistema de banco" << endl;
        return 0;
    
    default:
        break;
    }

    return 0;
}