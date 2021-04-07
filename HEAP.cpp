#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

struct programareVaccin
{
	int prioritate;
	char* nume;
	char* tipVaccin;
};

struct heap
{
	programareVaccin* vect;
	int nrElemente;
};

void filtrare(heap h, int index) {
	int indexRadacine = index;
	int indexStanga = 2 * index + 1;
	int indexDreapta = 2 * index + 2;
	if (indexStanga<h.nrElemente && h.vect[indexStanga].prioritate>h.vect[indexRadacine].prioritate) {
		indexRadacine = indexStanga;
	}
	if (indexDreapta<h.nrElemente && h.vect[indexDreapta].prioritate>h.vect[indexRadacine].prioritate) {
		indexRadacine = indexDreapta;
	}
	if (index != indexRadacine) {
		programareVaccin aux=h.vect[index];
		h.vect[index] = h.vect[indexRadacine];
		h.vect[indexRadacine] = aux;
		filtrare(h, indexRadacine);
	}
}

heap inserare(heap h, programareVaccin v) {// varianta cu return
	programareVaccin* vectNou = new programareVaccin[h.nrElemente + 1];
	for (int i = 0; i < h.nrElemente; i++) {
		vectNou[i] = h.vect[i];
		vectNou[h.nrElemente] = v;
	}
	delete[] h.vect;
	h.vect = vectNou;
	h.nrElemente++;
	for (int i = (h.nrElemente - 1) / 2; i >= 0; i--) {
		filtrare(h, i);
	}

	return h;
}

heap extragere(heap h, programareVaccin* p) {
	programareVaccin* vectNou = new programareVaccin[h.nrElemente + 1];
	programareVaccin aux = h.vect[0];
	h.vect[0] = h.vect[h.nrElemente - 1];
	h.vect[h.nrElemente - 1] = aux;
	*p = h.vect[h.nrElemente - 1];
	h.nrElemente--;
	for (int i = 0; i < h.nrElemente; i++) {
		vectNou[i] = h.vect[i];
	}
	delete[] h.vect;
	h.vect = vectNou;
	for (int i = (h.nrElemente - 1) / 2; i >= 0; i--) {
		filtrare(h, i);
	}
	return h;
}

void afisare(heap h) {
	for (int i = 0; i < h.nrElemente; i++) {
		cout << "Prioritate " << h.vect[i].prioritate << " Nume: " << h.vect[i].nume << " TipVaccin: " << h.vect[i].tipVaccin << endl;

	}
}

void dezalocare(heap h) {
	for (int i = 0; i < h.nrElemente; i++) {
		delete[]h.vect[i].nume;
		delete[]h.vect[i].tipVaccin;
	}

	delete[]h.vect;
}

void main() {

	heap h;
	char buffer[30];
	ifstream f("fisier2.txt");
	f >> h.nrElemente;
	h.vect = new programareVaccin[h.nrElemente];
	for (int i = 0; i < h.nrElemente; i++) {
		f >> h.vect[i].prioritate;
		f >> buffer;
		h.vect[i].nume = new char[strlen(buffer) + 1];
		strcpy(h.vect[i].nume, buffer);
		f >> buffer;
		h.vect[i].tipVaccin = new char[strlen(buffer) + 1];
		strcpy(h.vect[i].tipVaccin, buffer);
		
	}
	for (int i = (h.nrElemente - 1) / 2; i >= 0; i--) {
		filtrare(h, i);
	}
	afisare(h);
	programareVaccin p;
	cout << "Introduceti programarea: ";
	cin >> p.prioritate;
	cout << "Nume";
	cin >> buffer;
	p.nume = new char[strlen(buffer) + 1];
	strcpy(p.nume,buffer);
	cout << "TipVaccin";
	cin >> buffer;
	p.tipVaccin = new char[strlen(buffer) + 1];
	strcpy(p.tipVaccin, buffer);
	h=inserare(h, p);
	afisare(h);
	dezalocare(h);
	f.close();

}