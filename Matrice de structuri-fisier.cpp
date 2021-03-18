#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

struct Muzeu
{
	char* nume;
	float pretBilet;
	int numarVizitatoriZi;
};

Muzeu creareMuzeu() {
	Muzeu muzeu;
	cout << "Dati nume muzeu: ";
	char buffer[20];
	cin >> buffer;
	muzeu.nume = new char[strlen(buffer) + 1];
	strcpy(muzeu.nume, buffer);
	cout << "Dati pret bilet: " << endl;
	cin >> muzeu.pretBilet;
	cout << "Dati numar de vizitatori zilnici: " << endl;
	cin >> muzeu.numarVizitatoriZi;
	return muzeu;

}

void afisareMuzeu(Muzeu muzeu) {
	cout << "Muzeul are numele: " << muzeu.nume << " cu un pret al biletului de :" << muzeu.pretBilet << " lei" << " si are un numar de vizitatori zilnici de " <<
		muzeu.numarVizitatoriZi << endl;
}

void modificareMuzeu(Muzeu* muzeu) {
	if (muzeu->nume != nullptr) {
		delete[]muzeu->nume;
		cout << "Dati nume muzeu: " << endl;
		char buffer[20];
		cin >> buffer;
		muzeu->nume = new char[strlen(buffer) + 1];
		strcpy(muzeu->nume, buffer);
	}
	else {
		cout << "Dati nume muzeu: " << endl;
		char buffer[20];
		cin >> buffer;
		muzeu->nume = new char[strlen(buffer) + 1];
		strcpy(muzeu->nume, buffer);
	}
	cout << "Dati pret bilet: " << endl;
	cin >> muzeu->pretBilet;
	cout << "Dati numar de vizitatori zilnici: " << endl;
	cin >> muzeu->numarVizitatoriZi;
}

void afisareVector(Muzeu* muzee, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		afisareMuzeu(muzee[i]);
	}
}

Muzeu** citireMatrice(int* n, int* m) {
	cout << "Nr de linii: ";
	cin >> *n;
	cout << "Dati numarul de coloane: ";
	cin >> *m;
	Muzeu** matrice;
	//alocare spatiu matrice
	matrice = new Muzeu * [*n];
	for (int i = 0; i < *n; i++) {
		matrice[i] = new Muzeu[*m];
	}
	//creare muzee in matrice
	for (int i = 0; i < *n; i++) {

		for (int j = 0; j < *m; j++) {
			matrice[i][j] = creareMuzeu();
		}
	}

	return matrice;
}

void afisareMatrice(Muzeu** matrice, int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			afisareMuzeu(matrice[i][j]);
		}
		cout << "\n";
	}

}

//void main() {

	/*Muzeu muzeu = creare();
	afisareMuzeu(muzeu);
	modificareMuzeu(&muzeu);
	afisareMuzeu(muzeu);
	delete[]muzeu.nume;*/

	//vector alocat static de muzee

	//int n=3;
	///*cout << "Dati numarul de muzee din vector: " << endl;
	//cin >> n;*/
	//Muzeu vector[3];
	//for (int i = 0; i < 2; i++) {
	//	vector[i] = creareMuzeu();
	//}

	//afisareVector(vector, 2);

	//for (int i = 0; i < 2; i++) {
	//	modificareMuzeu(&vector[i]);
	//}
	//for (int i = 0; i < 2; i++) {
	//	delete[]vector[i].nume;
	//}

	//matrice alocata dinamic de muzee
	//int n;
	//cout << "Dati numarul de muzee din vector: " << endl;
	//cin >> n;
	//Muzeu* vectorDinamic = new Muzeu[n];
	//for (int i = 0; i < n; i++) {
	//	vectorDinamic[i] = creareMuzeu();
	//}

	//afisareVector(vectorDinamic, 2);

	//for (int i = 0; i < 2; i++) {
	//	modificareMuzeu(&vectorDinamic[i]);
	//}

	//afisareVector(vectorDinamic, 2);
	//for (int i = 0; i < 2; i++) {
	//	delete[]vectorDinamic[i].nume;
	//}

	//delete[]vectorDinamic;

	//matrice de muzee

//	Muzeu** matrice;
//	int nrLinii;
//	int nrColoane;//nr de elemete de tip muzeu din fiecare vector
//
//	matrice = citireMatrice(&nrLinii, &nrColoane);
//	afisareMatrice(matrice, nrLinii, nrColoane);
//
//	for (int i = 0; i < nrLinii; i++) {
//		for (int j = 0; j < nrColoane; j++) {
//			delete[]matrice[i][j].nume;
//		}
//	}
//
//	for (int i = 0; i < nrLinii; i++) {
//		delete[] matrice[i];
//	}
//
//	delete[]matrice;
//

	/*fstream fisier;
	Muzeu* vector;
	fisier.open("text.txt",ios::in);
	int n;
	fisier >> n;
	vector = new Muzeu[n];
	for (int i = 0; i < n; i++) {
		char buffer[30];
		fisier >> buffer;
		vector[i].nume = new char[strlen(buffer) + 1];
		strcpy(vector[i].nume, buffer);
		fisier >> vector[i].pretBilet;
		fisier >> vector[i].numarVizitatoriZi;
	}

	fisier.close();

	afisareVector(vector, n);*/

		
	
//}