#include "fabrica_account.h"

Devoma::account_base* Devoma::fabrica_account::create_account(std::string Login, std::string Password, std::string Name, std::string Family, std::string PhoneNumber)
{
	return new account_user{ Login, Password, Name, Family, PhoneNumber };
}