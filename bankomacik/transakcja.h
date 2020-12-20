#include <string>

enum class Typ {Wplata, Wyplata, Nieprawidlowa};

struct Transakcja {
	Typ typ;
	std::string numer_konta;
	int kwota;
};