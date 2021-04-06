#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>

using namespace std;

struct carte {
	char* nume;
	int pagini;
	bool isCitita;
};

struct nod
{
	nod* next;
	carte inf;

};

void afisareCarte(carte carte) {
	cout << "Cartea " << carte.nume << " are " << carte.pagini << " pagini";
	if (carte.isCitita == true) {
		cout << " si a fost citita." << endl;
	}
	else {

		cout << " si nu a fost citita." << endl;
	}

}

carte citireCarte() {
	carte c;
	char buffer[20];
	cout << "Dati numele cartii: " << endl;
	cin >> buffer;
	c.nume = new char[strlen(buffer) + 1];
	strcpy(c.nume, buffer);
	cout << "Dati numarul de pagini:" << endl;
	cin >> c.pagini;
	cout << "A fost sau nu citita( 1-da/0-nu )" << endl;
	cin >> c.isCitita;
	return c;
}

nod* inserareInListaLaSfarsit(nod* cap, carte carte) {
	nod* nou = new nod;
	nou->inf.nume = new char[strlen(carte.nume) + 1];
	strcpy(nou->inf.nume, carte.nume);
	nou->inf.pagini = carte.pagini;
	nou->inf.isCitita = carte.isCitita;
	nou->next = nullptr;
	if (cap != nullptr) {
		nod* temp = cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;

		return cap;
	}
	else {

		return nou;
	}
}

nod* inserareLaInceput(nod* cap, carte carte) {
	nod* nou = new nod;
	nou->inf.nume = new char[strlen(carte.nume) + 1];
	strcpy(nou->inf.nume, carte.nume);
	nou->inf.pagini = carte.pagini;
	nou->inf.isCitita = carte.isCitita;
	nou->next = nullptr;
	if (cap != nullptr) {
		nou->next = cap;
		cap = nou;
		return cap;
	}
	else {
		return nou;
	}

}

void dezalocareLista(nod* cap) {

	nod* temp = cap;
	while (temp) {
		delete[]temp->inf.nume;
		temp = temp->next;
	}

	delete temp;
}

void afisareLista(nod* cap) {
	nod* temp = cap;

	while (temp) {
		afisareCarte(temp->inf);
		temp = temp->next;
	}

}

void stergereNod(nod* lista, const char* numeCarte) {
	nod* temp = lista;
	if (strcmp(temp->inf.nume, numeCarte) == 0) {
		lista = temp->next;
		delete[]temp->inf.nume;
		delete temp;
	}
	else {
		while (temp) {
			if (strcmp(temp->next->inf.nume, numeCarte) == 0) {
			
					nod* temp2 = temp->next;
					temp->next = temp->next->next;
					delete[]temp2->inf.nume;
					delete temp2;
			}

			temp = temp->next;
		}
	}
}



void main() {

	carte carte = citireCarte();
	//afisareCarte(carte);

	nod* lista=nullptr;
	lista=inserareLaInceput(lista, carte);
	lista= inserareLaInceput(lista, citireCarte());
	lista= inserareLaInceput(lista, citireCarte());
	afisareLista(lista);
	stergereNod(lista, "istorie");
	afisareLista(lista);
	dezalocareLista(lista);



}