#pragma once
#include "node.h"
#include <iostream>
#include <string>

namespace Devoma
{
	class kernel final
	{
	private:
		Devoma::database_account_interface *DataBaseAccount{};
		Devoma::data_base_abstract *DataBaseBook{};
	private:
		void sign_up();
		void sign_in();
		void interface_account(Devoma::account_base* account);
		void interface_profile(Devoma::account_base* account);
	public:
		kernel();;
		~kernel();
	public:
		void start();
	};
}