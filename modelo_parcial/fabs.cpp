#include <iostream>
#include <vector>
using namespace std;

int minimo(vector<int> V, int ini, int fin){
    int min_actual = V[ini]; 
    
    for(int i = ini + 1; i <= fin; i++){ 
        if(V[i] < min_actual){
            min_actual = V[i];
        }
    }
    return min_actual;
}

int main(){
    vector<int> numeros = {12, 34, 45, 10};
    
    int valorMinimo = minimo(numeros, 2, 3); 
    
    cout << "El valor minimo en el rango es: " << valorMinimo << endl;
    return 0;
}