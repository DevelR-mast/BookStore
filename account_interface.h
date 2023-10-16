#pragma once


namespace Devoma
{
	class account_base
	{
	public:
		virtual ~account_base() = default;
	public:
		virtual void set_login() = 0;
		virtual void set_password() = 0;
		virtual void set_name() = 0;
		virtual void set_family() = 0;
		virtual void set_phonenumber() = 0;
		virtual void show_data() const = 0;
	public:
		virtual std::string ret_login() const = 0;
		virtual std::string ret_password() const = 0;
		virtual std::string ret_name() const = 0;
		virtual std::string ret_family() const = 0;
		virtual std::string ret_phonenumber() const = 0;
	};
}