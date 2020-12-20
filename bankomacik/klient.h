#ifndef KILENT_H_
#define KLIENT_H_

#include "osoba.h"
#include "karta.h"
#include "telefon.h"
#include "konto.h"

class Klient : public Osoba {
public:
	Klient();
	bool wprowadz_kod_PIN() const;
	bool wprowadz_kod_BLIK() const;
	void odbierz_informacje() const;
	bool wprowadz_karte() const;
	void sprawdz_stan_konta() const;
private:
	Konto konto;
	Karta karta;
	Telefon telefon;
};

#endif