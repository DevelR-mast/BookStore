#pragma once
#include "book_interface.h"
#include <iostream>
#include <string>

namespace Devoma
{
	class abstract_fabrica_book
	{
	public:
		virtual ~abstract_fabrica_book() = default;
	public:
		virtual book_base *create_standart_book() = 0;
	};
}