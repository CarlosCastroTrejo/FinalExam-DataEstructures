#pragma once
#include "NodoLigado.h"

class ListaSimpleCircular
{
	NodoLigado*head;
public:
	ListaSimpleCircular();
	void InsertarFin(string, string,string);
	bool Buscar(string );
	void Modificar(string,string,string);
	void BorrarDato(string);

	NodoLigado* getHead();
	void setHead(NodoLigado*);
	friend ostream &operator<< (ostream&, ListaSimpleCircular*);

	~ListaSimpleCircular();
};

