#include "baza_danych.h"
#include <fstream>

bool Baza_danych::wczytaj()
{
	std::ifstream ifs{ "baza_danych.txt" };
	for (std::string numer; ifs >> str; ) {
		baza_danych.insert(numer);
	}
}
