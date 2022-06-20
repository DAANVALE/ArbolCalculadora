#include <iostream>
#include <string>
#include "Separate.h"
#include "Nodo.h"

using namespace std;

void run();
string eliminarespacios(string);

int main()
{
    run();
    return 0;
}

string eliminarespacios(string operacion) {
    char* dato;
    dato = new char[operacion.length() + 1];
    char* remplazo;
    remplazo = new char[operacion.length() + 1];
    int indice = 0;

    strcpy_s(dato, operacion.length() + 1, operacion.c_str());
    dato[operacion.length()] = '\0';

    for (int i = 0; i < operacion.length() + 1; i++) {
        if (dato[i] != ' ') {
            remplazo[indice] = dato[i];
            indice++;
        }
    }

    remplazo[indice] = '\0';
    operacion = remplazo;
    return operacion;
}

void run() {
    string operacion;
    cout << "Ingrese la operacion a realizar: \nvalores permitidos:: + - / * ( )\n";
    getline(cin, operacion);

    Nodo* arbol = new Nodo(eliminarespacios(operacion));
    cout << endl << arbol->Calcular() << endl;
}