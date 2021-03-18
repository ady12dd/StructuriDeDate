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
	if (prim == nullptr&&ultim==nullptr) {
		*prim = nou;
		*ultim = nou;
	}
	else {
	
		(*ultim)->next = nou;
		*ultim = nou;
	}

}

void main()
{

}
