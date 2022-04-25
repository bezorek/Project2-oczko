#include "Karta.h"
#include "Gracz.h"
#pragma once

class Kasyno {
private:
	Gracz** gracze;
	int ile_graczy;
	int ilosc = 52;
	Karta talia[52];
public:
	Kasyno();
	~Kasyno();
	void pokaz_talie();
	void tasuj();
	Karta* dajKarte(); // chyba blad
	void poczatek();
	// void czy_spasowal
};

