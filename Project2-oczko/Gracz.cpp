#include "Gracz.h"
#include "Kasyno.h"

Gracz::Gracz(Kasyno* kasyno) {
	ile = 0;
	wartosc = 0;
	stol = kasyno;
	cout << "Podaj nazwe gracza: " << endl;
	cin >> nazwa;
	while (strlen(nazwa) > 20) {
		cout << "Nazwa jest za dluga. Podaj jeszcze raz" << endl;
		cin.clear();
		cin >> nazwa;
	}
}

int Gracz::ile_kart() {
	return ile;
}

int Gracz::wartosc_kart() {
	return wartosc;
}

bool Gracz::decyzja() {
	return pass;
}

void Gracz::wezKarte(Karta* _karta) {
	if (ile > 10) {
		cout << "Gracz posiada maksymalna liczbe kart na rece" << endl;
		return;
	}
	else if (_karta == NULL) {
		cout << "Nie ma wiecej kart w talii" << endl;
		return;
	}
	reka[ile] = _karta;
	//this->wartosc += _karta->getWartosc();
	ile += 1;

	if (wartosc > 21)
		pass = true;
}

void Gracz::pokaz_karty() {
	for (int i = 0;i < ile;i++) {
		reka[i]->wypisz();
		cout << " ";
	}
}

bool Gracz::decyduj() {
	string wybor;
	while (wybor != "k" && wybor != "p") {
		cout << "CO CHCESZ ZROBIC?" << endl << "Dobrac karte? / Pass? (k/p): " << endl;
		cin >> wybor;
		{
			cout << "Zla odpowiedz. Podaj jeszcze raz." << endl;
			cin.clear();
		}
	}
	if (wybor == "n")
		return pass = true;
	else
		return pass = false;
}

