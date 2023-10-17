#pragma once
#include "main_interface.h"

void sing_up()
{
	std::string login, password;
	std::string name, family, phonenumber;
	std::cout << "Enter login: "; std::cin >> login;
	std::cout << "Enter password: "; std::cin >> password;
	std::cout << "Enter name: "; std::cin >> name;
	std::cout << "Enter family: "; std::cin >> family;
	std::cout << "Enter phonenumber: "; std::cin >> phonenumber;
}