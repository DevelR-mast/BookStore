#pragma once
#include "account_interface.h"

namespace Devoma
{
	class abstaract_fabrica_account
	{
	public:
		virtual ~abstaract_fabrica_account() = default;
	public:
		virtual account_base* create_account(std::string Login, std::string Password, std::string Name, std::string Family, std::string PhoneNumber) = 0;
	};
}