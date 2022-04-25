#include "Kasyno.h"
#include <cstdlib>
#include <time.h>

Kasyno::Kasyno() {
	cout << "Podaj ile ma byc graczy? (1-3)" << endl;
	cin >> ile_graczy;
	while (ile_graczy != 1 && ile_graczy != 2 && ile_graczy != 3) {
		cout << "Niepoprawny wybor." << endl << "Podaj jeszcze raz : ";
		cin.clear();
		cin >> ile_graczy;
	}
	gracze = new Gracz*[ile_graczy];
	for (int i = 0; i < ile_graczy;i++) {
		gracze[i] = new Gracz(this);

	}

	int k = 0;
	for (int j = 0;j < 4;j++) {
		for (int i = 0;i < 13; i++) {
			talia[k] = Karta(j, i);
			k++;
		}
	}
}

Kasyno::~Kasyno() {
	delete[] gracze;
}

void Kasyno::pokaz_talie() {
	for (int i = 0;i < ilosc;i++) {
		talia[i].wypisz();
		cout << endl;
	}
}

void Kasyno::tasuj() {
	srand(time(NULL));
	int b;
	Karta tmp;
	for (int i = 0; i < 101;i++) {
		int a = rand() % 52;
		tmp = talia[a];
		b = rand() % 52;
		if (a == b) {
			i -= 1;
			continue;
		}
		talia[a] = talia[b];
		talia[b] = tmp;
	}
}

Karta* Kasyno::dajKarte() {
	if (ilosc < 0) {
		cout << "Nie ma wiecej kart w talii" << endl;
		return NULL;
	}
	Karta tmp;
	tmp = talia[ilosc-1];
	talia[ilosc-1] = NULL;
	ilosc -= 1;
	return &tmp;
}

void Kasyno::poczatek() {
	for (int i = 0; i < 2;i++) {
		for (int j = 0; j < ile_graczy;j++) {
			gracze[j]->wezKarte(dajKarte());
		}
	}
}

