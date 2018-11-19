#pragma once
#include"ListaSimpleCircular.h"
#include<string>
#include<iostream>

using namespace std;

template<class T>
class NodoExterior
{
	string NombreVariable;
	string TipoVariable;
	T valorVariable;
	ListaSimpleCircular *lista;
public:
	NodoExterior();

	NodoExterior(string, string, T);

	string getNombreVariable();

	string getTipoVariable();

	T getValorVariable();

	ListaSimpleCircular* getLista();

	~NodoExterior();
};

