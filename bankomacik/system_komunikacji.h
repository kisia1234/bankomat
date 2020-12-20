
#include <string>					

class System_komunikacji {												  
public:															
	void wyslanie_prosby_o_sprawdzenie_informacji();
	void wyslanie_prosby_o_sprawdzenie_pinu();
	void wyslanie_prosby_o_sprawdzenie_blik();
	void wyslanie_prosby_o_sprawdzenie_czy_konto_jest_zablokowane();
	void przeprowadz_transakcje();
private:
	std::string id_banku;
	std::string id_bankomatu;
};




