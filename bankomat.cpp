#include "bankomat.hpp"
#include "wybor.hpp"
#include <iostream>

Bankomat::Bankomat(long ilosc, std::string id, Bank& bank) : ilosc_gotowki{ ilosc }, idenfyfikator { id }, system(bank)
{
	
}

void Bankomat::przeprowadz_transakcje()
{
	int wybor;
	long kwota;
	std::cout << "Wybierz\n1.Wplata\n2.Wyplata\n4.Anuluj\n";
	std::cin >> wybor;
	switch (static_cast<Wybor>(wybor)) {

	case Wybor::Wplata: 
		std::cout << "Podaj kwote: \n";
		std::cin >> kwota;
		wplata(kwota);
		break;
	case Wybor::Wyplata:
		std::cout << "Podaj kwote: \n";
		std::cin >> kwota;
		wyplata(kwota);
		break;
	case Wybor::Anuluj:
		break;
	default:
		std::cout << "nieznana opcja\n";
		break;
	}
}

bool Bankomat::wyplata(long kwota)
{
	Transakcja transakcja = { Typ::Wyplata, aktualny_nr_konta, kwota };
	if (ilosc_gotowki >= kwota) {
		ilosc_gotowki -= kwota;
		std::cout << "wyplata (" << kwota << ")\twykonana pomyslnie\n";
		system.zwroc_bank().zmiana_stanu_konta(transakcja);
		if (!czy_wystarcza_gotowki()) {	// czy nalezy uzupelnic pieniadze w bankomacie
			std::cout << "prosba o uzupelnienie pieniedzy\n";
			uzupelnienie = true;
		}
		return true;
	}
	std::cout << "brak wystarczajacej ilosci srodkow w bankomacie\n";
	return false;
}

bool Bankomat::wplata(long kwota)
{
	Transakcja transakcja = { Typ::Wplata, aktualny_nr_konta, kwota };
	ilosc_gotowki += kwota;
	std::cout << "wplata (" << kwota << ")\twykonana pomyslnie\n";
	system.zwroc_bank().zmiana_stanu_konta(transakcja);
	return true;
}

void Bankomat::prosba_o_uzupelnienie_pieniedzy()
{
	Pracownik pracownik = system.zwroc_bank().wyslij_pracownika();
	std::string id_pracownik = system.zwroc_bank().wyslij_numer_pracownika();
	if (!pracownik.identyfikacja(id_pracownik)) {
		std::cout << "niepoprawny numer identyfikacyjny pracownika\n";
		return;
	}
	else {
		std::cout << "poprawny numer\n uzupeniono pieniadze\n";
		pracownik.uzupelnianie_pieniedzy(300000, *this);
	}
}

long Bankomat::sprawdzenie_salda()
{
	return system.zwroc_bank().pobranie_informacji_o_koncie(aktualny_nr_konta).saldo;
}

bool Bankomat::czy_wystarcza_gotowki()
{
	if (ilosc_gotowki <= min_ilosc_gotowki)
		return false;
	return true;
}

void Bankomat::wprowadz_karte(Klient klient)
{
	aktualny_nr_konta = klient.zwroc_numer_konta();
}

void Bankomat::wprowadzenie_pinu()
{
	std::string buff;
	std::cin >> buff;
	aktualny_nr_pin = buff;
}

bool Bankomat::sprawdz_pin()
{
	if (system.zwroc_bank().sprawdzenie_kodu_pin(aktualny_nr_pin, aktualny_nr_konta))
		return true;
	return false;
}

bool Bankomat::autoryzacja(Klient klient)
{
	std::cout << "wczytywanie karty ... \n";
	wprowadz_karte(klient);
	if (!system.zwroc_bank().czy_konto_istnieje(klient.zwroc_numer_konta())) {
		std::cout << "nie znaleziono konta w bazie danych\n";
		return false;
	}
	if (system.zwroc_bank().czy_konto_jest_zablkowane(klient.zwroc_numer_konta())) {
		std::cout << "konto jest zablokowane\n";
		return false;
	}
	int cntr = 0;
	std::cout << "Wprowadz pin\n";
	wprowadzenie_pinu();
	while (!sprawdz_pin()) {
		cntr++;
		if (cntr == 3) {
			std::cout << "wpisano nieprawidlowy pin 3 razy\nkonto"
				"zostalo tymczasowo zablokowane\n";
			system.zwroc_bank().zablokowanie_konta(klient.zwroc_numer_konta());
			return false;
		}
		std::cout << "niepoprawny pin\nsproboj ponownie\n";
		wprowadzenie_pinu();
	}
	std::cout << "poprawny pin\n";
}


void Bankomat::wyswietlenie_salda()
{
	Konto konto = system.zwroc_bank().pobranie_informacji_o_koncie(aktualny_nr_konta);
	std::cout << "saldo:\t"<< konto.saldo << '\n';
}

void Bankomat::uaktualnij_klienta(const std::string& nr_konta)
{
	aktualny_nr_konta = nr_konta;
}

void Bankomat::doladuj(long ilosc)
{
	ilosc_gotowki += ilosc;
}
