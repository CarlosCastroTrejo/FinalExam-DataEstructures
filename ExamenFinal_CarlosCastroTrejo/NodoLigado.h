#pragma once

#include<string>
#include <iomanip>
#include <fstream>
#include<iostream>
using namespace std;

class NodoLigado
{
	string NombreVariable;
	string TipoVariable;
	string valorVariable;
	NodoLigado *sig;

public:
	NodoLigado(string, string, string);

	void setSig(NodoLigado*);

	NodoLigado*getSig();

	string getNombreVariable();

	string getTipoVariable();

	string getValorVariable();

	void setNombreVariable(string);

	void setTipoVariable(string);

	void setValorVariable(string);

	friend ostream &operator<< (ostream&, NodoLigado*);

	~NodoLigado();
};



