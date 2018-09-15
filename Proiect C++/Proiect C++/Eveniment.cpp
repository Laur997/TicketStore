#include "stdafx.h"
#include "Eveniment.h"
#include <string>
#include <iostream>
#include <string>
using namespace std;

void  Eveniment::setNume(string n)
{
	this->nume = n;
}
string Eveniment::getNume(void) { return nume; }
void Eveniment::setOrganizator(string o) {
	this->organizator = o;
}
string Eveniment::getOrganizator(void) { return organizator; }
void Eveniment::setPret(int p) {
	this->pretBilet = p;
}
int Eveniment::getPret(void) { return pretBilet; }
void Eveniment::initializareLocuri(void) { 
	int k1, k2;
	ofstream out;  //Adaugare folder cu locurile salii
	out.open(nume + ".txt");
	for (k1 = 1; k1 <= 9; k1++) {
		for (k2 = 1; k2 <= 13; k2++) {
			out << 1 << " ";
		}
	}
	out.close();

	// Adaugare folder cu castiguri curente
	ofstream outc;
	outc.open(nume + "-incasari.txt");
	outc << 0;
	outc.close();

}


void Eveniment::setZi(int zi) { this->zi = zi; }
int Eveniment::getZi(void) { return zi; }
void Eveniment::setLuna(int luna) { this->luna = luna; }
int Eveniment::getLuna(void) { return luna; }
void Eveniment::setAn(int an) { this->an = an; }
int Eveniment::getAn(void) { return an; }
void Eveniment::setOra(int ora) { this->ora = ora; }
int Eveniment::getOra(void) { return ora; }
void Eveniment::setMinut(int minut) { this->minut = minut; }
int Eveniment::getMinut(void) { return minut; }
void Eveniment::OcupareLoc(void) {
	int k1, k2,sum;
	char opt;
	ifstream f(nume + ".txt");
	while (!f.eof()) {
		for (k1 = 1; k1 < 9; k1++) {
			for (k2 = 1; k2 < 13; k2++) {
				f >> loc[k1][k2];   //Introducere elemente in matrice

			}
		}
	}
	system("cls");
	for (k1 = 1; k1 < 9; k1++) {   //Afisare pe ecran
		for (k2 = 1; k2 < 13; k2++) {
			if (loc[k1][k2] == 1) {
				cout << "L" << k1 << "-" << k2 << " "; //loc liber
			}
			else {
				cout << "L-- "; //loc ocupat
			}

		}

		cout << endl;
	}
	f.close();
	cout << "Doriti sa continuati? " << endl;
	cout << "\na. Da" << endl;
	cout << "b. Nu" << endl;
	cout << "\n Introduceti optiunea : ";
	cin >> opt;
	if (opt == 'b') { exit(0); }
	cout << "Introduceti numarul randului : ";
	cin >> k1;
	cout << "\n Introduceti numarul locului : ";
	cin >> k2;
	loc[k1][k2] = 9;
	ofstream out(nume + ".txt");
	for (k1 = 1; k1 < 9; k1++) {
		for (k2 = 1; k2 < 13; k2++) {
			out << loc[k1][k2] << " ";
		}
	}
	out.close();
	ifstream insum(nume + "-incasari.txt");
	insum >> sum;
	sum = sum + getPret();
	insum.close();
	ofstream outsum(nume + "-incasari.txt");
	outsum << sum;
	outsum.close();
}
int Eveniment::getSuma(void)
{
	int sum;
	ifstream insum(nume + "-incasari.txt");
	insum >> sum;
	return sum;
}