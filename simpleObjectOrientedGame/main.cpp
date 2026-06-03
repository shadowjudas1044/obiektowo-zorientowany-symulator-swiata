#include <iostream>
#include <windows.h>
#include <time.h>
#include "conio.h"
#include "Swiat.h"
#include "Czlowiek.h"
#include <fstream>

using namespace std;

#define ZAPIS 'z'
#define WCZYTAJ 'x'

#define WYSOKOSC_INFO swiat->getWysokosc() + 5

void ustawWielkosc(int* wysokosc, int* szerokosc) {
	while (1) {
		cout << "Wysokosc swiata (min.10): ";
		cin >> *wysokosc;
		cout << "Szerokosc swiata (min.10): ";
		cin >> *szerokosc;
		if(*wysokosc >= 10 && *szerokosc >= 10) {
			break;
		}
		else {
			cout << "Wymiary musza byc wieksze niz 10!" << endl;
		}
	}
}

void zapisz(Swiat* swiat) {
	ofstream plik;

	plik.open("log.txt");
	swiat->zapiszSwiat(plik);
	plik.close();

	cout << "\033[" << WYSOKOSC_INFO << ";1H";
	cout << "\033[2K";
	cout << "\033[" << WYSOKOSC_INFO << ";1H";
	cout << "Zapisano do pliku!";
	Sleep(1000);
}

void wczytaj(Swiat* swiat) {
	cout << "\033[" << WYSOKOSC_INFO << ";1H";
	cout << "\033[2K";
	cout << "\033[" << WYSOKOSC_INFO << ";1H";
	cout << "Wczytano z pliku!";
	Sleep(1000);
}

int main() {
	cout << "\033[?25l"; // ukryj kursor
	SetConsoleTitle(L"Igor Trajdos 197954");
	srand(time(NULL));

	int wysokosc, szerokosc;

	ustawWielkosc(&wysokosc, &szerokosc);

	Swiat *swiat = new Swiat(wysokosc, szerokosc);
	swiat->organizmyNaPlanszy();
	swiat->rysujSwiat();

	while (true) {
		cout << "\033[" << WYSOKOSC_INFO << ";1H";
		cout << "\033[2K";
		swiat->tura();
		swiat->rysujSwiat();
		swiat->rysujLog();

		cout << "\033[" << WYSOKOSC_INFO << ";1H";
		cout << "koniec tury\tz->zapisz\tx->wczytaj";
		char klawisz = _getch();

		if(klawisz == ZAPIS){
			zapisz(swiat);
		}
		else if(klawisz == WCZYTAJ){
			ifstream plik;
			plik.open("log.txt");
			swiat = Swiat::wczytajSwiat(plik);
			system("cls");
			swiat->rysujSwiat();
			plik.close();
			wczytaj(swiat);
		}
	}
	delete swiat;
	return 0;
}