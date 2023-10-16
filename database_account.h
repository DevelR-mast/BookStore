#pragma once
#include <iostream>
#include <vector>
#include <fstream>

#include "account_interface.h"
#include "database_accoutn_interface.h"
#include "fabrica_account.h"

namespace Devoma
{
	class database_account : public database_account_interface
	{
	private:
		std::fstream file_account;
		std::vector<Devoma::account_base*> container_account;
		class Error{};
	private:
		void update_database();
		void checkup_login(std::string Login) const;
	public:
		database_account();
		~database_account() = default;
	public:
		void add_account() override;
		void add_account(std::string Login, std::string Password, std::string Name, std::string Family, std::string PhoneNumber) override;
		void delete_account() override;
		void find_account() override;
	};
}