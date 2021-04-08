#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct Avion
{
	char* producator;
	int nrAvion;
	int nrLocuri;
	bool isComercial;
};

struct nod
{
	Avion avion;
	nod* next;
};

Avion citireAvion() {
	Avion avion;
	char buffer[30];
	cout << "Dati nume producator" << endl;
	cin >> buffer;
	avion.producator = new char[strlen(buffer) + 1];
	strcpy(avion.producator, buffer);
	cout << "Dati nrAvion" << endl;
	cin >> avion.nrAvion;
	cout << "Dati nrLocuri" << endl;
	cin >> avion.nrLocuri;
	cout << "Avion este comercial sau nu(1-da/0-nu)" << endl;
	cin >> avion.isComercial;
	return avion;
}

nod* inserareInceput(nod* lista, Avion avion ) {
	nod* nou = new nod;
	nou->avion = avion;
	nou->next = nullptr;
	if (lista != nullptr) {
		nou->next = lista;
		lista = nou;
	}
	else {
		return nou;
	}
}

nod* inserareLaSfarsit(nod* lista, Avion avion) {
	nod* nou = new nod;
	nou->avion = avion;
	nou->next = nullptr;
	if (lista != nullptr) {
		nod* temp = lista;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
		return lista;
	}
	else {
		return nou;
	}

	
}

void afisareAvion(Avion a) {
	cout << "Avionul cu numarul " << a.nrAvion << " produs de " << a.producator << " are un numar de locuri de " << a.nrLocuri;
	if (a.isComercial == true) {
		cout << " si este comercial"<<endl;
	}
	else {
		cout << " si nu este comercial" << endl;
	}
}

void traversareLista(nod* cap) {
	nod* temp = cap;
	while (temp) {
		afisareAvion(temp->avion);
		temp = temp->next;
	}
}

void dezalocare(nod* lista) {
	nod* temp = lista;
	while (temp) {
		delete[]temp->avion.producator;
		temp = temp->next;
	}
	delete lista;
}

nod* stergereNod(nod** lista,const char* producator) {
	nod* temp = *lista;
	while (temp->next) {
			if (strcmp(temp->next->avion.producator, producator) == 0) {
			nod* temp2 = temp->next;
			temp->next = temp->next->next;
			delete[]temp2->avion.producator;
			delete temp2;
		}
		temp = temp->next;
	}
	return *lista;
}

Avion* conversieListaVector(nod* lista, int* nrElemente) {
	Avion* vector = new Avion[*nrElemente];
	int i = 0;
		nod* temp = lista;
		while (temp) {
			vector[i] = temp->avion;
			i++;
			temp = temp->next;
		}

		return vector;
	

}



void main() {
	nod* lista = nullptr;
	ifstream f;
	f.open("avioane.txt");
	char buffer[30];
	int nrElementeLista;
	f >> nrElementeLista;
	for (int i = 0; i < nrElementeLista; i++) {
		Avion avion;
		f >> buffer;
		avion.producator = new char[strlen(buffer) + 1];
		strcpy(avion.producator, buffer);
		f >> avion.nrAvion;
		f >> avion.nrLocuri;
		f >> avion.isComercial;

		lista = inserareLaSfarsit(lista,avion);
	}

	traversareLista(lista);

	cout << "-----------------AFISARE LISTA STERGERE-----------------------" << endl;
	lista = stergereNod(&lista, "BMW");
	nrElementeLista--;
	traversareLista(lista);
	cout << "-----------------------------------------------AFISARE VECTOR DUPA CONVERSIE----------------------------------------" << endl;
	
	Avion* vector = conversieListaVector(lista,&nrElementeLista);
	for (int i = 0; i < nrElementeLista; i++) {
		afisareAvion(vector[i]);
	}
	dezalocare(lista);
}
