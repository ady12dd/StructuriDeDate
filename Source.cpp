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

nodStiva* push(nodStiva* varf, carte c) {//varf echivalent cu cap //INSERARE LA INCEPUT INTR_O LISTA SIMPLA
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

int pop(nodStiva** varf, carte* val) {// pentru a actualiza varful(stiva) il dam pointer, val vreau sa returnez cartea pe care o scot
	if (*varf == nullptr) {
		return -1;// inseamna ca nu avem ce extrage
	}
	else {
		//deep copy informatie utila
		(*val).cod = (*varf)->inf.cod;
		(*val).titlu = new char[strlen((*varf)->inf.titlu) + 1];
		strcpy(val->titlu, (*varf)->inf.titlu);
		val->pret = (*varf)->inf.pret;
		//dezalocare nod stiva, curent
		nodStiva* temp = *varf;// pastrez adresa varfului curent
		*varf = (*varf)->next;
		delete[]temp->inf.titlu;
		delete temp;
		return 0;// s-a extras cu succes
	}
}

//trevaersarea se face ca la lista simpla pentru a putea utiliza stiva in alte operatii
void traversare(nodStiva* stiva) {
	nodStiva* temp = stiva;

	while (temp) {
		cout << "Cartea cu codul : " << temp->inf.cod << " are titlul " << temp->inf.titlu << " si pretul de " << temp->inf.pret << " lei" << endl;
		temp = temp->next;
	}
	
}

void main() {
	nodStiva* varf = nullptr;
	int n;//nr de carti
	cout << "Dati numarul de carti: ";
	cin >> n;
	char buffer[30];
	carte c;
	for (int i = 0; i < n; i++) {
		cout << "Dati codul:";
		cin >> c.cod;
		cout << "Dati titlul cartii:";
		cin.getline(buffer, 30,'.');
		c.titlu = new char[strlen(buffer) + 1];
		strcpy(c.titlu, buffer);
		cout << "Dati pretul cartii: ";
		cin >> c.pret;
		varf = push(varf, c);
		delete[]c.titlu;
	}

	///varf = push(varf, c);
	//varf = push(varf, c1);
	traversare(varf);
	//dezalocare
	carte val;
	while (pop(&varf, &val) == 0);
}