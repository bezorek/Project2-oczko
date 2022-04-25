#include "Karta.h"
#pragma once

class Kasyno;
class Gracz {
private:
	Kasyno* stol;
	Karta* reka[10];
	int ile;
	int wartosc;
	bool pass = false;
	char nazwa[20];
public:
	Gracz(Kasyno*);
	void wezKarte(Karta* _karta);
	int ile_kart();
	int wartosc_kart();
	void pokaz_karty();
	bool decyduj();
	bool decyzja();

};