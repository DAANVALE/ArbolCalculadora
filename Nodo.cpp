#include "Nodo.h"
#include <iostream>
#include <string>
#include "Separate.h"

using namespace std;

Nodo::Nodo(string S_node) {
	_Node = S_node;
	Insertar();
}

Nodo* Nodo::Agregar(string S_node) {
	Nodo* nuevo_nodo = new Nodo(S_node);
	return nuevo_nodo;
}

void Nodo::Insertar() {
	separar = new Separate(_Node);

	if (separar->Hierarchy() != _Node) {
		left = Agregar(separar->operator_1);
		right = Agregar(separar->operator_3);
		_Operator = separar->operator_2;
	}
	else {
		int_Node = stoi(_Node);
	}
}

double Nodo::Calcular() {
	if (separar->Hierarchy() != _Node) {
		if (_Operator == "+" ) {
			int_Node = left->Calcular() + right->Calcular();
		}
		else if (_Operator == "-") {
			int_Node = left->Calcular() - right->Calcular();
		}
		else if (_Operator == "*") {
			int_Node = left->Calcular() * right->Calcular();
		}
		else if (_Operator == "/") {
			int_Node = left->Calcular() / right->Calcular();
		}
	}
	return int_Node;
}