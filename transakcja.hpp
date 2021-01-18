#pragma once

#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

#include <string>

enum class Typ { Wplata, Wyplata, Nieprawidlowa };

struct Transakcja {
	Typ typ;
	std::string numer_konta;
	int kwota;
};

#endif