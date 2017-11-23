#include "stdafx.h"
#include <iostream>

void checkChar(char input) {
	std::cout << input << std::endl;
	if (isdigit(input)) {
		std::cout << "Character is a digit!" << std::endl;
		return;
	}
	else if (isspace(input)) {
		std::cout << "Character is whitespace!" << std::endl;
	}
	else if (isalpha(input)) {
		if (isupper(input)) {
			std::cout << "Character is uppercase!" << std::endl;
		}
		else {
			std::cout << "Character is lowercase!" << std::endl;
		}
	}
	else {
		std::cout << "Character is not recognised." << std::endl;
	}
	return;
}