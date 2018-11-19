#include "NodoExterior.h"

template<class T>
NodoExterior<T>::NodoExterior(string nombreVariable, string tipoVariable, T valorVariable)
{
	this->NombreVariable = nombreVariable;
	this->TipoVariable = tipoVariable;
	this->valorVariable = valorVariable;
	this->lista = new ListaSimpleCircular();
}

template<class T>
NodoExterior<T>::NodoExterior()
{
	this->NombreVariable = "";
	this->TipoVariable = "";
	this->valorVariable = "";
	this->lista = NULL;
}

template<class T>
ListaSimpleCircular *NodoExterior<T>::getLista()
{
	return this->lista ;
}

template<class T>
string NodoExterior<T>::getNombreVariable()
{
	return this->NombreVariable;
}

template<class T>
string NodoExterior<T>::getTipoVariable()
{
	return this->TipoVariable;
}

template<class T>
T NodoExterior<T>::getValorVariable()
{
	return this->valorVariable;
}

template<class T>
NodoExterior<T>::~NodoExterior()
{
}
