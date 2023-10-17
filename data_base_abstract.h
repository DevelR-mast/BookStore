#pragma once

namespace Devoma
{
	class data_base_abstract
	{
	public:
		virtual ~data_base_abstract() {};
	public:
		virtual void add_book() = 0;
		virtual void delete_book() = 0;
		virtual void show_database() const = 0;
		virtual void search_book() const = 0;
	};
}