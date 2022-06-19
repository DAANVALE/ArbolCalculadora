#include <iostream>
#include <string>
#include "Separate.h"

using namespace std;
int main()
{
    Separate separar("(5+3)-3+4*20/5");
    cout << separar.Suma();
    cout << endl << ":" << separar.operator_1 << endl << ":" << separar.operator_2 << endl << ":" << separar.operator_3 << endl;
    
    Separate separarizquierda(separar.operator_1);
    cout << separarizquierda.Suma();
    cout << endl << ":" << separarizquierda.operator_1 << endl << ":" << separarizquierda.operator_2 << endl << ":" << separarizquierda.operator_3 << endl;

    Separate separariz(separarizquierda.operator_1);
    cout << separariz.Hierarchy();
    cout << endl << separariz.operator_0;

    return 0;
}