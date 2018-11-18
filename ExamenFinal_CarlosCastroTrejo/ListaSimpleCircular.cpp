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

void ListaSimpleCircular::BorrarDato(string nombreVariable)
{

	/*if (!head) {
		cout << "Lista vacia" << endl;
	}
	else {
		NodoLigado *temp = head;
		while (temp->Get_id() != dato && temp->Get_sig() != NULL) {
			temp = temp->Get_sig();
		}
		if (temp->Get_sig() == NULL) {
			if (temp->Get_id() == dato) {
				NodoLigado *borrar = head;
				if (temp == borrar) {
					head = NULL;
					delete borrar;
				}
				else {
					while (borrar->Get_sig() != temp) {
						borrar = borrar->Get_sig();
					}
					borrar->Set_sig(NULL);
					delete temp;
				}
			}
			else {
				cout << "No se encuentra el dato solicitado" << endl;
			}
		}
		else {
			NodoLigado *borrar = head;
			if (borrar == temp) {
				head = head->Get_sig();
				delete borrar;
			}
			else {
				while (borrar->Get_sig() != temp) {
					borrar = borrar->Get_sig();
				}
				borrar->Set_sig(temp->Get_sig());
				delete temp;
			}
		}
	}*/
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





