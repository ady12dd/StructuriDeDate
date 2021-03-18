#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdint.h>

using namespace std;

struct Masina
{
	char* nume;
	float cilindree;
	float pret;
};

Masina creareMasina(const char* nume, float cilindree, float pret) {
	Masina masina;
	masina.nume = new char[strlen(nume) + 1];
	strcpy(masina.nume, nume);
	masina.cilindree = cilindree;
	masina.pret = pret;
	return masina;
}

void afisareMasina(Masina masina) {

	cout << "Masina cu numele " << masina.nume << " are o cilindree de " << masina.cilindree
		<< " si are pretul " << masina.pret << " $" << endl;
}

Masina citireMasina() {
	Masina masina;
	char buffer[30];
	cout << "Dati nume masina: ";
	cin >> buffer;
	masina.nume = new char[strlen(buffer) + 1];
	strcpy(masina.nume, buffer);
	cout << "Dati cilindree masina: ";
	cin >> masina.cilindree;
	cout << "Dati pret masina: ";
	cin >> masina.pret;
	return masina;
}

struct Nod
{
	Masina info;
	Nod* next;
};

//inserare nod

Nod* inserareNodLaSfarsit(Nod* lista) {
	if (lista == NULL) { // daca este lista goala, acesta este primul nod
		Nod* nou = new Nod;
		nou->info = citireMasina();
		nou->next = nullptr;
		lista = nou;
		return lista;
	}
	else {
		Nod* nou = new Nod; //daca lista nu este goala, nodul se adauga in lista
		nou->info = citireMasina();
		nou->next = nullptr;
		Nod* temp;
		temp = lista;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
		return lista;
	}
}

//traversare lista

void traversareLista(Nod* lista) {
	Nod* temp = lista;
	while (temp) {

		afisareMasina(temp->info);
		temp = temp->next;
	}

}

//stergereLista

void stergeLista(Nod* lista) {
	Nod* temp = lista;
	while (temp->next) {
		delete[] temp->info.nume;
		temp = temp->next;
	}
	delete temp;
	delete lista;
}

//void main() {
//
//	//declare lista goala
//	Nod* lista = NULL;
//	lista = inserareNodLaSfarsit(lista);
//	lista = inserareNodLaSfarsit(lista);
//	lista = inserareNodLaSfarsit(lista);
//	traversareLista(lista);
//	stergeLista(lista);
//
//}