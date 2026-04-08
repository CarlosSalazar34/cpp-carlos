#include <iostream>
using namespace std;

main(){
    int a = 10;
    int *p = &a;
    cout << "Valor de a: " << a << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Valor apuntado por p: " << *p << endl;
    cout << "Direccion de a: " << &a << endl;
    cout << "Direccion de p: " << &p << endl;
}