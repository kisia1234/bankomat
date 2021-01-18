#include "klient.hpp"

Klient::Klient(std::string numer_konta, Karta karta, Telefon telefon) : numer_konta {numer_konta}
{
}

Klient::Klient(std::string numer_konta, std::string imie, std::string nazwisko) : numer_konta{ numer_konta }, imie{ imie }, nazwisko{ nazwisko }
{

}

std::string Klient::zwroc_numer_konta() const
{
	return numer_konta;

}