#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>// pentru strcpy
#include<fstream>

using namespace std;

struct carte //pas1 - info utila
 {
	int cod;
	char* titlu;
	float pret;
};

struct nodStiva
{
	carte inf;
	nodStiva* next;//pointer de lagatura pentru a referi pointer urmator
};

nodStiva* push(nodStiva* varf, carte c) {//varf echivalent cu cap //inserare la inceput in lista simpla
	//initializare nod nou care trebuie introdus in stiva
	nodStiva* nou = new nodStiva;
	nou->inf.cod = c.cod;
	nou->inf.pret = c.pret;
	nou->inf.titlu = new char[strlen(c.titlu) + 1];
	strcpy(nou->inf.titlu, c.titlu);
	nou->next = nullptr;
	if (varf == nullptr) {
		varf = nou;
	}
	else {
		nou->next = varf;
		varf = nou;//ultimul nod inserat in strucutra
	}
	return varf;
}





void main() {

}