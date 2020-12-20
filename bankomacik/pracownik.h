#include "osoba.h"

#include <string>

class Pracownik : public Osoba {
public:
	bool uzupelnianie_pieniedzy() const;
	void odbior_informacji_o_ilosci_gotowki() const;
	long sprawdzenie_zasobow() const;
private:
	std::string numer_identyfikacyjny;
};