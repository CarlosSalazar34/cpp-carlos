#include <iostream>
using namespace std;

struct Usuario{
    string nombre;
    int cedula;
    Usuario* siguiente;
};



bool verifyUsers(Usuario* cabeza){ 
    return cabeza == nullptr;
};

Usuario* crearUsuario(string nombre, int cedula){
    Usuario* nuevoUsuario = new Usuario;
    nuevoUsuario->nombre = nombre;
    nuevoUsuario->cedula = cedula;
    nuevoUsuario->siguiente = nullptr;
    return nuevoUsuario;
};


int main(){
    return 0;
}