#pragma once
#include "data_base_abstract.h"
#include "fabrica_first.h"
#include "error.h"

#include <fstream>
#include <unordered_map>
#include <vector>

constexpr auto NAMEFILE = "data_base.txt";

namespace Devoma
{
	class data_base_file : public data_base_abstract
	{
	private:
		std::fstream file;
		std::unordered_map<std::string, int> container_product;
		std::vector<book_base*> container_book;
	private:
		void update_file();
		void chekup_book(std::string NB) const;
	public:
		data_base_file();
		~data_base_file();
	public:
		void add_book() override;
		void delete_book() override;
		void show_database() const override;
		void search_book() const override;
	};
}