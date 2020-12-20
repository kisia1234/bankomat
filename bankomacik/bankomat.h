#include <string>
#include "system_komunikacji.h"

class Bankomat {
public:
	bool wyplata();
	bool wplata();
	void prosba_o_uzupelnienie_pieniedzy();
	void sprawdzenie_salda();
	void odbior_gotowki_od_pracownika();
	void sprawdzenie_zasobow();
	void wprowadzenie_pinu();
	void wprowadzenie_kwoty();
	void wprowadzenie_kodu_blik();
	void wyswietlenie_salda();
private:
	long ilosc_gotowki;
	std::string idenfyfikator;
	int licznik_prob;
	System_komunikacji system;
	// stan
};

