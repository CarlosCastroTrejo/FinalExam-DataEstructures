#pragma once
#include "NodoExterior.h"
#include<vector>
#include<string>
#include <iomanip>
#include <fstream>
#include<iostream>

using namespace std;

class HashTable
{

	vector < NodoExterior*> myVector;

public:
	HashTable(int);

	void Insertar(string, string,string);
	void Deplegar();

	vector < NodoExterior*> getMyVector();
	~HashTable();
};

