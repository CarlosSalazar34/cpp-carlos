#include <iostream>
using namespace std;

struct Lista{
    int dato;
    Lista* siguiente;
};

int main(){
    Lista *P, *Q;
    P = new Lista;
    P->dato = 15;
    P->siguiente = nullptr;
    Q = new Lista;
    Q->dato = 20;
    Q->siguiente = nullptr;
    P->siguiente = Q;
    
    return 0;
}