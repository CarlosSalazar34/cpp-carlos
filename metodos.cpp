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

    vector<map<string, string>> usuarios = {
        {{"nombre", "Carlos"}, {"edad", "30"}},
        {{"nombre", "Ana"}, {"edad", "25"}},
        {{"nombre", "Luis"}, {"edad", "28"}}
    };
    for (const auto& usuario : usuarios) {
        cout << usuario.at("nombre") << '\n';   // ahora sí extrae el valor asociado
    }
        
    // cout << "Nombre: " << usuario.at("nombre") << ", Edad: " << usuario.at("edad") << endl;
    vector<int> numeros = {1, 2, 3, 4, 5};

    cout << numeros.size() << endl;
    cout << numeros[0] << endl;

    for(int n = 0; n < numeros.size(); n++){
        cout << numeros[n] << endl;
    };



    // numeros.push_back(6);

    // for (const auto& n: numeros){
    //     cout << n << endl;
    // }

    // cout << "Tamaño del vector: " << numeros.size() << endl;
    // cout << "Elementos del vector: ";
    // for (const auto& n : numeros) {
    //     cout << n << " ";
    // }
    // cout << endl;

    return 0;

}