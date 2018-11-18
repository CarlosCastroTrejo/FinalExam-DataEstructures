#pragma once
#include"ListaSimpleCircular.h"
#include<string>
#include<iostream>

using namespace std;

class NodoExterior
{
	string NombreVariable;
	string TipoVariable;
	string valorVariable;
	ListaSimpleCircular *lista;
public:
	NodoExterior();

	NodoExterior(string, string, string);

	string getNombreVariable();

	string getTipoVariable();

	string getValorVariable();

	ListaSimpleCircular* getLista();

	~NodoExterior();
};

