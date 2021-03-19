#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct student {//informatia utila
	int cod;
	char* nume;
	float medie;
};

struct nodLS//lista simpla pentru elementele din tabel si coliziunile
{
	student inf;
	nodLS* next;
};

struct hashT
{
	nodLS** vect;//vector dinamic de pointeri la noduri - adresele primului nod din fiecare sublista
	int size;
};

int functieHash(int cheie, hashT tabela) {
	return cheie % tabela.size;//aplicam modulo dau putem returna ce vrem noi
	//de preferat o functie care sa genereze cat mai putine coliziuni( coliziune= pt f(x1)=y sa nu existe f(x2)=y

}

int inserare(hashT tabela, student s) {
	//primim tabela pe care lucram (ca la lista simpla cand primeam capul0 si informatia utila(studentul)
	int pozitie;
	if (tabela.vect != nullptr) {
		pozitie = functieHash(s.cod, tabela);
		//acum e partea de la lista ( inserarea in lista simpla)
		nodLS* nou = new nodLS;
		nou->inf.cod = s.cod;
		nou->inf.nume = new char[strlen(s.nume) + 1];
		strcpy(nou->inf.nume, s.nume);
		nou->inf.medie = s.medie;
		nou->next = nullptr;
		//unde bagam nodul
		if (tabela.vect[pozitie] == nullptr) {
			tabela.vect[pozitie] = nou;
		}
		else {
			//suntem in situatie de coliziune
			nodLS* temp = tabela.vect[pozitie];
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = nou;
		}
	}
	return pozitie;
}

void traversareHashTable(hashT tabela) {

	if (tabela.vect != nullptr) {
	
		for (int i = 0; i < tabela.size; i++) {
			if (tabela.vect[i] != nullptr) {
				//afisare ca o lista
				cout << "Pozitie " << i << endl;
				//pot face o fucntie separata sau traversam aici
				nodLS* temp = tabela.vect[i];
				while (temp) {
					cout << "Cod: " << temp->inf.cod << " cu numele: " << temp->inf.nume << " cu media: " << temp->inf.medie<<endl;
					temp = temp->next;
				}
			}
		}
	}
}

void dezalocareHastT(hashT tabela) {

	if (tabela.vect != nullptr) {
	
		for (int i = 0; i < tabela.size; i++) {
		
			if (tabela.vect[i] != nullptr) {
				//dezalocare lista - putem folosi si functia de dezalocare de la lista simpla
				nodLS* temp = tabela.vect[i];
				while (temp) {
					
					nodLS* temp2 = temp->next;
					delete[]temp->inf.nume;
					delete[]temp;//stergem si pointerul next
					temp = temp2;// apoi in aducem pe pozitia urmatoare dupa ce am sters
				}
			}
		}
		delete[]tabela.vect;
	}
}

void main() {

}