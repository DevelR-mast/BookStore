#pragma once
#include "account_interface.h"
#include <string>
#include <iostream>

namespace Devoma
{
	class account_admin : public account_base
	{
	private:
		std::string login, password;
		std::string name, family;
		std::string phonenumber;
	public:
		account_admin(std::string Login, std::string Password, std::string Name, std::string Family, std::string Phnum)
			:login{ Login }, password{ Password }, name{ Name }, family{ Family }, phonenumber{ Phnum } {};
		~account_admin() = default;
	private:
		void set_login() override;
		void set_password() override;
		void set_name() override;
		void set_family() override;
		void set_phonenumber() override;
		void show_data() const override;
		std::string ret_login() const override;
		std::string ret_password() const override;
		std::string ret_name() const override;
		std::string ret_family() const override;
		std::string ret_phonenumber() const override;
	};
}