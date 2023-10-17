#pragma once
#include "account_interface.h"
#include <string>

namespace Devoma
{
	class database_account_interface
	{
	public:
		virtual ~database_account_interface() = default;
	public:
		virtual account_base *add_account() = 0;
		virtual account_base *add_account(std::string L, std::string P, std::string N, std::string F, std::string PN) = 0;
		virtual void delete_account() = 0;
		virtual void find_account() = 0;
		virtual account_base* authorization(std::string L, std::string P) = 0;
	};
}