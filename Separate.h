#pragma once
#define SEPARATE_H
#ifndef SEPARATE_h

#include<iostream>
#include<string>

using namespace std;

class Separate
{
public:
	Separate() {}
	Separate(string operator_);

	string operator_0 = "", operator_1, operator_2, operator_3;
	string Hierarchy();
	string Parentesis();
	string Multiplicacion();
	string Suma();
};

#endif // !SEPARATE_h