#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include<fstream>
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
	nodls* next;
};

nodls* inserare(nodls* cap, produs p)
{

	nodls* nou = new nodls;
	nou->inf.cod = p.cod;
	nou->inf.denumire = new char[strlen(p.denumire) + 1];
	strcpy(nou->inf.denumire, p.denumire);
	nou->inf.pret = p.pret;
	nou->inf.cantitate = p.cantitate;

	nou->next = NULL;

	if (cap == NULL)
	{
		cap = nou;
		nou->next = NULL;
	}
	else
	{
		nodls* temp = cap;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = nou;
		nou->next = NULL;
	}
	return cap;
}

void traversare(nodls* cap)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		cout << "Cod=" << temp->inf.cod << " Denumire=" << temp->inf.denumire <<
			" Pret=" << temp->inf.pret << " Cantitate=" << temp->inf.cantitate << endl;
		temp = temp->next;
	}
	
} 

void dezalocare(nodls* cap)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		nodls* temp2 = temp->next;
		delete[] temp->inf.denumire;
		delete temp;
		temp = temp2;
	}
	
}

void main()
{
	int n;
	/*cout << "Nr. produse=";
	cin >> n;*/
	ifstream file;
	file.open("fisier.txt");
	file >> n;

	nodls* cap = NULL, * coada = NULL;
	produs p;
	char buffer[20];

	for (int i = 0; i < n; i++)
	{

		file >> p.cod;
		file >> buffer;
		p.denumire = new char[strlen(buffer) + 1];
		strcpy(p.denumire, buffer);
		file >> p.pret;
		file >> p.cantitate;

		cap = inserare(cap, p);
	}
	file.close();
	traversare(cap);

	dezalocare(cap);
}