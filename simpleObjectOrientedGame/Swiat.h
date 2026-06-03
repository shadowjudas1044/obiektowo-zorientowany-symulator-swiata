#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Organizm.h"

using namespace std;

class Swiat {
private:
	vector<Organizm*> organizmy;
	vector<string> log;
	Organizm* czlowiek;
	int wysokosc;
	int szerokosc;
	bool priorytet(Organizm* organizm1, Organizm* organizm2);
	static Swiat* stworzony_swiat;
public:
	Swiat(int wysokosc, int szerokosc);
	void organizmyNaPlanszy();
	void dodajOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	void rysujSwiat();
	void tura();
	void dodajLog(string log, Organizm* kto);
	void rysujLog();
	void zapiszSwiat(ofstream& plik);
	static Swiat* wczytajSwiat(ifstream& plik);
	//gettery
	Organizm* getCzlowiek();
	int getWysokosc();
	int getSzerokosc();
	static Swiat* getSwiat();
	Organizm* getOrganizm(int x, int y);
};