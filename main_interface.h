#pragma once
#include <iostream>
#include <string>

void start_menu()
{
	std::cout << "\t_________Welcome to BookStore__________" <<std::endl;
	char choice{'a'};
	std::cout << "Sing up(u) or Sing in(i)" << std::endl;
	std::cout << "Enter your choice: "; std::cin >> choice;
	if (choice == 'i')
	{

	}
	else if (choice == 'u')
	{

	}
	else
	{
		std::cout << "Don't correct input. Repeat." << std::endl;
		start_menu();
	}
}