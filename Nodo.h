#pragma once
#define NODO_H
#ifdef NODO_H

#include<iostream>
#include<string>
#include"Separate.h"

using namespace std;

class Nodo
{
public:
	Nodo(){}
	Nodo(string S_node);

	Separate *separar = nullptr;
	Nodo* right = NULL; 
	Nodo* left = NULL;
	string _Node, _Operator;
	double int_Node;

	Nodo* Agregar(string S_node);
	void Insertar();
	double Calcular();
};

#endif // !NODO_H