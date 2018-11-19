#pragma once
#include<string>
#include <iomanip>
#include <fstream>
#include<iostream>
#include <queue>

using namespace std;


void Valores(string oracion, HashTable* hash,string tipo)
{
	queue<string> myQueue;
	string x;
	while (oracion.length() > 0) 
	{
		x = oracion.substr(0, oracion.find(" "));
		oracion.erase(0, oracion.find(" ") + 1);
		if (x != "=") 
		{
			if (x[x.length() - 1] == ',') 
			{
				x.erase(x.length() - 1, 1);
			}
			myQueue.push(x);
		}
	}

	string nombre="";
	string valor="";
	while (!myQueue.empty())
	{
		nombre = myQueue.front();
		myQueue.pop();
		if (!myQueue.empty()  )
		{
			if ( tipo == "bool" ) 
			{
				valor = myQueue.front();
				myQueue.pop();
			
			}
			else if (tipo == "string") 
			{
				if (myQueue.front()[0] == 34) 
				{
					valor = myQueue.front();
					myQueue.pop();
				}
			}
			else if (tipo == "char") 
			{
				if (myQueue.front()[0] == 39)
				{
					valor = myQueue.front();
					myQueue.pop();
				}
			}
			else 
			{
				if (myQueue.front()[0] >= 48 && myQueue.front()[0] <= 57) 
				{
					valor = myQueue.front();
					myQueue.pop();
				}
			}
		}
		else 
		{
			if (tipo == "int") 
			{
				valor = "0";
			}
			else if (tipo == "string")
			{
				valor = " " " ";
			}
			else if (tipo == "float") 
			{
				valor = "0";
			}
			else if (tipo == "double")
			{
				valor = "0";
			}
			else if (tipo == "char")
			{
				valor = "' '";
			}
			else if (tipo == "bool")
			{
				valor = "true";
			}
		}
		hash->Insertar(nombre, tipo, valor);
	}
}

int Val(string oracion)
{
	int number=0;
	queue<string> myQueue;
	string x;
	while (oracion.length() > 0)
	{
		x = oracion.substr(0, oracion.find(" "));
		oracion.erase(0, oracion.find(" ") + 1);
		if (x != "=")
		{
			myQueue.push(x);
		}
	}

	string nombre = "";
	string valor = "";
	while (!myQueue.empty())
	{
		nombre = myQueue.front();
		myQueue.pop();
		if (!myQueue.empty() || (myQueue.front()[0] >= 48 && myQueue.front()[0] <= 57) || myQueue.front()[0] == 34)
		{
			valor = myQueue.front();
			myQueue.pop();
		}
		else
		{

		}
		number++;

	}
	return number;

}

void LeerDocumento(string nombreTexto,HashTable* myHash) 
{
	string oracion, palabra;
	ifstream archivo;
	archivo.open(nombreTexto);

	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			getline(archivo, oracion);
			if (oracion.length() >= 1)
			{
				if (oracion[0] == ' ')
				{
					while (oracion[0] == ' ')
					{
						oracion.erase(oracion.find(" "), oracion.find(" ") + 1);
					}
				}
				if (oracion[0] == 9)
				{
					while (oracion[0] == 9)
					{
						oracion.erase(0, oracion.find(9) + 1);
					}
				}
				oracion += ' ';
				while(oracion.find("(") != string::npos)
				{

					oracion.replace(oracion.find("("), 1, " ");
				}
				while (oracion.find(")") != string::npos)
				{

					oracion.replace(oracion.find(")"), 1, " ");
				}
				while (oracion.length()>0)
				{
					palabra = oracion.substr(0, oracion.find(' '));
					if (palabra == "int")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion.find(";") != string::npos)
						{
							oracion = oracion.substr(0, oracion.find(';'));
							oracion += " ";
							Valores(oracion, myHash, "int");
						}
					}
					else if (palabra == "string") 
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							Valores(oracion, myHash, "string");
						}
					}
					else if (palabra == "float")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							Valores(oracion, myHash, "float");
						}
					}
					else if (palabra == "double")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							Valores(oracion, myHash, "double");
						}
					}
					else if (palabra == "char")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							Valores(oracion, myHash, "char");
						}
					}
					else if (palabra == "bool")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion.find(";") != string::npos)
						{
							oracion = oracion.substr(0, oracion.find(';'));
							oracion += " ";
							Valores(oracion, myHash, "bool");
						}
					}
					else
					{
						oracion.erase(0, oracion.find(' ') + 1);
					}
					oracion.erase(0, oracion.find(' ') + 1);

				}
			}
		}
		archivo.close();
	}

}

int NumeroVariables(string nombreTexto) 
{
	int number = 0;
	string oracion, palabra;
	ifstream archivo;
	archivo.open(nombreTexto);

	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			getline(archivo, oracion);
			if (oracion.length() >= 1)
			{
				if (oracion[0] == ' ')
				{
					while (oracion[0] == ' ')
					{
						oracion.erase(oracion.find(" "), oracion.find(" ") + 1);
					}
				}
				if (oracion[0] == 9)
				{
					while (oracion[0] == 9)
					{
						oracion.erase(0, oracion.find(9) + 1);
					}
				}
				oracion += ' ';
				while (oracion.find("(") != string::npos)
				{

					oracion.replace(oracion.find("("), 1, " ");
				}
				while (oracion.find(")") != string::npos)
				{

					oracion.replace(oracion.find(")"), 1, " ");
				}
				while (oracion.length()>0)
				{
					palabra = oracion.substr(0, oracion.find(' '));
					if (palabra == "int")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion.find(";") != string::npos)
						{

							oracion = oracion.substr(0, oracion.find(';'));
							oracion += " ";
							number+=Val(oracion);
						}
					}
					else if (palabra == "string")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							number+=Val(oracion);
						}
					}
					else if (palabra == "float")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							number+=Val(oracion);
						}
					}
					else if (palabra == "double")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							number+=Val(oracion);
						}
					}
					else if (palabra == "char")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							number+=Val(oracion);
						}
					}
					else if (palabra == "bool")
					{
						oracion.erase(0, oracion.find(' ') + 1);
						if (oracion[oracion.length() - 2] == ';')
						{
							oracion.erase(oracion.length() - 2, 1);
							number+=Val(oracion);
						}
					}
					else
					{
						oracion.erase(0, oracion.find(' ') + 1);
					}
					oracion.erase(0, oracion.find(' ') + 1);

				}
			}
		}
		archivo.close();
	}
	return number;
}
