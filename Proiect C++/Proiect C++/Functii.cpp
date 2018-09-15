#include "stdafx.h"
#include "Functii.h"
#include "Eveniment.h"
#include <conio.h>
using namespace std;
void Functii::MeniuEvenimente(void) {
	system("cls");
	char c;
	cout << "\nMeniu Evenimente:" << endl;
	cout << "\na. Afisare evenimente" << endl;
	cout << "\nb. Iesire" << endl;
	cout << "\nNumarul optiunii : ";
	cin >> c;
	switch (c) {
	case 'a': ListareEvenimente();
			  break;

	case 'b': exit(0);
			  break;

	default: cout << "\nNu avem aceasta optiune! Incercati din nou ";
		     MeniuEvenimente();
			 break;
	}
}

void Functii::AdaugareEveniment(void) { // ADAUGAREA UNUI EVENIMENT
	Eveniment e; // Declararea evenimentului e
	string sir1, sir2;
	int m, n, p, q, o, min;
	ofstream out("FisierSala.txt", ios_base::app);
	cout << "\nIntroduceti numele evenimentului( Scrieti numele legat ): ";  // NUME SPECTACOL
	cin >> sir1;
	out << sir1 << " ";
	e.setNume(sir1);
	cout << "\nIntroduceti numele organizatorului : "; // ORGANIZATOR
	cin >> sir2;
	out << sir2 << " ";
	e.setOrganizator(sir2);
	cout << "\nIntroduceti pretul unui bilet : "; // PRET BILET
	cin >> m;
	out << m << " ";
	e.setPret(m);
	cout << "\n Setare data : "; // DATA
	do {
		cout << "\n ziua : ";
		cin >> n;
	} while (n < 1 && n > 31);
	out << n << " ";
	e.setZi(n);
	do {
		cout << "\n luna : ";
		cin >> p;
	} while (p < 1 && p > 12);
	out << p << " ";
	e.setLuna(p);
	do {
		cout << "\n anul : ";
		cin >> q;
	} while (q < 2018 && q > 2999);
	out << q << " ";
	e.setAn(q);
	do {
		cout << "\n ora :  ";
		cin >> o;
	} while (o < 0 && o > 23);
	out << o << " ";
	do {
		cout << "\n minutul :  ";
		cin >> min;
	} while (min < 0 && min > 23);
	out << min << " ";
	out << endl;
	out.close();
	e.initializareLocuri(); // Initializarea locurilor ca libere (elementele din matricea cu locuri vor primi valoarea 0)
	MeniuAdmin();
}
void Functii::ListareEvenimente(void) 
{
	system("cls");
	string sir1, sir2, sir3;
	char x;
	int m, n, p, q, i, j, o, min;
	Eveniment e[21];

	ifstream in("FisierSala.txt");
	for (i = 1; !in.eof(); i++) { // Introducerea fiecarei componente in membrii vectorului
		in >> sir1;
		e[i].setNume(sir1);
		in >> sir2;
		e[i].setOrganizator(sir2);
		in >> m;
		e[i].setPret(m);
		in >> n;
		e[i].setZi(n);
		in >> p;
		e[i].setLuna(p);
		in >> q;
		e[i].setAn(q);
		in >> o;
		e[i].setOra(o);
		in >> min;
		e[i].setMinut(min);
	}
	j = i - 1;
	for (i = 1; i < j; i++) {
		cout << endl;
		cout << i << ".Spectacol: " << e[i].getNume() << "; ";
		cout << "Organizator: " << e[i].getOrganizator() << "; ";
		cout << "pret bilet:" << e[i].getPret() << "; ";
		cout << "Data: "  << e[i].getLuna() << "/" << e[i].getZi()<<"/" << e[i].getAn()<<endl;
		cout << "\n Ora : " << e[i].getOra() << " : " << e[i].getMinut() << endl;
	}
	cout << "\na. Operatii cu evenimente deja existente : " << endl;
	cout << "\nb. Revenire la meniul principal" << endl;
	cout << "\n Introduceti optiunea : ";
	cin >> x;
	switch (x) {
	case 'a': SelectareEveniment();
		break;
	case 'b': Logare();
		      break;
	default: cout << "\nNu avem aceasta optiune!" << endl;;
		     Logare();
		     break;
	}


}
void Functii::SelectareEveniment(void) 
{
	string sir1, sir2, filepath;
	char  y, z;
	int m, n, p, q, o, i, j, min, st;
	Eveniment e[21];

	ifstream in("FisierSala.txt");
	for (i = 1; !in.eof(); i++)
	{ // Introducerea fiecarei componente in membrii vectorului
		in >> sir1;
		e[i].setNume(sir1);
		in >> sir2;
		e[i].setOrganizator(sir2);
		in >> m;
		e[i].setPret(m);
		in >> n;
		e[i].setZi(n);
		in >> p;
		e[i].setLuna(p);
		in >> q;
		e[i].setAn(q);
		in >> o;
		e[i].setOra(o);
		in >> min;
		e[i].setMinut(min);
	}
	j = i - 1;
	in.close();
	cout << "a. Cumparare bilet" << endl;
	cout << "b. Stergere spectacol " << endl;
	cout << "c. Revenire la meniul principal" << endl;
	cout << "Introduceti optiunea : ";
	cin >> y;
	switch (y) {

	case 'a':do
	{
		cout << "Introduceti numarul evenimentului : ";
		cin >> i;
	} while (i < 1 && i >= j);
	e[i].OcupareLoc();
	cout << "Doriti sa mai ocupati un loc?" << endl;
	cout << "a. Da " << endl;
	cout << "b. Nu " << endl;
	cout << "Introduceti optiunea : ";
	cin >> z;
	while (z == 'a')
	{
		e[i].OcupareLoc();
		cout << "Doriti sa mai ocupati un loc?" << endl;
		cout << "a. Da " << endl;
		cout << "b. Nu " << endl;
		cout << "\nIntroduceti optiunea : ";
		cin >> z;
	}
	MeniuEvenimente();
	break;


	default: cout << "Nu avem aceasta optiune!";
		MeniuEvenimente();
		break;
	case 'b':
		std::cout << "\nIntroduceti numarul evenimentului pe care doriti sa il stergeti : ";
		std::cin >> st;
		filepath = e[st].getNume();
		filepath = filepath + ".txt";
		const char* c = filepath.c_str();
		remove(c);
		ofstream out("FisierSala.txt");
		for (i = 1; i <= j - 1; i++)
		{
			if (i != st)
			{
				out << e[i].getNume() << " ";
				out << e[i].getOrganizator() << " ";
				out << e[i].getPret() << " ";
				out << e[i].getZi() << " ";
				out << e[i].getLuna() << " ";
				out << e[i].getAn() << " ";
				out << e[i].getOra() << " ";
				out << e[i].getMinut() << endl;
			}
		}
		out.close();
		MeniuEvenimente();
		break;

	}
}
void Functii::MeniuAdmin(void)
{
	char c;
	system("cls");
	cout << "\nMeniu Administrator:" << endl;
	cout << "\na. Afisare evenimente" << endl;
	cout << "\nb. Monitorizare incasari" << endl;
	cout << "\nd. Adaugare evenimente" << endl;
	cout << "\nd. Schimbare parola" << endl;
	cout << "\ne. Iesire" << endl;
	cout << "\nNumarul optiunii : ";
	cin >> c;
	cout << endl;
	switch (c) {
	case 'a': system("cls");
		      ListareEvenimente();
		      break;
	case 'b': system("cls");
		      IncasareEv();
		      break;
	case 'c': AdaugareEveniment();
		       break;
	case 'd': SchimbareParola();
		       break;
	case 'e': exit(0);
	default:  MeniuAdmin();
		       break;
	}
}
void Functii::Logare(void) 
{       
		string pass, user, parola;
		char ch;

	tryagain:   // reincercare
		system("cls");
		cout << "\nIntroduceti username-ul : ";
		cin >> user;
		if (user != "Administrator" && user != "Casier")
		{
			system("cls");
			cout << " Username gresit " << endl;
			goto tryagain;
		}

		if (user == "Administrator") {
			ifstream in("parola.txt");
			in >> parola;
		  tryagain2:  // eticheta
			pass = "";
			cout << "\n Introduceti parola :  ";
			ch = _getch();
			while (ch != 13)
			{
				cout << "*";
				pass.push_back(ch);
				ch = _getch();
			}
			if (pass == parola) {
				MeniuAdmin();
				system("PAUSE");
			}
			else
			{
				if (pass == "exit")
				{
					goto tryagain;
				}
				else
				{
					system("cls");
					cout << "Parola incorecta \n Incercati din nou sau, pentru iesire, scrieti 'exit' : " << endl;
					goto tryagain2;
				}
			}
		}
		if (user == "Casier")
		{
			MeniuEvenimente();
			system("PAUSE");
		}
	
	}

void Functii::IncasareEv(void)
{
	string sir1, sir2;
	char var;
	int m, n, p, q, o, i, j, min, sum, sumt;
	Eveniment e[21];

	ifstream in("FisierSala.txt");
	for (i = 1; !in.eof(); i++)
	{ // Introducerea fiecarei componente in membrii vectorului
		in >> sir1;
		e[i].setNume(sir1);
		in >> sir2;
		e[i].setOrganizator(sir2);
		in >> m;
		e[i].setPret(m);
		in >> n;
		e[i].setZi(n);
		in >> p;
		e[i].setLuna(p);
		in >> q;
		e[i].setAn(q);
		in >> o;
		e[i].setOra(o);
		in >> min;
		e[i].setMinut(min);
	}
	in.close();
	j = i - 1;
	for (i = 1; i < j; i++) {
		cout << i << ". " << e[i].getNume() << endl;
	}
	cout << "\na. Suma per eveniment;" << endl;
	cout << "\nb. Suma facuta de toate spectacolele;" << endl;
	cout << "\n Introduceti varianta : ";
	cin >> var;


	if (var == 'a') {
		cout << "Introduceti numarul evenimentului : ";
		cin >> i;
		ifstream sumin(e[i].getNume() + "-incasari.txt");
		sumin >> sum;
		sumin.close();
		system("cls");
		cout << e[i].getNume() << " - " << "Bilete vandute : " << sum / e[i].getPret() << " ;  Suma incasata : " << sum << endl;
	}
	else {
		if (var == 'b') {
			sumt = 0;
			for (i = 1; i < j; i++) {
				ifstream sumin(e[i].getNume() + "-incasari.txt");
				sumin >> sum;
				sumt = sumt + sum;
				sumin.close();
			}
			cout << " Suma incasata de toate spectacolele : " << sumt << endl;
			system("PAUSE");
			MeniuAdmin();
		}
		else { cout << " Nu avem aceasta optiune!" << endl; }
	}
}
void Functii::SchimbareParola(void)
{
	string confirmare, pass;
	char ch;
tryagain3:
	pass = "";
	cout << "Introduceti noua parola : ";
	ch = _getch();
	while (ch != 13)
	{
		cout << "*";
		pass.push_back(ch);
		ch = _getch();
	}
	confirmare = "";
	cout << endl << endl << "Confirmare parola :  ";
	ch = _getch();
	while (ch != 13)
	{
		cout << "*";
		confirmare.push_back(ch);
		ch = _getch();
	}
	if (pass == confirmare) {
		ofstream out("parola.txt");
		out << pass;
		out.close();
		Logare();
	}
	else {
		system("cls");
		cout << "Nepotrivire! Mai introduceti o data parola: " << endl;
		goto tryagain3;
	}
}
