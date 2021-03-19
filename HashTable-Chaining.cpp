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

int funsctieHash2(char cheie[20], hashT tabela) {
	return cheie[0] % tabela.size;
}

int inserare(hashT tabela, student s) {
	//primim tabela pe care lucram (ca la lista simpla cand primeam capul0 si informatia utila(studentul)
	int pozitie;
	if (tabela.vect != nullptr) {
		pozitie = funsctieHash2(s.nume, tabela);
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
				int contor = 1;
				while (temp) {
					cout << contor<<"."<<" Cod: " << temp->inf.cod << " cu numele: " << temp->inf.nume << " cu media: " << temp->inf.medie<<endl;
					contor++;
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

//stergerea este o combinatie de inserare si dezalocare

void stergeNod(nodLS* nod) {
	
	delete[] nod->inf.nume;
	delete nod;
}

int stergere(hashT tabela, char nume[20])
{
	int pozitie;
	if (tabela.vect != NULL)
	{
		pozitie = funsctieHash2(nume, tabela);
		if (tabela.vect[pozitie] == NULL)
			return -1;
		else
		{
			if (strcmp(tabela.vect[pozitie]->inf.nume, nume)!=0)
			{
				if (tabela.vect[pozitie]->next == NULL)
				{
					//nodLS* temp = tabela.vect[pozitie];
					stergeNod(tabela.vect[pozitie]);
					tabela.vect[pozitie] = NULL;
				}
				else
				{
					nodLS* temp = tabela.vect[pozitie];
					tabela.vect[pozitie] = temp->next;
					free(temp->inf.nume);
					free(temp);
				}
			}
			else
			{
				nodLS* temp = tabela.vect[pozitie];
				while (temp->next != NULL && strcmp(temp->next->inf.nume, nume)!=0)
					temp = temp->next;
					nodLS* p = temp->next;
				if (p->next != NULL)
				{
					temp->next = p->next;
					free(p->inf.nume);
					free(p);
				}
				else
				{
					temp->next = NULL;
					free(p->inf.nume);
					free(p);
				}
			}
		}
	}
	return pozitie;
}



void main() {

	hashT tabela;
	tabela.size = 101;
	tabela.vect = new nodLS*[tabela.size];
	for (int i = 0; i < tabela.size; i++) {
		tabela.vect[i] = nullptr;
	}

	int n;
	cout << "Introduceti numarul de student: ";
	cin >> n;
	student s;
	char buffer[20];//pt nume student
	for (int i = 0; i < n; i++) {
		cout << "Dati codul studentului: ";
		cin >> s.cod;
		cout << "dati numele studentului: ";
		cin>>buffer;
		s.nume = new char[strlen(buffer) + 1];
		strcpy(s.nume, buffer);
		cout << "Dati media studentului:";
		cin >> s.medie;
		inserare(tabela, s);
	}
	char buffer2[20];
	cout << "Nume de sters: " << endl;
	cin >> buffer2;
	cout << "---------------------Afisare tabela inainte de stergere----------------------" << endl<<endl;
	traversareHashTable(tabela);
	stergere(tabela, buffer2);
	cout << "---------------------Afisare tabela dupa stergere--------------------------- " << endl<<endl;
	traversareHashTable(tabela);
	
	dezalocareHastT(tabela);
}