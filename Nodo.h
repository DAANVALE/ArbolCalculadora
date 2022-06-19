#pragma once
#define NODO_H
#ifdef NODO_H

#include<iostream>
#include<string>

using namespace std;

class Nodo
{
public:
	Nodo(){}
	Nodo(string S_node);

	Nodo* right; 
	Nodo* left;
	string _Node, _Right, _Left, _Operator;
	double area_Node, area_Right, area_Left;

	Nodo* Agregar(string S_node);
	string Separar();
	double Calcular();
};

#endif // !NODO_H