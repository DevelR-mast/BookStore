#pragma once
#include "abstract_fabrica_book.h"
#include "book.h"

namespace Devoma
{
	class fabrica_first: public abstract_fabrica_book
	{
	public:
		~fabrica_first() = default;
	public:
		book_base *create_standart_book() override;
	};
}