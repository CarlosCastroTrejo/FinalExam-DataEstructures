#include "ListaSimpleCircular.h"




ListaSimpleCircular::ListaSimpleCircular()
{
	this->head = NULL;
}


void ListaSimpleCircular::InsertarFin(string nombreVariable, string tipoVariable, string valorVariable) 
{
	NodoLigado *aux = new NodoLigado(nombreVariable,tipoVariable,valorVariable);
	
	if (this->head == NULL) 
	{
		head = aux;
	}
	else 
	{
		NodoLigado *temp = head;
		while (temp->getSig() != NULL) 
		{
			temp = temp->getSig();
		}
		temp->setSig(aux);

	}
}

bool ListaSimpleCircular::Buscar(string nombre) 
{
	if (!head) 
	{
		return false;
	}
	else 
	{
		NodoLigado *temp = head;
		while (temp != NULL)
		{
			if (temp->getNombreVariable() == nombre) 
			{
				return true;
			}

			temp = temp->getSig();
		}
		return false;
	}
}

void ListaSimpleCircular::Modificar(string nombre,string tipo,string valor)
{
	
	NodoLigado *auxiliar = new NodoLigado(nombre, tipo,valor);
	NodoLigado *auxiliarUltimo = head;

	
	while (auxiliarUltimo != NULL && auxiliar->getNombreVariable() != auxiliarUltimo->getNombreVariable())
	{
		auxiliarUltimo = auxiliarUltimo->getSig();

	}
	auxiliarUltimo->setNombreVariable(nombre);
	auxiliarUltimo->setTipoVariable(tipo);
	auxiliarUltimo->setValorVariable(valor);
}

void ListaSimpleCircular::BorrarDato(string nombre)
{
	
		NodoLigado *temp = head;
		while (temp->getNombreVariable() != nombre && temp != NULL) {
			temp = temp->getSig();
		}
		if (temp->getSig() == NULL) 
		{
			if (temp->getNombreVariable() == nombre) 
			{
				NodoLigado *borrar = head;
				if (temp == borrar) {
					head = NULL;
					delete borrar;
				}
				else {
					while (borrar->getSig() != temp) {
						borrar = borrar->getSig();
					}
					borrar->setSig(NULL);
					delete temp;
				}
			}
		}
		else {
			NodoLigado *borrar = head;
			if (borrar == temp) {
				head = head->getSig();
				delete borrar;
			}
			else {
				while (borrar->getSig() != temp) {
					borrar = borrar->getSig();
				}
				borrar->setSig(temp->getSig());
				delete temp;
			}
		}
}


NodoLigado* ListaSimpleCircular::getHead()
{
	return this->head;
}

void ListaSimpleCircular::setHead(NodoLigado *head)
{
	this->head = head;
}

ostream &operator<< (ostream &o, ListaSimpleCircular* lista)
{
	if (lista == NULL)
	{

	}
	else if (lista->head == NULL)
	{

	}
	else
	{
		NodoLigado *temp = lista->head;
		while (temp != NULL)
		{
			o << " ----> ";
			o << temp;
			temp = temp->getSig();
		}

	}
	return o;
}

ListaSimpleCircular::~ListaSimpleCircular()
{
}





