#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct scoala
{
	char* nume;
	int nrClase;

};

struct nodCoada
{
	scoala inf;
	nodCoada* next;
};

void put(nodCoada** prim, nodCoada** ultim, scoala s) {
	nodCoada* nou = new nodCoada;
	nou->inf.nume = new char[strlen(s.nume) + 1];
	strcpy(nou->inf.nume, s.nume);
	nou->inf.nrClase = s.nrClase;
	nou->next = nullptr;
	if (*prim == nullptr && *ultim == nullptr) {
		*prim = nou;
		*ultim = nou;
	}
	else {
		(*ultim)->next = nou;
		(*ultim) = nou;
	}
}

int get(nodCoada** prim, nodCoada** ultim, scoala* s) {
	if (*ultim != nullptr && *prim != nullptr) {
		nodCoada* temp = *prim;
		*prim = (*prim)->next;
		s->nume = new char[strlen((temp)->inf.nume) + 1];
		strcpy(s->nume, temp->inf.nume);
		s->nrClase = temp->inf.nrClase;
		delete[]temp->inf.nume;
		delete temp;
		return 0;
	}
	else {
		
		if (*prim == nullptr)
			*ultim = nullptr;
		return -1;
		
	}
}

void afisareScoala(scoala s) {
	cout << "Scoala cu numele " << s.nume << " are " << s.nrClase << " clase." << endl;
}


void main() {
	nodCoada* prim = nullptr;
	nodCoada* ultim = nullptr;

	ifstream f;
	f.open("scoli.txt");
	scoala s;
	char buffer[30];
	int nrScoli = 0;
	f >> nrScoli;
	for (int i = 0; i < nrScoli; i++) {
		f >> buffer;
		s.nume = new char[strlen(buffer) + 1];
		strcpy(s.nume, buffer);
		f >> s.nrClase;
		put(&prim, &ultim, s);
		delete[]s.nume;
	}

	f.close();
	scoala s1;

	while (get(&prim, &ultim, &s1) == 0) {
		afisareScoala(s1);
		delete[]s1.nume;
	}


}