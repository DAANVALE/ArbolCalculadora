#include "Separate.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include <cstring>

using namespace std;

Separate::Separate(string operator_) {
	operator_0 = operator_;
}

string Separate::Suma(){
	int contadorparentesis = 0;
	int coordenadadato = 0;
	char* dato = new char[operator_0.length() + 1];

	char* izquierda;
	char* derecha;

	strcpy_s(dato, operator_0.length() + 1 , operator_0.c_str());

	for (int i = 0; i < operator_0.length() + 1; i++) {
		if (dato[i] == '(') {
			contadorparentesis++;
		}
		if (dato[i] == ')') {
			contadorparentesis--;
		}
		if (contadorparentesis == 0) {
			if (dato[i] == '+' || dato[i] == '-') {
				operator_2 = dato[i];
				coordenadadato = i;
				izquierda = new char[coordenadadato + 1];
				derecha = new char[operator_0.length() - coordenadadato + 1];

				for (int j = 0; j < operator_0.length() + 1; j++) {
					if (j < coordenadadato) { izquierda[j] = dato[j]; }
					if (j > coordenadadato){ derecha[j - coordenadadato - 1] = dato[j]; }
				}

				izquierda[coordenadadato] = '\0';
				derecha[operator_0.length() - coordenadadato] = '\0';

				operator_1 = izquierda;
				operator_3 = derecha;
			}
		}
	}
	return operator_2;
}

string Separate::Multiplicacion() {
	int contadorparentesis = 0;
	int coordenadadato = 0;
	char* dato = new char[operator_0.length() + 1];

	char* izquierda;
	char* derecha;

	strcpy_s(dato, operator_0.length() + 1, operator_0.c_str());

	for (int i = 0; i < operator_0.length() + 1; i++) {
		if (dato[i] == '(') {
			contadorparentesis++;
		}
		if (dato[i] == ')') {
			contadorparentesis--;
		}
		if (contadorparentesis == 0) {
			if (dato[i] == '*' || dato[i] == '/') {
				operator_2 = dato[i];
				coordenadadato = i;
				izquierda = new char[coordenadadato + 1];
				derecha = new char[operator_0.length() - coordenadadato + 1];

				for (int j = 0; j < operator_0.length() + 1; j++) {
					if (j < coordenadadato) { izquierda[j] = dato[j]; }
					if (j > coordenadadato) { derecha[j - coordenadadato - 1] = dato[j]; }
				}

				izquierda[coordenadadato] = '\0';
				derecha[operator_0.length() - coordenadadato] = '\0';

				operator_1 = izquierda;
				operator_3 = derecha;
			}
		}
	}
	return operator_2;
}

string Separate::Parentesis() {
	int left_parentesis = 0, rigth_parentesis = 0;
	int left_coordenada = 0, rigth_coordenada = 0;
	char* dato = new char[operator_0.length() + 1];

	char* centro = new char[operator_0.length() - 1];

	strcpy_s(dato, operator_0.length() + 1, operator_0.c_str());

	for (int i = 0; i < operator_0.length() + 1; i++) {
		if (dato[i] == '(') {
			left_parentesis++;
			if (left_parentesis == 1) {
				left_coordenada = i;
			}
		}
		if (dato[i] == ')') {
			rigth_parentesis++;
			left_parentesis--;
			if (left_parentesis == 0) {
				rigth_coordenada = i;
			}
		}

		for (int j = 1; j < rigth_coordenada; j++) {
			centro[j - 1] = dato[j];
		}
	}
	centro[operator_0.length() - 2] = '\0';
	operator_0 = centro;
	return Hierarchy();
}

string Separate::Hierarchy() {
	char* dato = new char[operator_0.length() + 1];
	strcpy_s(dato, operator_0.length() + 1, operator_0.c_str());
	
	int parentesis_iz = 0, parentesis_der = 0;
	
	for (int i = 0; i < operator_0.length() + 1; i++) {

		if (dato[i] == '(') { parentesis_iz++; }
		if (dato[i] == ')') { parentesis_iz--; parentesis_der++; }

		if ((dato[i] == '+' || dato[i] == '-') && parentesis_iz == 0) {
			return Suma();
		}
	}

	parentesis_iz = 0; parentesis_der = 0;

	for (int i = 0; i < operator_0.length() + 1; i++) {

		if (dato[i] == '(') { parentesis_iz++; }
		if (dato[i] == ')') { parentesis_iz--; parentesis_der++; }

		if ((dato[i] == '*' || dato[i] == '/') && parentesis_iz == 0) {
			return Multiplicacion();
		}
	}

	parentesis_iz = 0; parentesis_der = 0;

	for (int i = 0; i < operator_0.length(); i++) {

		if (dato[i] == '(') { parentesis_iz++; }
		if (dato[i] == ')') { parentesis_iz--; parentesis_der++; }

		if ((dato[i] == '(' || dato[i] == ')') && parentesis_iz == 0) {
			return Parentesis();
		}
	}

	return operator_0;
}

//Leer el ultimo parentesis anidado o el primero de la operacion
/*string Separate::parentesis() {
	int parentesis_inicio = 0;
	int parentesis_final = 0;
	int posicionindicador[3];
	//indicador 1 es para guardar temporal el espacio que se encontro (
	//indicador 2 es para guardar fijo el lugar de (
	//indicador 3 es para guardar fijo el lugar de )
	char* operator_char = new char[operator_0.length() + 1];
	strcpy_s(operator_char, operator_0.length() + 1, operator_0.c_str());

	for (int i = 0; i < (operator_0.length() + 1); i++) {
		if (operator_char[i] == '(') {
			parentesis_inicio++;
			posicionindicador[0] = i;
		}
		if (operator_char[i] == ')') {
			parentesis_final++;
			if (parentesis_final == 1) {
				posicionindicador[1] = posicionindicador[0];
				posicionindicador[2] = i;
			}
		}
	}

	for (int i = posicionindicador[1] + 1; i < posicionindicador[2]; i++) {
		cout << operator_char[i];
	}

	operator_0 = operator_char;
	
	return operator_0;
}*/