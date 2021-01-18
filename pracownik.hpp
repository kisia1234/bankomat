#pragma once

#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <string>
//#include "bankomat.hpp"

class Bankomat;

class Pracownik {
public:
	Pracownik() = default;
	Pracownik(std::string numer) : numer_identyfikacyjny{ numer } {}
	void uzupelnianie_pieniedzy(long ilosc, Bankomat& bankomat) const;
	bool identyfikacja(std::string numer) const;
	std::string pobiez_numer();
private:
	std::string numer_identyfikacyjny;
};

#endif
