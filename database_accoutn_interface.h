#pragma once
#include <string>

#define FILEACCOUNT "database_account.txt"

namespace Devoma
{
	class database_account_interface
	{
	public:
		virtual ~database_account_interface() = default;
	public:
		virtual void add_account() = 0;
		virtual void add_account(std::string L, std::string P, std::string N, std::string F, std::string PN) = 0;
		virtual void delete_account() = 0;
		virtual void find_account() = 0;
	};
}