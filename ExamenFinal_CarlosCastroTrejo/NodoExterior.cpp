#include "NodoExterior.h"

NodoExterior::NodoExterior(string nombreVariable, string tipoVariable, string valorVariable)
{
	this->NombreVariable = nombreVariable;
	this->TipoVariable = tipoVariable;
	this->valorVariable = valorVariable;
	this->lista = new ListaSimpleCircular();
}

NodoExterior::NodoExterior()
{
	this->NombreVariable = "";
	this->TipoVariable = "";
	this->valorVariable = "";
	this->lista = NULL;
}

ListaSimpleCircular *NodoExterior::getLista()
{
	return this->lista ;
}

string NodoExterior::getNombreVariable()
{
	return this->NombreVariable;
}

string NodoExterior::getTipoVariable()
{
	return this->TipoVariable;
}

string NodoExterior::getValorVariable()
{
	return this->valorVariable;
}

NodoExterior::~NodoExterior()
{
}
