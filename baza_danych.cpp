#include "baza_danych.hpp"
#include <fstream>
#include <sstream>

bool Baza_danych::wczytaj()
{
	std::ifstream ifs{ "baza_danych.txt" };
	if (!ifs) {
		return false;
	}
	Konto temp;

	// czytaj linia po lini
	for (std::string line; std::getline(ifs, line); ) {

		std::istringstream is{ line };
		is >> temp.numer;	// numer konta
		is >> temp.imie;
		is >> temp.nazwisko;
		is >> temp.saldo;
		is >> temp.PIN;
		is >> temp.czy_zablokowane;
		dane.insert(std::make_pair(temp.numer, temp));
	}

	return true;
}