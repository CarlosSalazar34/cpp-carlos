#include <iostream>
using namespace std;

struct Lista{
    int dato;
    Lista* siguiente;
};

int main(){
    Lista *P, *Q, *R;
    P = new Lista;
    P->dato = 15;
    P->siguiente = nullptr;
    Q = new Lista;
    Q->dato = 20;
    Q->siguiente = nullptr;
    P->siguiente = Q;
    R = new Lista;
    R->dato = 25;
    R->siguiente = nullptr;
    Q->siguiente = R;
    Lista *aux = P;
    while (aux != nullptr)
    {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
    
    return 0;
}