#include<string>
#include "konto.h"
#include <unordered_map>

class Baza_danych {
public:
	bool wczytaj();
private:
	std::unordered_map<Konto, int> baza_danych;
};