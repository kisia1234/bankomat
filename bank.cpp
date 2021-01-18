#include "bank.hpp"

Bank::Bank(std::string id) : identyfikator{ id }, pracownik("777") {
	baza_danych.wczytaj();
	//numery_kont.insert(std::make_pair("1111", "780032");
}

bool Bank::zablokowanie_konta(const std::string& numer_konta)
{
	if (baza_danych.dane.at(numer_konta).czy_zablokowane == false) {
		baza_danych.dane.at(numer_konta).czy_zablokowane = true;
		return true;
	}
	return false;
}

bool Bank::sprawdzenie_kodu_pin(const std::string& pin, const std::string& numer_konta)
{
	if (baza_danych.dane.at(numer_konta).PIN == pin)
		return true;
	return false;
}

bool Bank::czy_konto_jest_zablkowane(const std::string& numer_konta)
{
	return baza_danych.dane.at(numer_konta).czy_zablokowane == true;
}

bool Bank::zmiana_stanu_konta(Transakcja transakcja)
{
	switch (transakcja.typ) {
	case Typ::Wplata:
		baza_danych.dane.at(transakcja.numer_konta).saldo += transakcja.kwota;
		return true;
		break;
	case Typ::Wyplata:
		if (czy_wystarczajaca_ilosc_srodkow(transakcja.numer_konta, transakcja.kwota)) {
			baza_danych.dane.at(transakcja.numer_konta).saldo -= transakcja.kwota;
			return true;
		}
		else 
			return false;
	case Typ::Nieprawidlowa:
		return false;
	}
}

Konto Bank::pobranie_informacji_o_koncie(const std::string& numer_konta)
{
	return baza_danych.dane.at(numer_konta);
}

bool Bank::czy_wystarczajaca_ilosc_srodkow(const std::string& numer_konta, long ilosc)
{
	if (baza_danych.dane.at(numer_konta).saldo >= ilosc)
		return true;
	return false;
}

bool Bank::czy_konto_istnieje(const std::string& numer_konta)
{
	auto it = baza_danych.dane.find(numer_konta);
	if (it == baza_danych.dane.end())
		return false;
	return true;
}

Pracownik Bank::wyslij_pracownika()
{
	return pracownik;
}

std::string Bank::wyslij_numer_pracownika()
{
	return pracownik.pobiez_numer();
}

/*
std::string Bank::zwroc_numer_konta(std::string numer_karty)
{
	return numery_kont.at(numer_karty);
}
*/


