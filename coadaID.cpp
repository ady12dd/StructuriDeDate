#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

struct masina
{
	int cod;
	char* marca;
	float pret;
};

struct nodCoada
{
	masina inf;
	nodCoada* next;
};

void put(nodCoada** prim, nodCoada** ultim, masina m) {
	nodCoada* nou = new nodCoada;
	nou->inf.cod = m.cod;
	nou->inf.marca = new char[strlen(m.marca)+1];
	strcpy(nou->inf.marca, m.marca);
	nou->inf.pret = m.pret;
	nou->next = nullptr;
	if (*prim == nullptr && *ultim==nullptr) {
		*prim = nou;
		*ultim = nou;
	}
	else {
	
		(*ultim)->next = nou;
		*ultim = nou;
	}

}

int get(nodCoada** prim, nodCoada** ultim, masina* m) {
	if (*prim != nullptr && *ultim != nullptr) {
		(*m).cod = (*prim)->inf.cod;
		(*m).marca = new char[strlen((*prim)->inf.marca) + 1];
		strcpy((*m).marca, (*prim)->inf.marca);
		(*m).pret = (*prim)->inf.pret;
		nodCoada* temp = *prim;
		*prim = (*prim)->next;
		delete[]temp->inf.marca;
		delete temp;
		return 0;
	}
	else if(*prim==nullptr) {
		*ultim = nullptr;// il dezalocam explicit
		return -1;
	}
}

void traversare(nodCoada* prim) {
	nodCoada* temp = prim;
	while (temp) {
		cout << "Masina cu codul : " << temp->inf.cod << " are marca " << temp->inf.marca << " si pretul de " << temp->inf.pret << " lei" << endl;
		temp = temp->next;
	}
}
void main()
{
	int n;
	cout << "Dati numarul de masini: " << endl;
	cin >> n;
	nodCoada* prim = nullptr, * ultim = nullptr;
	char buffer[30];
	masina m;
	for (int i = 0; i < n; i++) {
		cout << "Cod =" << endl;
		cin >> m.cod;
		cout << "Marca: " << endl;
		cin.getline(buffer, 29, '.');
		m.marca = new char[strlen(buffer) + 1];
		strcpy(m.marca, buffer);
		cout << "Pret= " << endl;
		cin >> m.pret;
		put(&prim, &ultim, m);
		delete[]m.marca;
	}

	traversare(prim);
	while (get(&prim, &ultim, &m) == 0) {
		delete[]m.marca;
	}
}
