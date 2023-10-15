#pragma once
#include <string>
#include <iostream>
#include "book_interface.h"

namespace Devoma
{
	class book : public book_base
	{
	private:
		std::string book_name;
		std::string author_name;
		std::string author_family;
		std::string publisher;
		int price;
		int number_list;
	public:
		book(std::string NB, std::string NA, std::string FA, std::string P, int PR, int NL);
		~book() = default;
	public:
		void show_data() const override;
		void set_name_author() override;
		void set_family_author() override;
		void set_price() override;
		void set_number_list() override;
		void set_publisher() override;
	public:
		std::string ret_name_book() const override;
		std::string ret_name_author() const override;
		std::string ret_family_author() const override;
		std::string ret_publisher() const override;
		int ret_price() const override;
		int ret_number_list() const override;
	};
}