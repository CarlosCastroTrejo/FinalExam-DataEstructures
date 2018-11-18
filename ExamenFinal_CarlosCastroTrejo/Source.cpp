#include"HashTable.h"
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

	/*hash.Insertar("Nombres", "int", "10");
	hash.Insertar("Nombres", "int", "10");
	hash.Insertar("Nombres", "int", "10");

	hash.Insertar("Nombre", "int", "10");*/


	while (oracion != "F")
	{
		cout << "Que deseas hacer" << endl;
		getline(cin, oracion);
		//			oracion = oracion.substr(2, oracion.length() - 1);

		if (oracion[0] == '@')
		{
		}
		else if (oracion[0] == 'I')
		{
		}
		else if (oracion[0] == 'B')
		{
		}
		else if (oracion[0] == 'D')
		{
			hash.Deplegar();
		}
		
		cout << endl;
	}
	system("pause");
}