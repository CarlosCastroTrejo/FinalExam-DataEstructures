#include "HashTable.h"
#include "ListaSimpleCircular.h"
#include<string>
#include<sstream>

HashTable::HashTable(int numeroVariables)
{
	myVector.resize(numeroVariables,new NodoExterior());
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
		
		myVector[locacion] = new NodoExterior(nombreVariable, tipoVariable, valorVariable);
		
		
	}
	else 
	{
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

vector < NodoExterior*> HashTable::getMyVector()
{
	return this->myVector;
}

HashTable::~HashTable()
{
}
