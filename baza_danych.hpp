#pragma once

#ifndef BAZA_DANYCH_H
#define BAZA_DANYCH_H

#include<string>
#include "konto.hpp"
#include <unordered_map>

struct Baza_danych {
	bool wczytaj();
	std::unordered_map<std::string, Konto> dane;
};

#endif