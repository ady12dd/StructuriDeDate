#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

struct Masina {
	int nrMasina;
	char* denumire;
	bool isElectric;
};

struct nod {
	Masina info;
	nod* next;
	nod* prev;
};

nod* inserareInceput(Masina m, nod* capLista, nod* coadaLista) {
	nod* nou = new nod;
	nou->info.denumire = new char[strlen(m.denumire) + 1];
	strcpy(nou->info.denumire, m.denumire);
	nou->info.nrMasina = m.nrMasina;
	nou->info.isElectric = m.isElectric;
	nou->next = nullptr;
	nou->prev = nullptr;
	if (capLista != nullptr)
	{
		nou->next = capLista;
		capLista->prev = nou;
		return nou;
	}
	coadaLista = nou;
	capLista = nou;
	return nou;


}

void afisareMasina(Masina m) {
	cout << "Masina cu denumirea " << m.denumire << " are numarul " << m.nrMasina;
	if (m.isElectric == 1) {
		cout << "si este electrica" << endl;
	}
	else {
		cout << " si nu este electrica" << endl;
	}
}

void traversareLista(nod* capLista) {
	nod* temp = capLista;
	while (temp)
	{
		afisareMasina(temp->info);
		temp = temp->next;
	}
}
void traversareInversa(nod* capLista) {
	nod* temp = capLista;
	while (temp->next)
	{
		temp = temp->next;
	}
	nod* temp2 = temp;
	while (temp2) {
		afisareMasina(temp2->info);
		temp2 = temp2->prev;
	}
}

void dezalocare(nod* lista) {
	nod* temp = lista;
	while (temp) {
		nod* temp2 = temp->next;
		delete[]temp->info.denumire;
		delete[]temp;
		temp = temp2;
	}
	
}

Masina* conversieListaVector(nod* lista, int* nrMasini) {
	Masina* vectorMasini = new Masina[*nrMasini];
	nod* temp = lista;
	int i = 0;
	while (temp) {
		vectorMasini[i] = temp->info;
		temp = temp->next;
		i++;
	}
	return vectorMasini;
}


void main() {
	nod* lista = nullptr;
	char buffer[20];
	int nrMasini;
	ifstream f;
	f.open("masini.txt");
	f >> nrMasini;
	Masina m;
	for (int i = 0; i < nrMasini; i++) {

		f >> buffer;
		m.denumire = new char[strlen(buffer) + 1];
		strcpy(m.denumire, buffer);
		f >> m.nrMasina;
		f >> m.isElectric;
		lista = inserareInceput(m, lista, lista);
		delete[]m.denumire;
	}

	traversareLista(lista);
	cout << "-----------------Afisare INVERSA------------------------" << endl;
	traversareInversa(lista);

	Masina* vectorMasini = conversieListaVector(lista, &nrMasini);
	cout << "-----------------Afisare MATRICE------------------------" << endl;
	for (int i = 0; i < nrMasini; i++) {
		afisareMasina(vectorMasini[i]);
	}
}