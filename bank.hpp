#pragma once

#ifndef BANK_H
#define BANK_H

#include "pracownik.hpp"
#include <string>
#include <vector>
#include "konto.hpp"
#include "baza_danych.hpp"
#include "transakcja.hpp"
#include <map>

class Pracownik;

class Bank {
public:
	Bank(std::string id);
	bool zablokowanie_konta(const std::string& numer_konta);
	bool sprawdzenie_kodu_pin(const std::string& pin, const std::string& numer_konta);
	bool czy_konto_jest_zablkowane(const std::string& numer_konta);
	bool zmiana_stanu_konta(Transakcja transakcja);
	Konto pobranie_informacji_o_koncie(const std::string& numer_konta);
	bool czy_wystarczajaca_ilosc_srodkow(const std::string& numer_konta, long ilosc);
	bool czy_konto_istnieje(const std::string& numer_konta);
	Pracownik wyslij_pracownika();
	std::string wyslij_numer_pracownika();
	//std::string zwroc_numer_konta(std::string numer_karty);
private:
	//std::map<std::string, std::string> numery_kont;
	Pracownik pracownik;		// pracownicy banku
	std::string identyfikator;
	Baza_danych baza_danych;
};

#endif