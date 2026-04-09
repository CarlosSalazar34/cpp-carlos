#include <iostream>
#include <string>  
using namespace std;

struct Usuario {
    string nombre;
    int cedula;
    Usuario* siguiente;
};

bool verifyUsers(Usuario* cabeza) {
    return cabeza == nullptr;
}

void getUsers(Usuario* cabeza) {
    if (verifyUsers(cabeza)) {
        cout << "No hay usuarios registrados." << endl;
        return;
    }
    Usuario* aux = cabeza;
    while (aux != nullptr) {
        cout << "Nombre: " << aux->nombre << ", Cedula: " << aux->cedula << endl;
        aux = aux->siguiente;
    }
}

Usuario* crearUsuario(string nombre, int cedula) {
    Usuario* nuevoUsuario = new Usuario;
    nuevoUsuario->nombre = nombre;
    nuevoUsuario->cedula = cedula;
    nuevoUsuario->siguiente = nullptr;
    return nuevoUsuario;
}

void insertarUsuario(Usuario*& cabeza, Usuario* nuevo) {
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Usuario* aux = cabeza;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

void liberarLista(Usuario* cabeza) {
    while (cabeza != nullptr) {
        Usuario* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void menu() {
    cout << "BIENVENIDO AL CRUD HECHO EN CPP" << endl;
    cout << "PRESIONE 1 PARA CREAR UN USUARIO" << endl;
    cout << "PRESIONE 2 PARA VER TODOS LOS USUARIOS" << endl;
    cout << "PRESIONE 0 PARA SALIR" << endl;
}

int main() {
    int option;
    Usuario* cabeza = nullptr;  // La cabeza de la lista empieza nula
    while (true) {
        menu();
        cout << "Seleccione una opcion: ";
        cin >> option;
        switch (option) {
        case 1: {
            string nombre;
            int cedula;
            cout << "Ingrese el nombre de la persona: ";
            cin.ignore();  // Esto es para limpiar el buffer Xd
            getline(cin, nombre);
            cout << "Ingrese la cedula de la persona: ";
            cin >> cedula;
            Usuario* nuevo = crearUsuario(nombre, cedula);
            insertarUsuario(cabeza, nuevo);
            break;
        }
        case 2: {
            getUsers(cabeza);
            break;
        }
        case 0: {
            liberarLista(cabeza);  // Libera la memoria para que no permanezcan los datos en la memoria
            return 0;
        }
        default:
            cout << "Opcion invalida." << endl;
            break;
        }
    }
    return 0;
}