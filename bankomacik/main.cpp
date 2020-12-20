#include<iostream>
#include "wybor.h"

int main() {

	int wybor;

	std::cout << "Wybierz\n1.Wplata\n2.Wyplata\n3.Pokaz saldo\n4.Anuluj\n";

	while (1) {

		std::cin >> wybor;

		switch (wybor) {

		case Wplata:
			std::cout << "Wplata\n";
			break;
		case Wyplata:
			std::cout << "Wyplata\n";
			break;
		case Saldo:
			std::cout << "Saldo\n";
			break;
		case Anuluj:
			return 0;
			break;
		default:
			std::cout << "nieznana opcja\n";
			break;
		}

	}

	return 0;
}