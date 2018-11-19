#include "NodoLigado.h"



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

ostream &operator<< (ostream &o, NodoLigado* Nodo) {

	o << Nodo->getNombreVariable() << " " << Nodo->getTipoVariable() << " " << Nodo->getValorVariable();
	return o;
}
NodoLigado::~NodoLigado()
{
}





