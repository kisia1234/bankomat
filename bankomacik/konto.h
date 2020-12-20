#include <string>

struct Konto {
	std::string numer;
	std::string imie;
	std::string nazwisko;
	long saldo;
	std::string PIN;
	bool czy_zablokowane;
};