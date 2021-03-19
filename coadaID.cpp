#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct masina
{
	int cod;
	char* marca;
	float pret;
};

struct nodStiva
{
	masina inf;
	nodStiva* next;
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

void traversareStiva(nodStiva* varf) {
	ofstream f;
	f.open("out.txt");
	nodStiva* temp = varf;
	while (temp) {
		f << "Masina cu codul : " << temp->inf.cod << " are marca " << temp->inf.marca << " si pretul de " << temp->inf.pret << " lei" << endl;
		temp = temp->next;
	}

	f.close();
}

int pop(nodStiva** varf, masina* val) {// pentru a actualiza varful(stiva) il dam pointer, val vreau sa returnez cartea pe care o scot
	if (*varf == nullptr) {
		return -1;// inseamna ca nu avem ce extrage
	}
	else {
		//deep copy informatie utila
		(*val).cod = (*varf)->inf.cod;
		(*val).marca = new char[strlen((*varf)->inf.marca) + 1];
		strcpy(val->marca, (*varf)->inf.marca);
		val->pret = (*varf)->inf.pret;
		//dezalocare nod stiva, curent
		nodStiva* temp = *varf;// pastrez adresa varfului curent
		*varf = (*varf)->next;
		delete[]temp->inf.marca;
		delete temp;
		return 0;// s-a extras cu succes
	}
}

nodStiva* push(nodStiva* varf, masina c) {//varf echivalent cu cap //INSERARE LA INCEPUT INTR_O LISTA SIMPLA
	//initializare nod nou care trebuie introdus in stiva
	nodStiva* nou = new nodStiva;
	nou->inf.cod = c.cod;
	nou->inf.pret = c.pret;
	nou->inf.marca = new char[strlen(c.marca) + 1];
	strcpy(nou->inf.marca, c.marca);
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

void ConversieCoadaStiva(nodCoada** prim, nodCoada** ultim, nodStiva** varf) {
	masina val;
	while (get(prim, ultim, &val) == 0) {
		*varf=push(*varf, val);
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
	cout << "---------------Coada----------------" << endl;
	traversare(prim);
	masina val;
	/*while (get(&prim, &ultim, &m) == 0) {
		delete[]m.marca;
	}*/
	cout << "---------------Stiva----------------" << endl;
	nodStiva* varf = nullptr;
	ConversieCoadaStiva(&prim, &ultim, &varf);
	traversareStiva(varf);
	while (pop(&varf, &val) == 0) {
		delete[]val.marca;
	}
}
