#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


void clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int main(){
    int option;
    while (true)
    {
        cout << "Ingrese la opcion: ";
        cin >> option;
        switch (option)
        {
        case 1:
            clearTerminal();
            break;
        
        default:
            break;
        }
    }
        
}