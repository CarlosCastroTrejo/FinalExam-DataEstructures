#include "HashTable.h"
#include "ListaSimpleCircular.h"
#include<string>
#include<sstream>

HashTable::HashTable(int numeroVariables)
{
	myVector.resize(numeroVariables,new NodoExterior<string>());
}

void HashTable::Insertar(string nombreVariable,string tipoVariable,string valorVariable)
{
	int val = 0;
	for (int x = 0; x < nombreVariable.length(); x++) 
	{
		val += nombreVariable[x];
	}

	int locacion =val%myVector.size();
	if (myVector[locacion]->getNombreVariable()=="") 
	{
		
		if (tipoVariable == "int")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
			tipoVariable = "0";
		}
		else if (tipoVariable == "string")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
			tipoVariable = " ";
		}
		else if (tipoVariable == "float")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
			tipoVariable = "0";
		}
		else if (tipoVariable == "double")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
			tipoVariable = "0";
		}
		else if (tipoVariable == "char")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);

			tipoVariable = " ";
		}
		else if (tipoVariable == "bool")
		{
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
			tipoVariable = "true";
		}		

	}
	else 
	{
		/*if (tipoVariable == "int")
		{
			tipoVariable = "0";
		}
		else if (tipoVariable == "string")
		{
			tipoVariable = " ";
		}
		else if (tipoVariable == "float")
		{
			tipoVariable = "0";
		}
		else if (tipoVariable == "double")
		{
			tipoVariable = "0";
		}
		else if (tipoVariable == "char")
		{
			tipoVariable = " ";
		}
		else if (tipoVariable == "bool")
		{
			tipoVariable = "true";
		}*/
		myVector[locacion]->getLista()->InsertarFin(nombreVariable, tipoVariable, valorVariable);
	}

}

void HashTable::Deplegar()
{
	for (int x = 0; x < myVector.size(); x++) 
	{
		cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << myVector[x]->getValorVariable() << "  "<<myVector[x]->getLista() << endl;
	}

}

void HashTable::DeplegarEspecifico(string nombre)
{
	int val = 0;
	for (int x = 0; x < nombre.length(); x++)
	{
		val += nombre[x];
	}
	int locacion = val % myVector.size();
	cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << myVector[locacion]->getValorVariable() << "  " << myVector[locacion]->getLista() << endl;
}

bool HashTable::Buscar(string nombre)
{
	int val = 0;
	for (int x = 0; x < nombre.length(); x++)
	{
		val += nombre[x];
	}
	int locacion = val % myVector.size();

	if (myVector[locacion]->getNombreVariable() == "") 
	{
		return false;
	}
	else if (myVector[locacion]->getNombreVariable() != "")
	{
		if (myVector[locacion]->getLista()->Buscar(nombre) || myVector[locacion]->getNombreVariable() == nombre)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

}

void HashTable::CambiarValor(string nombre,string tipo,string valor)
{
	int val = 0;
	for (int x = 0; x < nombre.length(); x++)
	{
		val += nombre[x];
	}
	int locacion = val % myVector.size();
	if (myVector[locacion]->getNombreVariable() == nombre)
	{
		myVector[locacion] = new NodoExterior<string>(nombre, tipo, valor);
	}
	else 
	{
		myVector[locacion]->getLista()->Modificar(nombre, tipo, valor);

	}
	

}

void HashTable::Borrar(string nombre) 
{
	int val = 0;
	for (int x = 0; x < nombre.length(); x++)
	{
		val += nombre[x];
	}
	int locacion = val % myVector.size();

	if (myVector[locacion]->getNombreVariable() == nombre) 
	{
		myVector[locacion] = new NodoExterior<string>("", "", "");
	}
	else 
	{
		myVector[locacion]->getLista()->BorrarDato(nombre);
	}
}

HashTable::~HashTable()
{
}
