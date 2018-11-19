#include "NodoLigado.h"
#include<locale>
#include<cctype>
#include<string>
#include<sstream>

extern vector<int> IntVector;
extern vector<int> IntVector;
extern vector<string>StringVector;
extern vector<float> FloatVector;
extern vector<double> DoubleVector;
extern vector<char> CharVector;
extern vector<bool> BoolVector;

NodoLigado::NodoLigado(string nombreVariable,string tipoVariable,string valorVariable)
{
	this->sig = NULL;
	this->NombreVariable = nombreVariable;
	this->TipoVariable = tipoVariable;
	this->valorVariable = valorVariable;
}


void NodoLigado::setSig(NodoLigado* s)
{
	this->sig = s;
}


NodoLigado *NodoLigado::getSig()
{
	return sig;
}

string NodoLigado::getNombreVariable()
{
	return this->NombreVariable;
}

string NodoLigado::getTipoVariable()
{
	return this->TipoVariable;
}

string NodoLigado::getValorVariable()
{
	return this->valorVariable;
}


void NodoLigado::setNombreVariable(string nombre)
{
	this->NombreVariable = nombre;
}

void NodoLigado::setTipoVariable(string tipo)
{
	this->TipoVariable = tipo;
}

void NodoLigado::setValorVariable(string valor)
{
	this->valorVariable = valor;
}

ostream &operator<< (ostream &o, NodoLigado* Nodo) 
{
	if (Nodo->getTipoVariable() == "int") 
	{
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << to_string(IntVector[stoi(Nodo->getValorVariable())]);
	}
	if (Nodo->getTipoVariable() == "string")
	{
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << StringVector[stoi(Nodo->getValorVariable())];
	}

	if (Nodo->getTipoVariable() == "float")
	{
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << to_string(FloatVector[stoi(Nodo->getValorVariable())]);
	}
	if (Nodo->getTipoVariable() == "double")
	{
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << to_string(DoubleVector[stoi(Nodo->getValorVariable())]);
	}

	if (Nodo->getTipoVariable() == "char")
	{
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << to_string(CharVector[stoi(Nodo->getValorVariable())]);
	}
	if (Nodo->getTipoVariable() == "bool")
	{
		
		o << Nodo->getNombreVariable() << " - " << Nodo->getTipoVariable() << " - " << to_string(BoolVector[stoi(Nodo->getValorVariable())]);
	}
	return o;
}
NodoLigado::~NodoLigado()
{
}





