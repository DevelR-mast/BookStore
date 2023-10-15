#pragma once
#include "account_interface.h"
#include <string>
#include <iostream>

namespace Devoma
{
	class account_user : public account_base
	{
	private:
		std::string login, password;
		std::string name, family;
		std::string phonenumber;
	public:
		account_user(std::string Login, std::string Password, std::string Name, std::string Family, std::string Phnum);
		~account_user() = default;
	public:
		void set_login() override;
		void set_password() override;
		void set_name() override;
		void set_family() override;
		void set_phonenumber() override;
	};
}