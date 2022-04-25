#include <iostream>
#include "Karta.h"
#include "Kasyno.h"
#include "Gracz.h"
using namespace std;

int main() {
	Kasyno p1;
	p1.tasuj();
	p1.poczatek();
	p1.pokaz_talie();
	_CrtDumpMemoryLeaks();
}