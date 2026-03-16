#include <vector>
#include <map>
#include <any>
#include <string>
#include <cstdio>
using namespace std;

class SistemaBanco{
private:
    vector<map<string, any>> clientes;
    long long reservas = 200000000000;

public:
    SistemaBanco(const vector<map<string, any>>& c): clientes(c) {}
    SistemaBanco() = default;

    void iniciar(){ 
        printf("Bienvenido al sistema del banco\n");
    }
};

int main(){ 
    vector<map<string, any>> clientes = {
        { 
            {"name", string("Carlos")},
            {"edad", 12},
            {"balance", 25000}
        }
    }; 

    SistemaBanco sistema(clientes);
    sistema.iniciar();

    return 0;
}