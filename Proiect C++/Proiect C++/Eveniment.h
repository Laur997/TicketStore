#pragma once
#include <string>
#include <fstream>
#include <iostream> 
using namespace std;
class Eveniment
{
public:
	Eveniment() {};
	~Eveniment() {};
	void  setNume(string);
	string getNume(void);
	void setOrganizator(string);
	string getOrganizator(void);
	void setPret(int p);
	int getPret(void);
	void initializareLocuri(void);
	void setZi(int zi);
	int getZi(void);
	void setLuna(int luna);
	int getLuna(void);
	void setAn(int an);
	int getAn(void);
	void setOra(int ora);
	int getOra(void);
	void setMinut(int minut);
	int getMinut(void);
	void OcupareLoc(void);
	int getSuma(void);


private:string nume;
		string organizator;
		int pretBilet;
		int loc[9][13];
		int zi, luna, an, ora, minut;
};

