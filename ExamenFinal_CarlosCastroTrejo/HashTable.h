#pragma once
#include "NodoExterior.h"
#include"NodoExterior.cpp"
#include<vector>
#include<string>
#include <iomanip>
#include <fstream>
#include<iostream>

using namespace std;
class HashTable
{
	vector < NodoExterior<string>*> myVector; 

public:
	HashTable(int);

	void Insertar(string, string,string);
	void Deplegar();
	void DeplegarEspecifico(string);
	void CambiarValor(string,string,string);
	bool Buscar(string );
	void Borrar(string);
	~HashTable();
};

