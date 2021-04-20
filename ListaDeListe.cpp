#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct bicicleta
{
	int cod;
	char* brand;
	float pret;
};

struct nodLS
{
	bicicleta inf;
	nodLS* next;
};

struct nodLP
{
	nodLS* inf;
	nodLP* next;
};

nodLS* inserareLS(nodLS* cap, bicicleta b) {
	nodLS* nou = new nodLS;
	nou->inf.cod = b.cod;
	nou->inf.pret = b.pret;
	nou->inf.brand = new char[strlen(b.brand) + 1];
	strcpy(nou->inf.brand, b.brand);
	nou->next = nullptr;
	if (cap == nullptr) {
		return nou;
	}
	else {
		nodLS* temp = cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
		return cap;
	}
}

nodLP* inserareLP(nodLP* capLP, nodLS* capLS) {
	nodLP* nou = new nodLP;
	nou->inf = capLS;
	nou->next = nullptr;
	if (capLP == nullptr) {
		return nou;
	}
	else {
		nodLP* temp = capLP;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
		return capLP;
	}
}

void traversaLS(nodLS* cap) {
	nodLS* temp = cap;
	while (temp) {
		cout << "Cod: " << temp->inf.cod << " Brand: " << temp->inf.brand << " pret: " << temp->inf.pret <<" RON."<< endl;
		temp = temp->next;
	}
}

void traversareLP(nodLP* capLP) {
	nodLP* temp = capLP;
	while (temp) {
		traversaLS(capLP->inf);
		temp = temp->next;
	}
}

void dezalocareLS(nodLS* cap) {
	nodLS* temp = cap;
	while (temp) {
		nodLS* temp2 = temp->next;
		delete[]temp->inf.brand;
		delete temp;
		temp = temp2;

	}
}

void dezalocareLP(nodLP* capLP) {
	nodLP* temp = capLP;
	while (temp) {
		nodLP* temp2 = temp->next;
		dezalocareLS(temp->inf);
		delete temp;
		temp = temp2;
	}
}

//functie care sa afiseze suma tuturor produselot din lista

float pretTotal(nodLP* capLP) {
	float pret = 0;
	nodLP* temp = capLP;
	while (temp) {
		nodLS* tempLS = temp->inf;
		while (tempLS) {
			pret += tempLS->inf.pret;
			tempLS = tempLS->next;
		}
		temp = temp->next;
	}

	return pret;
}

void main() {
	int n;
	nodLS* lista1 = nullptr;
	nodLS* lista2 = nullptr;
	nodLS* lista3 = nullptr;
	bicicleta b;
	char buffer[30];
	ifstream fisier("fisierBiciclete.txt");
	fisier >> n;
	for (int i = 0; i < 4; i++) {
		fisier >> b.cod;
		fisier >> b.pret;
		fisier >> buffer;
		b.brand = new char[strlen(buffer) + 1];
		strcpy(b.brand, buffer);
		lista1 = inserareLS(lista1, b);
		delete[]b.brand;

	}
	for (int i = 4; i < 7; i++) {
		fisier >> b.cod;
		fisier >> b.pret;
		fisier >> buffer;
		b.brand = new char[strlen(buffer) + 1];
		strcpy(b.brand, buffer);
		lista2 = inserareLS(lista2, b);
		delete[]b.brand;
	}

	for (int i = 7; i < n; i++) {
		fisier >> b.cod;
		fisier >> b.pret;
		fisier >> buffer;
		b.brand = new char[strlen(buffer) + 1];
		strcpy(b.brand, buffer);
		lista3 = inserareLS(lista3, b);
		delete[]b.brand;
	}

	fisier.close();

	nodLP* listaListe = nullptr;

	listaListe = inserareLP(listaListe, lista1);
	listaListe = inserareLP(listaListe, lista2);
	listaListe = inserareLP(listaListe, lista3);
	cout << "------------lista1-----------------"<<endl;
	traversaLS(lista1);
	cout << "------------lista2-----------------"<<endl;
	traversaLS(lista2);
	cout << "------------lista3-----------------"<<endl;
	traversaLS(lista3);
	cout << "------------listaMare-----------------" << endl;
	traversareLP(listaListe);

	float pretTotalCalculat = pretTotal(listaListe);
	cout << """""""""" << endl;
	cout << "Pretul tuturor bicicletelor: " << pretTotalCalculat << endl;

	
	dezalocareLP(listaListe);
}