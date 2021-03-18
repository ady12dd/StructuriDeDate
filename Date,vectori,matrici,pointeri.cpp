#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

//void main() {

	/*int* px=nullptr;
	cout << px << endl;
	int numar = 10;
	px = &numar;
	cout <<"adresa retinuta de px este: "<< px << endl;
	cout << "variabila salvata la adresa retinuta de px este: " << *px<<endl;
	cout << &numar << endl;*/

	/*int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	int n5 = 5;
	int n6 = 6;
	int n7 = 7;
	int n8 = 8;
	int n9 = 9;
	int n10 = 10;

	int* vp[10];
	vp[0] = &n1;
	vp[1] = &n2;
	vp[2] = &n3;
	vp[3] = &n4;
	vp[4] = &n5;
	vp[5] = &n6;
	vp[6] = &n7;
	vp[7] = &n8;
	vp[8] = &n9;
	vp[9] = &n10;

	for (int i= 0; i < 10; i++) {
		cout << vp[i] << "\n";
	}*/

	//masive unidimensionale - vectori - omogeni, contiguu, nr finit de elemente

	//int vector[10] = {1,2,3,4,5,6,7,8,9,10};//static
	//int vector1[5] = { 1,2,3 };//initializate partial

	//int* ni;//dinamic, pointer catre adresa primului element

	////masive bidimensionale

	//int matrice[][2] = { {1,2},{1},{1,4} };//static// linie si coloana, adresa primului element
	////pointer catre vector, rezervare memorie la executie nu la compilare
	//int** matrice1;//dinamic

	//HEAP alocare masivelor
	//alocarea se face la exaecutie nu la compilare
	//posibilitatea schimbarii adresei in timpul executiei, la compilare nu este posibil acest lucru

	//int* n;//dinamic, pointer catre adresa primului element
	////rezervarea memoriei:
	//n = new int[3];
	//for (int i = 0; i < 3; i++) {
	//	n[i] = i;
	//}

	//for (int i = 0; i < 3; i++) {
	//	cout << n[i];
	//}

	//cout << endl;
	////dezalocare n
	////delete[]n;

	//cout << *(n+2);
	
	//int** matrice;
	//matrice = new int*[3];//pointeri catre vectorii de linii ale matricei
	////matrice de 3 linii si 3 coloane
	//for (int i = 0; i < 3; i++) {
	//	*(matrice + i) = new int[3];
	//}









//}