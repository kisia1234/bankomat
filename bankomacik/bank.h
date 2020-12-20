
#include <string>
#include "konto.h"

class Bank {
public:
	void zablokowanie_konta();
	bool identyfikacja();
	void sprawdzenie_kodu_pin();
	void sprawdzenie_kodu_blik();
	void komunikacja_bank_konto();
	bool czy_konto_jest_zablkowane();
	void zmiana_stanu_konta();
	Konto pobranie_informacji_o_koncie();
private:
	std::string indentyfikator;
	// baza danych (z pliku)
};