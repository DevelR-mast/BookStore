#pragma once
#include <string>

namespace Devoma
{
	class book_base
	{
	public:
		virtual ~book_base() = default;
	public:
		virtual void show_data() const = 0;
		virtual void set_name_author() = 0;
		virtual void set_family_author() = 0;
		virtual void set_price() = 0;
		virtual void set_number_list() = 0;
		virtual void set_publisher() = 0;
	public:
		virtual std::string ret_name_book() const = 0;
		virtual std::string ret_name_author() const = 0;
		virtual std::string ret_family_author() const = 0;
		virtual std::string ret_publisher() const = 0;
		virtual int ret_price() const = 0;
		virtual int ret_number_list() const = 0;
	};
}