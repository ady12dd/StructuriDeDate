#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct bicicleta
{
	int cod;
	float pret;
	char* brand;

};

struct nodLS
{
	bicicleta inf;
	nodLS* next;

};

struct hashT
{
	nodLS** vect;
	int size;
};

int functieHash(int pret, hashT table) {
	return pret % table.size;
}

int inserare(hashT table, bicicleta b) {
	if (table.vect != nullptr) {
		int poz = functieHash(b.pret,table);
		nodLS* nou = new nodLS;
		nou->inf.cod = b.cod;
		nou->inf.pret = b.pret;
		nou->inf.brand = new char[strlen(b.brand) + 1];
		strcpy(nou->inf.brand, b.brand);
		nou->next = nullptr;
		if (table.vect[poz] == nullptr) {
			table.vect[poz] = nou;
		}
		else {
			nodLS* temp = table.vect[poz];
			while (temp->next!=nullptr) {
				temp = temp->next;
			}
			temp->next = nou;
		}
		return poz;
	}
	else {
		return -1;
	}
}

void traversareLS(nodLS* cap) {
	nodLS* temp = cap;
	while (temp) {
		cout << "Bicicleta are codul : " << temp->inf.cod << " cu pretul de : " << temp->inf.pret << " si este bradul: " << temp->inf.brand << endl;
		temp = temp->next;
	}
}

void traversareTabela(hashT table) {
	for (int i = 0; i < table.size; i++) {
		if (table.vect[i]) {
			cout << "Pozitia: " << i << endl;
			traversareLS(table.vect[i]);
		}
		else {
			cout << " pe pozitia: " << i << " nu sunt elemente" << endl;
		}
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

void dezalocareHastTable(hashT table) {
	for (int i = 0; i < table.size; i++) {
		if (table.vect[i] != nullptr) {
			dezalocareLS(table.vect[i]);
		}
	}
	delete[]table.vect;
}

void main() {
	int n = 0;
	ifstream file("fisierBiciclete.txt");
	char buffer[20];
	hashT table;
	table.size = 10;
	table.vect = new nodLS * [table.size];
	bicicleta b;
	file >> n;
	for (int i = 0; i < n; i++) {
		table.vect[i] = nullptr;
	}

	for (int i = 0; i < n; i++) {
		file >> b.cod;
		file >> b.pret;
		file >> buffer;
		b.brand = new char[strlen(buffer) + 1];
		strcpy(b.brand, buffer);
		inserare(table, b);
		delete[]b.brand;
	}
	file.close();

	traversareTabela(table);
	dezalocareHastTable(table);


}