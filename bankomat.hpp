#pragma once

#ifndef BANKOMAT_H
#define BANKOMAT_H

#include <string>

#include "klient.hpp"
#include "bank.hpp"
#include "system_komunikacji.hpp"


class Bank;
class Klient;
class System_komunikacji;

class Bankomat {
public:
	Bankomat(long ilosc, std::string id, Bank& bank);
	void przeprowadz_transakcje();
	bool wyplata(long kwota);
	bool wplata(long kwota);
	void prosba_o_uzupelnienie_pieniedzy();
	long sprawdzenie_salda();
	bool czy_wystarcza_gotowki();
	void wprowadz_karte(Klient klient);
	void wprowadzenie_pinu();
	bool sprawdz_pin();
	bool autoryzacja(Klient klient);
	void wyswietlenie_salda();
	void uaktualnij_klienta(const std::string& nr_konta);
	void doladuj(long ilosc);
	bool uzupelnienie{ false };
private:
	std::string numer_id_pracownika;
	std::string aktualny_nr_konta;
	std::string aktualny_nr_pin;
	long ilosc_gotowki;
	std::string idenfyfikator;
	int licznik_prob;
	System_komunikacji system;
	static const int min_ilosc_gotowki = 30000;		// ilosc gotowki od ktorej wysylamy prosbe o uzupelnienie
};

#endif