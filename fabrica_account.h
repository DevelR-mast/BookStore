#pragma once
#include "account_user.h"
#include "abstract_fabrica_account.h"

namespace Devoma
{
	class fabrica_account: public abstaract_fabrica_account
	{
	public:
		fabrica_account() = default;
		~fabrica_account() = default;
	public:
		account_base* create_account(std::string Login, std::string Password, std::string Name, std::string Family, std::string PhoneNumber) override;
	};
}