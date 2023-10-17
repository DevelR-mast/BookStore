#include "kernel.h"

Devoma::kernel::kernel()
{
	DataBaseAccount = new database_account{};
	DataBaseBook = new data_base_file{};
}

Devoma::kernel::~kernel()
{
	delete DataBaseAccount;
	delete DataBaseBook;
}

void Devoma::kernel::start()
{
	std::cout << "****************Welcome to BookStore*******************" << std::endl;
	char choise{ 'a' };
	std::cout << "Sing up(u) or Sing in(i)" << std::endl;
	std::cout << "Enter your choice: "; std::cin>>choise;
	if (choise == 'i')
	{
		sign_in();
	}
	else if (choise == 'u')
	{
		sign_up();
	}
	else
	{
		std::cout << "Don't correct input. Repeat." << std::endl;
		start();
	}
}

void Devoma::kernel::sign_up()
{
	std::string login, password;
	std::string name, family, phonenumber;
	std::cout << "Enter login: "; std::cin >> login;
	std::cout << "Enter password: "; std::cin >> password;
	std::cout << "Enter name: "; std::cin >> name;
	std::cout << "Enter family: "; std::cin >> family;
	std::cout << "Enter phonenumber: "; std::cin >> phonenumber;
	try
	{
		Devoma::account_base *account = DataBaseAccount->add_account(login, password, name, family, phonenumber);
		interface_account(account);
	}
	catch (Devoma::error er)
	{
		sign_in();
	}
}

void Devoma::kernel::sign_in()
{
	std::string login, password;
	std::cout << "Enter login: "; std::cin >> login;
	std::cout << "Enter password: "; std::cin >> password;
	try
	{
		Devoma::account_base* account = DataBaseAccount->authorization(login, password);
		interface_account(account);
	}
	catch (Devoma::error er)
	{
		std::cout << "--Repeat please--" << std::endl;
		sign_in();
	}
}

void Devoma::kernel::interface_account(Devoma::account_base* account)
{
	while (true)
	{
		std::cout << "************" << "Welcome to BookStore " << account->ret_name() << "**************" << std::endl;
		std::cout << "(1)-Look catalog book-" << std::endl;
		std::cout << "(2)-Find book-" << std::endl;
		std::cout << "(3)-Show profile-" << std::endl;
		std::cout << "(4)-Exit-" << std::endl;
		char choise{ 'a' };
		std::cout << "What do you want: ";
		std::cin >> choise;
		switch (choise)
		{
		case '1':
		{
			DataBaseBook->show_database();
			break;
		}
		case '2':
		{
			DataBaseBook->search_book();
			break;
		}
		case '3':
		{
			interface_profile(account);
			break;
		}
		case 'e':
		{
			exit(0);
		}
		default:
		{
			std::cout << "Don't correct enter. Repeat" << std::endl;
			interface_account(account);
		}
		}
	}
}

void Devoma::kernel::interface_profile(Devoma::account_base* account)
{
	std::cout << "(1)-Change name-" << std::endl;
	std::cout << "(2)-Change family-" << std::endl;
	std::cout << "(3)-Change phonenumber-" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "(4)-Change password-" << std::endl;
	//std::cout << "(5)-Change login-" << std::endl;
	char choise{ 'a' };
	std::cin >> choise;
	switch (choise)
	{
	case '1':
	{
		account->set_name();
		break;
	}
	case '2':
	{
		account->set_family();
		break;
	}
	case '3':
	{
		account->set_phonenumber();
		break;
	}
	case '4':
	{
		account->set_login();
		break;
	}
	default:
	{
		std::cout << "Don't correct enter. Repeat" << std::endl;
		interface_profile(account);
	}
	}
}