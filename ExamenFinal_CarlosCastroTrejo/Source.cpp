// Carlos Emiliano Castro Trejo  -  A01422062
// Examen final Estructuras de Datos  -  19/11/2018
// Proyecto encargado de simular una tabla de simbolos al momento de compilar el codigo. 
// Proyecto implementado usando Hash Tables.
#include"HashTable.h"
#include"Header.h"
#include"Leer.h"
#include<vector>
#include<string>
#include <iomanip>
#include <fstream>
#include<iostream>

using namespace std;

int main() 
{
	HashTable hash(NumeroVariables("texto.txt"));
	string oracion,palabra;

	LeerDocumento("texto.txt",&hash);

	while (oracion != "F")
	{
		cout << "Que deseas hacer?" << endl;
		getline(cin, oracion);
		if (oracion[0] == '@')
		{
			palabra = oracion.substr(1, oracion.length() - 1);
			if (hash.Buscar(palabra)) 
			{
				hash.DeplegarEspecifico(palabra);
			}
			else 
			{
				cout << palabra << " identificador no declarado" << endl;
			}
		}
		else if (oracion[0] == 'I')
		{
			palabra = oracion.substr(2, oracion.length() - 1);
			palabra += " ";
			string nombre, tipo, valor;
			tipo = palabra.substr(0, palabra.find(" "));
			palabra.erase(0, palabra.find(" ") + 1);

			nombre = palabra.substr(0, palabra.find(" "));
			palabra.erase(0, palabra.find(" ") + 1);
			palabra.erase(0, palabra.find(" ") + 1);

			valor = palabra.substr(0, palabra.find(" "));

			if (hash.Buscar(nombre))
			{
				hash.CambiarValor(nombre, tipo, valor);
			}
			else
			{
				hash.Insertar(nombre, tipo, valor);
			}
		}
		else if (oracion[0] == 'B')
		{
			palabra = oracion.substr(2, oracion.length() - 1);
			if (hash.Buscar(palabra))
			{
				hash.Borrar(palabra);
			}
			else
			{
				cout << palabra << " identificador no declarado" << endl;
			}
		}
		else if (oracion[0] == 'D')
		{
			hash.Deplegar();
		}
		
		cout << endl;
	}
	system("pause");
}