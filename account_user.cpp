#include "account_user.h"

Devoma::account_user::account_user(std::string Login, std::string Password, std::string Name, std::string Family, std::string Phnum)
	: login{ Login }, password{ Password }, name{ Name }, family{ Family }, phonenumber{ Phnum } {}

void Devoma::account_user::set_family()
{
	std::cout << "Enter new family: "; std::cin >> family;
}

void Devoma::account_user::set_name()
{
	std::cout << "Enter new name: "; std::cin >> name;
}

void Devoma::account_user::set_login()
{
	std::cout << "Enter new login: "; std::cin >> login;
}

void Devoma::account_user::set_password()
{
	std::cout << "Enter new password: "; std::cin >> password;
}

void Devoma::account_user::set_phonenumber()
{
	std::cout << "Enter new phone number :"; std::cin >> phonenumber;
}

void Devoma::account_user::show_data() const
{
	std::cout << "**********Account data************" << std::endl;
	std::cout << "Login: " << login << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Family: " << family << std::endl;
	std::cout << "Phonenumber: " << phonenumber << std::endl;
	std::cout << "***********************************" << std::endl;
}

/////////////////////////////////////////////////////////////

std::string Devoma::account_user::ret_login() const { return login; }

std::string Devoma::account_user::ret_password() const { return password; }

std::string Devoma::account_user::ret_name() const { return name; }

std::string Devoma::account_user::ret_family() const { return family; }

std::string Devoma::account_user::ret_phonenumber() const { return phonenumber; }