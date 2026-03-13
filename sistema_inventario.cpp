#include <iostream>
#include <vector>
#include <map>
#include <any>
#include <cstdlib>
#include <algorithm>
#include <limits>
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void updateProduct(vector<map<string, any>> &inventory){
    string name;
    double newPrice;
    double newQuantity;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> name;
    for (auto &product: inventory){
        if (any_cast<string>(product.at("name")) == name){
            cout << "Ingrese el nuevo precio: ";
            cin >> newPrice;
            cout << "Ingrese la nueva cantidad: ";
            cin >> newQuantity;
            product.at("price") = newPrice;
            product.at("quantity") = newQuantity;
            cout << "Producto actualizado" << endl;
        }
    } 
}

void addProduct(vector<map<string, any>> &inventory, string name, double price, int quantity)
{
    inventory.push_back({{"name", name},
                         {"price", price},
                         {"quantity", quantity}});
}

void deleteProduct(vector<map<string, any>> &inventory)
{
    string name;
    for (const auto &product : inventory)
    {
        cout << "Nombre" << any_cast<string>(product.at("name"))
             << "Precio: " << any_cast<double>(product.at("price"))
             << "Cantidad: " << any_cast<int>(product.at("quantity")) << endl;
    }
    cout << "Ingrese el nombre del producto a eliminar: ";
    cin >> name;
    auto it = find_if(inventory.begin(), inventory.end(), [&name](const map<string, any> &product)
                      { return any_cast<string>(product.at("name")) == name; });
    if (it != inventory.end())
    {
        inventory.erase(it);
        cout << "Producto eliminado" << endl;
    }
    else
    {
        cout << "Producto no encontrado" << endl;
    }
}

void showProducts(const vector<map<string, any>>& inventory)
{
    if (inventory.empty())
    {
        cout << "No hay productos en el inventario." << endl;
    }
    else
    {
        for (const auto &product : inventory)
        {
            cout << "Nombre: " << any_cast<string>(product.at("name"))
                 << " | Precio: " << any_cast<double>(product.at("price"))
                 << " | Cantidad: " << any_cast<int>(product.at("quantity")) << endl;
        }
    }

    cout << "Presione Enter para continuar...";
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

int main()
{
    vector<map<string, any>> inventory = {};
    int option;
    while (true)
    {
        menu();
        cout << "Ingrese una opción: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            clearScreen();
            string name;
            double price;
            int quantity;
            cout << "Ingrese el nombre del producto: ";
            cin >> name;
            cout << "Ingrese el precio del producto: ";
            cin >> price;
            cout << "Ingrese la cantidad del producto: ";
            cin >> quantity;
            addProduct(inventory, name, price, quantity);
            /* code */
            break;
        }
        
        case 2:
        {
            clearScreen();
            deleteProduct(inventory);
            clearScreen();
            break;
        }

        case 3: 
        {
            clearScreen();
            showProducts(inventory);
            clearScreen();
            break;

        }

        case 4:
        {
            clearScreen();
            updateProduct(inventory);
            clearScreen();
            break;
        }

        case 0: 
        {
            cout << "Saliendo del programa..." << endl;
            return 0;
        }

        default:
            break;
        }
    }
}