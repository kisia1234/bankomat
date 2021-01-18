#pragma once
#ifndef KILENT_H
#define KLIENT_H

#include "karta.hpp"
#include "telefon.hpp"
#include "konto.hpp"
#include "bankomat.hpp"

class Klient {
public:
	Klient(std::string numer_konta, Karta karta, Telefon telefon);
	Klient(std::string numer_konta, std::string imie, std::string nazwisko);
	std::string zwroc_numer_konta() const;
private:
	std::string numer_konta;
	Karta karta;
	Telefon telefon;
	std::string imie;
	std::string nazwisko;
};

#endif