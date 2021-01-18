#include<iostream>
#include<exception>
#include "wybor.hpp"
#include "bank.hpp"
#include "bankomat.hpp"
#include "wybor_menu_glowne.hpp"

int main() {

	try {
		Bank bank("123");
		Bankomat bankomat{ 300000, "12321", bank };
		Klient Nikola{ "780032", "Nikola", "Prochalska" };

		if (!bankomat.autoryzacja(Nikola)) {
			return -1;
		}

		std::cout << "1. Przeprowadzenie trasnsakcja\n2. Saldo\n3. Anuluj\n";
		int wybor;
		while (1) {

			if (bankomat.uzupelnienie) {
				bankomat.prosba_o_uzupelnienie_pieniedzy();
				bankomat.uzupelnienie = false;
			}

			std::cout << "wybierz opcje\n";

			std::cin >> wybor;
			switch (static_cast<Menu>(wybor))
			{
			case Menu::Transakcja:
				bankomat.przeprowadz_transakcje();
				break;
			case Menu::Saldo:
				bankomat.wyswietlenie_salda();
				break;
			case Menu::Anuluj:
				return 0;
			}
		}
	}

	catch (std::exception& exc) {
		std::cerr << exc.what() << '\n';
		return -1;
	}

	catch (...) {
		std::cerr << "unknown exception\n";
		return -2;
	}

	return 0;
}