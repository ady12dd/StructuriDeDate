#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct apartament
{
	int nrCamere;
	char* tipApartament;
	float pret;
};

struct nodStiva
{
	apartament apartament;
	nodStiva* next;
};

//functis push returneaza lista

nodStiva* push(nodStiva* varf, apartament apartament) {
	nodStiva* nou = new nodStiva;
	nou->apartament.nrCamere = apartament.nrCamere;
	nou->apartament.pret = apartament.pret;
	nou->apartament.tipApartament = new char[strlen(apartament.tipApartament) + 1];
	strcpy(nou->apartament.tipApartament, apartament.tipApartament);
	nou->next = nullptr;
	if (varf != nullptr) {
		nou->next = varf;
		varf = nou;
		return varf;
	}
	else {
		
		return nou;
	}

}

int pop(nodStiva** varfa, apartament* a) {
	if (*varfa == nullptr) {
		return -1;
	}
	else {
		(*a).nrCamere = (*varfa)->apartament.nrCamere;
		(*a).pret = (*varfa)->apartament.pret;
		(*a).tipApartament = new char[strlen((*varfa)->apartament.tipApartament) + 1];
		strcpy((*a).tipApartament, (*varfa)->apartament.tipApartament);
		nodStiva* temp = *varfa;
		*varfa = (*varfa)->next;
		delete[]temp->apartament.tipApartament;
		delete temp;
		return 0;
	}
}

void afisareApartament(apartament a) {
	cout << "Apartamentul are " << a.nrCamere << " este de tip " << a.tipApartament << " si costa " << a.pret << " $." << endl;
}

void main() {
	nodStiva* lista=nullptr;

	ifstream f;
	f.open("apartamente.txt");
	char buffer[30];
	apartament test;
	int nrApartamente=0;
	f >> nrApartamente;
	for (int i = 0; i < nrApartamente; i++) {
		f >> test.nrCamere;
		f >> buffer;
		test.tipApartament = new char[strlen(buffer) + 1];
		strcpy(test.tipApartament, buffer);
		f >> test.pret;
		lista = push(lista, test);
		delete[]test.tipApartament;
	}

	f.close();

	apartament test2;

	//afisare stiva
	/*while (pop(&lista, &test2) == 0) {
		afisareApartament(test2);
		delete[]test2.tipApartament;
	}*/

	apartament* vect;
	vect = new apartament[nrApartamente];
	int i = 0;
	while (pop(&lista, &test2) == 0) {
		vect[i].tipApartament = new char[strlen(test2.tipApartament)+1];
		strcpy(vect[i].tipApartament, test2.tipApartament);
		vect[i].nrCamere = test2.nrCamere;
		vect[i].pret = test2.pret;
		i++;
		delete[]test2.tipApartament;
	}

	for (int i = 0; i < nrApartamente; i++) {
		afisareApartament(vect[i]);
	}
}