#pragma once
#include <iostream>
#include <string>
#include "fabrica_account.h"
#include "node.h"

#include "sing_in.h"
#include "sing_up.h"

void start_menu()
{
	std::cout << "\t_________Welcome to BookStore__________" <<std::endl;
	char choice{'a'};
	std::cout << "Sing up(u) or Sing in(i)" << std::endl;
	std::cout << "Enter your choice: "; std::cin >> choice;
	if (choice == 'i')
	{
		sing_in();
	}
	else if (choice == 'u')
	{
		sing_up();
	}
	else
	{
		std::cout << "Don't correct input. Repeat." << std::endl;
		start_menu();
	}
}