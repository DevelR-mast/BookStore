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