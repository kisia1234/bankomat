#pragma once
#ifndef SYSTEM_KOMUNIKACJI_H
#define SYSTEM_KOMUNIKACJI_H	

#include <string>				
#include "bank.hpp"

class Bank;

class System_komunikacji {
public:
	System_komunikacji(Bank& bank);
	System_komunikacji();
	/*
	void wyslanie_prosby_o_sprawdzenie_informacji();
	void wyslanie_prosby_o_sprawdzenie_pinu();
	void wyslanie_prosby_o_sprawdzenie_blik();
	void wyslanie_prosby_o_sprawdzenie_czy_konto_jest_zablokowane();
	void przeprowadz_transakcje();
	*/
	Bank& zwroc_bank();
private:
	Bank& bank;
	std::string id_banku;
	std::string id_bankomatu;
};

#endif


