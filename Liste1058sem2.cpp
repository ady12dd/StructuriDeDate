#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

struct produs
{
	int cod;
	char* denumire;
	float pret;
	float cantitate;
};

struct nodls
{
	produs inf;
	nodls* next, * prev;
};

nodls* inserare(nodls* cap, nodls** coada, produs p)
{
	nodls* nou = new nodls;
	nou->inf.cod = p.cod;
	nou->inf.denumire = new char[strlen(p.denumire) + 1];
	strcpy(nou->inf.denumire, p.denumire);
	nou->inf.pret = p.pret;
	nou->inf.cantitate = p.cantitate;

	nou->next = NULL;
	nou->prev = NULL;

	if (cap == NULL)
	{
		cap = nou;
		nou->next = cap;
		nou->prev = cap;
		*coada = nou;
	}
	else
	{
		nodls* temp = cap;
		while (temp->next != cap)
			temp = temp->next;
		temp->next = nou;
		nou->prev = temp;
		*coada = nou;
		(*coada)->next = cap;
		cap->prev = *coada;
	}

	return cap;
}

void traversare(nodls* cap)
{
	nodls* temp = cap;
	while (temp->next != cap)
	{
		cout << "Cod=" << temp->inf.cod << " Denumire=" << temp->inf.denumire <<
			" Pret =" << temp->inf.pret << " Cantitate=" << temp->inf.cantitate << endl;
		temp = temp->next;
	}
	cout << "Cod=" << temp->inf.cod << " Denumire=" << temp->inf.denumire <<
		" Pret =" << temp->inf.pret << " Cantitate=" << temp->inf.cantitate << endl;
}

void traversareInvers(nodls* coada)
{
	nodls* temp = coada;
	while (temp->prev != coada)
	{
		cout << "Cod=" << temp->inf.cod << " Denumire=" << temp->inf.denumire <<
			" Pret =" << temp->inf.pret << " Cantitate=" << temp->inf.cantitate << endl;
		temp = temp->prev;
	}
	cout << "Cod=" << temp->inf.cod << " Denumire=" << temp->inf.denumire <<
		" Pret =" << temp->inf.pret << " Cantitate=" << temp->inf.cantitate << endl;
}

void dezalocare(nodls* cap)
{
	nodls* temp = cap;
	while (temp->next != cap)
	{
		nodls* temp2 = temp->next;
		delete[] temp->inf.denumire;
		delete temp;
		temp = temp2;
	}
	delete[] temp->inf.denumire;
	delete temp;
}

void main()
{
	int n;

	ifstream fisier;
	fisier.open("fisier.txt");

	//cout << "Nr. produse=";
	//cin >> n;
	fisier >> n;

	nodls* cap = NULL, * coada = NULL;
	produs p;
	char buffer[20];

	for (int i = 0; i < n; i++)
	{
		//cout << "Cod=";
		//cin >> p.cod;
		fisier >> p.cod;
		//cout << "Denumire=";
		//cin >> buffer;
		fisier >> buffer;
		p.denumire = new char[strlen(buffer) + 1];
		strcpy(p.denumire, buffer);
		//cout << "Pret=";
		//cin >> p.pret;
		fisier >> p.pret;
		//cout << "Cantitate=";
		//cin >> p.cantitate;
		fisier >> p.cantitate;
		cap = inserare(cap, &coada, p);
		delete[] p.denumire;
	}
	fisier.close();

	traversare(cap);
	cout << endl;
	traversareInvers(coada);
	dezalocare(cap);
}