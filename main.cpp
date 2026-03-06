#include <iostream>
#include <string>
#include <map>
#include <any>
#include <limits>
#include <cstdlib> // Necesario para system()

using namespace std;

// Función para limpiar la pantalla según el Sistema Operativo
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Función para pausar la ejecución y dejar que el usuario lea los mensajes
void pause()
{
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void menu()
{
    cout << "============================================" << endl;
    cout << "   SISTEMA DE GESTIÓN DE INVENTARIO" << endl;
    cout << "============================================" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Eliminar producto" << endl;
    cout << "3. Mostrar inventario" << endl;
    cout << "4. Actualizar producto" << endl;
    cout << "0. Salir" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Seleccione una opción: ";
}

void addProduct(map<string, map<string, any>> &inventory)
{
    string name;
    double price;
    int quantity;

    cout << "\n--- Agregar Nuevo Producto ---" << endl;
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer
    getline(cin, name);

    cout << "Precio: ";
    while (!(cin >> price))
    {
        cout << "Error. Ingrese un precio numérico: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Cantidad: ";
    while (!(cin >> quantity))
    {
        cout << "Error. Ingrese una cantidad entera: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    inventory[name] = map<string, any>{{"price", price}, {"quantity", quantity}};
    cout << "\n¡Producto '" << name << "' agregado con éxito!" << endl;
}

int main()
{
    int option;
    map<string, map<string, any>> inventory;

    while (true)
    {
        clearScreen();
        menu();

        if (!(cin >> option))
        {
            cout << "\nError: Por favor, ingrese un número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pause();
            continue;
        }

        switch (option)
        {
        case 1:
            addProduct(inventory);
            pause();
            break;

        case 2:
        {
            string name;
            cout << "\nNombre del producto a eliminar: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            if (inventory.erase(name))
            {
                cout << "Producto '" << name << "' eliminado correctamente." << endl;
            }
            else
            {
                cout << "Error: El producto no existe en el inventario." << endl;
            }
            pause();
            break;
        }

        case 3:
            cout << "\n--- Inventario Actual ---" << endl;
            if (inventory.empty())
            {
                cout << "El inventario está vacío." << endl;
            }
            else
            {
                // Usamos Structured Bindings (C++17) para recorrer el mapa
                for (const auto &[name, data] : inventory)
                {
                    cout << "-> " << name
                         << " | Precio: $" << any_cast<double>(data.at("price"))
                         << " | Cantidad: " << any_cast<int>(data.at("quantity")) << endl;
                }
            }
            pause();
            break;

        case 4:
        {
            string name;
            cout << "\nNombre del producto a actualizar: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            auto it = inventory.find(name);

            if (it != inventory.end())
            {
                double newPrice;
                int newQuantity;

                cout << "Nuevo precio: ";
                while (!(cin >> newPrice))
                {
                    cout << "Error. Ingrese un precio numérico: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Nueva cantidad: ";
                while (!(cin >> newQuantity))
                {
                    cout << "Error. Ingrese una cantidad entera: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                it->second["price"] = newPrice;
                it->second["quantity"] = newQuantity;

                cout << "\n¡Producto '" << name << "' actualizado con éxito!" << endl;
            }
            else
            {
                cout << "\nError: El producto '" << name << "' no existe." << endl;
            }

            pause(); 
            break;   
        }

        case 0:
            clearScreen();
            cout << "Saliendo del sistema. ¡Hasta pronto!" << endl;
            return 0;

        default:
            cout << "\nOpción no válida. Intente de nuevo." << endl;
            pause();
            break;
        }
    }

    return 0;
}