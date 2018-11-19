#include "HashTable.h"
#include "ListaSimpleCircular.h"
#include<locale>
#include<cctype>
#include<string>
#include<sstream>

extern vector<int> IntVector;
extern vector<int> IntVector;
extern vector<string>StringVector;
extern vector<float> FloatVector;
extern vector<double> DoubleVector;
extern vector<char> CharVector;
extern vector<bool> BoolVector;

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
			int x = stoi(valorVariable);
			IntVector.push_back(x);
			valorVariable = to_string(IntVector.size()-1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}
		else if (tipoVariable == "string")
		{
			StringVector.push_back(valorVariable);
			valorVariable = to_string(StringVector.size()-1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}
		else if (tipoVariable == "float")
		{
			float x = stof(valorVariable);
			FloatVector.push_back(x);
			valorVariable = to_string(FloatVector.size() - 1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}
		else if (tipoVariable == "double")
		{
			double x = stod(valorVariable);
			DoubleVector.push_back(x);
			valorVariable = to_string(DoubleVector.size() - 1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}
		else if (tipoVariable == "char")
		{
			char x = valorVariable[0];
			CharVector.push_back(x);
			valorVariable = to_string(CharVector.size() - 1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}
		else if (tipoVariable == "bool")
		{
			bool x;
			if (valorVariable.find("true") == string::npos)
			{
				x = true;
			}
			else 
			{
				x = false;
			}
			BoolVector.push_back(x);
			valorVariable = to_string(BoolVector.size() - 1);
			myVector[locacion] = new NodoExterior<string>(nombreVariable, tipoVariable, valorVariable);
		}		

	}
	else 
	{
		if (tipoVariable == "int")
		{
			int x = stoi(valorVariable);
			IntVector.push_back(x);
			valorVariable = to_string(IntVector.size() - 1);
		}
		else if (tipoVariable == "string")
		{
			StringVector.push_back(valorVariable);
			valorVariable = to_string(StringVector.size() - 1);
		}
		else if (tipoVariable == "float")
		{
			float x = stof(valorVariable);
			FloatVector.push_back(x);
			valorVariable = to_string(FloatVector.size() - 1);
		}
		else if (tipoVariable == "double")
		{
			double x = stod(valorVariable);
			DoubleVector.push_back(x);
			valorVariable = to_string(DoubleVector.size() - 1);
		}
		else if (tipoVariable == "char")
		{
			char x = valorVariable[0];
			CharVector.push_back(x);
			valorVariable = to_string(CharVector.size() - 1);
		}
		else if (tipoVariable == "bool")
		{
			bool x;
			if (valorVariable=="true")
			{
				x =true;
			}
			else
			{
				x = false;
			}
			BoolVector.push_back(x);
			valorVariable = to_string(BoolVector.size() - 1);
		}
		myVector[locacion]->getLista()->InsertarFin(nombreVariable, tipoVariable, valorVariable);
	}
	
}

void HashTable::Deplegar()
{
	for (int x = 0; x < myVector.size(); x++) 
	{
		if (myVector[x]->getTipoVariable() == "int") 
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << IntVector[ stoi(myVector[x]->getValorVariable()) ]<< "  ||| " << myVector[x]->getLista() << endl;
		}
		else if (myVector[x]->getTipoVariable() == "string")
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << StringVector[stoi(myVector[x]->getValorVariable())] << "  ||| " << myVector[x]->getLista() << endl;
		}
		else if (myVector[x]->getTipoVariable() == "float")
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << FloatVector[stoi(myVector[x]->getValorVariable())] << "  ||| " << myVector[x]->getLista() << endl;
		}
		else if (myVector[x]->getTipoVariable() == "double")
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << DoubleVector[stoi(myVector[x]->getValorVariable())] << "  ||| " << myVector[x]->getLista() << endl;
		}
		else if (myVector[x]->getTipoVariable() == "char")
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << CharVector[stoi(myVector[x]->getValorVariable())] << "  ||| " << myVector[x]->getLista() << endl;
		}
		else if (myVector[x]->getTipoVariable() == "bool")
		{
			cout << x << " " << myVector[x]->getNombreVariable() << " - " << myVector[x]->getTipoVariable() << " - " << BoolVector[stoi(myVector[x]->getValorVariable())] << "  ||| " << myVector[x]->getLista() << endl;
		}
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

	if (myVector[locacion]->getTipoVariable() == "int")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << IntVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
	else if (myVector[locacion]->getTipoVariable() == "string")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << StringVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
	else if (myVector[locacion]->getTipoVariable() == "float")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << FloatVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
	else if (myVector[locacion]->getTipoVariable() == "double")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << DoubleVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
	else if (myVector[locacion]->getTipoVariable() == "char")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << CharVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
	else if (myVector[locacion]->getTipoVariable() == "bool")
	{
		cout << locacion << " " << myVector[locacion]->getNombreVariable() << " - " << myVector[locacion]->getTipoVariable() << " - " << BoolVector[stoi(myVector[locacion]->getValorVariable())] << "  ||| " << myVector[locacion]->getLista() << endl;
	}
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

	if (tipo == "int")
	{
		int x = stoi(valor);
		IntVector.push_back(x);
		valor = to_string(IntVector.size() - 1);
	}
	else if (tipo == "string")
	{
		StringVector.push_back(valor);
		valor = to_string(StringVector.size() - 1);
	}
	else if (tipo == "float")
	{
		float x = stof(valor);
		FloatVector.push_back(x);
		valor = to_string(FloatVector.size() - 1);
	}
	else if (tipo == "double")
	{
		double x = stod(valor);
		DoubleVector.push_back(x);
		valor = to_string(DoubleVector.size() - 1);
	}
	else if (tipo == "char")
	{
		char x = valor[0];
		CharVector.push_back(x);
		valor = to_string(CharVector.size() - 1);
	}
	else if (tipo == "bool")
	{
		bool x;
		if (valor.find("true") == string::npos)
		{
			x = true;
		}
		else
		{
			x = false;
		}
		BoolVector.push_back(x);
		valor = to_string(BoolVector.size() - 1);
	}

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
