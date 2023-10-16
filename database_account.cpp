#include "database_account.h"

Devoma::database_account::database_account()
{
	std::string Login {}, Password {}, Name {}, Family {}, Phonenumber {};
	file_account.open(FILEACCOUNT, std::ios::app);

	Devoma::abstaract_fabrica_account* fabrica = new Devoma::fabrica_account{};

	while (!file_account.eof())
	{
		file_account >> Login; file_account >> Password; file_account >> Name; file_account >> Family; file_account >> Phonenumber;
		container_account.push_back(fabrica->create_account(Login, Password, Name, Family, Phonenumber));
	}
	file_account.close();
}

void Devoma::database_account::checkup_login(std::string Login) const
{
	for (auto account : container_account)
	{
		if (account->ret_login() != Login) { continue; }
		else throw Error{};
	}
}

void Devoma::database_account::add_account()
{
	std::string Login{}, Password{}, Name{}, Family{}, Phonenumber{};
	std::cout << "Enter Login: "; std::cin >> Login;
	std::cout << "Enter Password: "; std::cin >> Password;
	std::cout << "Enter Name: "; std::cin >> Name;
	std::cout << "Enter Family: "; std::cin >> Family;
	std::cout << "Enter PhoneNumber: "; std::cin >> Phonenumber;
	try
	{
		checkup_login(Login);
		Devoma::abstaract_fabrica_account* fabrica = new Devoma::fabrica_account{};
		container_account.push_back(fabrica->create_account(Login, Password, Name, Family, Phonenumber));
	}
	catch (database_account::Error e)
	{
		std::cout << "Can't create accoutn. Login already exists" << std::endl;
	}
}

void Devoma::database_account::add_account(std::string Login, std::string Password, std::string Name, std::string Family, std::string Phonenumber)
{
	try
	{
		checkup_login(Login);
		Devoma::abstaract_fabrica_account* fabrica = new Devoma::fabrica_account{};
		container_account.push_back(fabrica->create_account(Login, Password, Name, Family, Phonenumber));
		update_database();
	}
	catch (database_account::Error e)
	{
		std::cout << "Can't create accoutn. Login already exists" << std::endl;
	}
}

void Devoma::database_account::delete_account()
{
	std::cout << "Enter login and password account." << std::endl;
	std::string Login, Password;
	std::cout << "Enter login: ";  std::cin >> Login;
	std::cout << "Enter password: "; std::cin >> Password;
	try
	{
		checkup_login(Login);
		std::cout << "Account with that login don'y find!" << std::endl;
	}
	catch (database_account::Error e)
	{
		std::vector<account_base*>::iterator iter = container_account.begin();
		while(true)
		{
			if ((*iter)->ret_login() != Login) { ++iter;  continue; }
			else break;
		}
		container_account.erase(iter);
		update_database();
	}
}

void Devoma::database_account::find_account()
{
	char choise;
	std::cout << "Looking for login(l)/name(n)/family(f)/phonenumber(p): "; std::cin.get(choise);
	std::string message{};
	switch (choise)
	{
		case 'l':
		{
			std::cout << "Enter login: "; std::cin>>message;
			for (auto account : container_account)
			{
				if (account->ret_login() != message) { continue; }
				else { account->show_data(); }
			}
			break;
		}
		case 'n':
		{
			std::cout << "Enter name: "; std::cin >> message;
			for (auto account : container_account)
			{
				if (account->ret_name() != message) { continue; }
				else { account->show_data(); }
			}
			break;
		}
		case 'f':
		{
			std::cout << "Enter family: "; std::cin >> message;
			for (auto account : container_account)
			{
				if (account->ret_family() != message) { continue; }
				else { account->show_data(); }
			}
			break;
		}
		case 'p':
		{
			std::cout << "Enter phonenumber: "; std::cin >> message;
			for (auto account : container_account)
			{
				if (account->ret_phonenumber() != message) { continue; }
				else { account->show_data(); }
			}
			break;
		}
		default:
		{
			std::cout << "Don't correct enter. Repeat please." << std::endl;
			find_account();
		}
	}
}

void Devoma::database_account::update_database()
{
	file_account.open(FILEACCOUNT);
	file_account.clear();

	for (auto account : container_account)
	{
		file_account << account->ret_login(); file_account << " ";
		file_account << account->ret_password(); file_account << " ";
		file_account << account->ret_name(); file_account << " ";
		file_account << account->ret_family(); file_account << " ";
		file_account << account->ret_phonenumber(); file_account << " ";
	}
	file_account.close();
}