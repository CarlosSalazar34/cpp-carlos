#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
using namespace std;

int main() {

    string texto = "hola como estas";
    cout << texto[0] << endl;
    cout << texto.substr(0, 4) << endl;
    transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
    cout << texto << endl;
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    cout << texto << endl;

    vector<int> numeros = {1, 2, 3, 4, 5};
    numeros.push_back(6);
    cout << "Tamaño del vector: " << numeros.size() << endl;
    cout << "Elementos del vector: ";
    for (const auto& n : numeros) {
        cout << n << " ";
    }
    cout << endl;

    return 0;

}