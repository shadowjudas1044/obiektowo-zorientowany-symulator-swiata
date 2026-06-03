#include "Organizm.h"
#include "Swiat.h"
#include <iostream>

using namespace std;

Organizm::Organizm(int x, int y, int sila, int inicjatywa, char symbol, int wiek) {
	this->swiat = Swiat::getSwiat();
	this->pozycja = { x, y };
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->wiek = wiek;
	swiat->dodajOrganizm(this);
}

void Organizm::rysowanie() {
	int x = this->pozycja.x + 2;
	int y = this->pozycja.y + 2;
	cout << "\033[" << y << ";" << x << "H";
	cout << "\033[30m";
	if (symbol == 't') {
		cout<<"\033[42m";
	}
	else if(symbol == 'C') {
		cout<<"\033[41m";
	}
	else if(symbol >='A' && symbol <= 'Z') {
		cout<<"\033[46m";
	}
	else {
		cout<<"\033[45m";
	}
	cout << this->symbol;
	cout << "\033[0m";
}

void Organizm::dodajWiek() {
	this->wiek++;
}

void Organizm::setPolozenie(int x, int y) {
	Organizm* inny_organizm = swiat->getOrganizm(x, y);
	if (inny_organizm != nullptr) {
		inny_organizm->kolizja(this);
	}
	else {
		this->pozycja = {x, y};
	}
}

bool Organizm::czyMozliwyRuch(int x, int y, bool musiBycPuste) {
	if (x < 0 || x >= swiat->getSzerokosc() || y < 0 || y >= swiat->getWysokosc()) {
		return false;
	}
	else {
		if (musiBycPuste) {
			Organizm* inny_organizm = swiat->getOrganizm(x, y);
			if (inny_organizm != nullptr) {
				return false;
			}
			else {
				setPolozenie(x, y);
				delete inny_organizm;
				return true;
			}
		}
		else {
			swiat->dodajLog(" poszedl na pole (" + to_string(x) + ", " + to_string(y) + ")", this);
			setPolozenie(x, y);
			return true;
		}
	}
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

//gettery
int Organizm::getPozycjaX() {
	return this->pozycja.x;
}

int Organizm::getPozycjaY() {
	return this->pozycja.y;
}

int Organizm::getWiek() {
	return this->wiek;
}

int Organizm::getSila() {
	return this->sila;
}

int Organizm::getInicjatywa() {
	return this->inicjatywa;
}

int Organizm::getX() {
	return this->pozycja.x;
}

int Organizm::getY() {
	return this->pozycja.y;
}

char Organizm::getSymbol() {
	return this->symbol;
}