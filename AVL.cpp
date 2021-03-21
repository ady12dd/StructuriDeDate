#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct produs
{
	int cod;
	char* denumire;
	float pret;
};

struct nod
{
	produs inf;
	nod* left;
	nod* right;

};

//facem 2 functii

nod* creareNod(produs p, nod* st, nod* dr) {
	nod* nou = new nod;
	nou->inf.cod = p.cod;
	nou->inf.denumire = new char[strlen(p.denumire) + 1];
	strcpy(nou->inf.denumire, p.denumire);
	nou->inf.pret = p.pret;
	nou->left = st;
	nou->right = dr;
	return nou;
}

nod* inserare(nod* rad, produs p) {//nod* rad este capul arborelui
	nod* temp = rad;
	if (rad == nullptr)
	{
		temp = creareNod(p, nullptr, nullptr);
		return temp;
	}
	else 
	{
		while (true) 
		{
			if (p.cod < temp->inf.cod) 
			{
				if (temp->left != nullptr) {
					temp = temp->left;
				}
				else
				{
					temp->left = creareNod(p, nullptr, nullptr);
					return rad;
				}
			}
			else {

				if (p.cod > temp->inf.cod)
				{
					if (temp->right != nullptr) {
						temp = temp->right;
					}
					else
					{
						temp->right = creareNod(p, nullptr, nullptr);
						return rad;
					}
				}
				return rad;
			}

		}
	}
}

void traversareInOrdine(nod* rad) {//SRD
	if(rad!=nullptr){
		traversareInOrdine(rad->left);
		cout << "Cod: " << rad->inf.cod << "Denumire: " << rad->inf.denumire << " Pret: " << rad->inf.pret << endl;
		traversareInOrdine(rad->right);
		
	}
}

void dezalocare(nod* rad) {
	if (rad != nullptr) {
		nod* stanga = rad->left;
		nod* dreapta = rad->right;
		delete[]rad->inf.denumire;
		delete rad;
		dezalocare(stanga);
		dezalocare(dreapta);
	}
}

nod* cautare(nod* rad, int cheie) {
	if (rad != nullptr) {
		if (cheie == rad->inf.cod) {
			return rad;
		}
		else {

			if (cheie < rad->inf.cod) {
				return cautare(rad->left, cheie);
			}
			else {
				return cautare(rad->right, cheie);
			}
		}
	}
	
}

void conversieArboreVector(nod* rad, produs* vect, int* nr) {
	if (rad != nullptr) {
		vect[*nr].cod = rad->inf.cod;
		vect[*nr].denumire = new char[strlen(rad->inf.denumire) + 1];
		strcpy(vect[*nr].denumire, rad->inf.denumire);
		vect[*nr].pret = rad->inf.pret;
		(*nr)++;

		nod* stanga = rad->left;
		nod* dreapta = rad->right;
		delete[]rad->inf.denumire;
		delete rad;
		conversieArboreVector(stanga,vect,nr);
		conversieArboreVector(dreapta,vect,nr);
		
	}
}

void main() {
	int n;
	nod* rad = nullptr;
	char buffer[20];
	produs p;
	ifstream fis;
	fis.open("Text1.txt");
	fis >> n;
	for (int i = 0; i < n; i++) {
		fis >> p.cod;
		fis >> buffer;
		p.denumire = new char[strlen(buffer) + 1];
		strcpy(p.denumire, buffer);
		fis >> p.pret;

		rad = inserare(rad, p);
		delete[]p.denumire;
	}
	fis.close();
	traversareInOrdine(rad);

	produs* vect = new produs[n];
	int nr = 0;
	conversieArboreVector(rad, vect, &nr);
	for (int i = 0; i < nr; i++) {
		cout << "Cod: " << vect[i].cod << "Denumire: " << vect[i].denumire << " Pret: " << vect[i].pret << endl;
	}

	for (int i = 0; i < nr; i++) {
		delete[]vect[i].denumire;
	}
	delete[]vect;

	//dezalocare(rad);


}

//--------------Arborele nostru--------------
//					55
//		33						66
//				44						77
	