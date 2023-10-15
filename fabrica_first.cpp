#include "fabrica_first.h"

Devoma::book_base *Devoma::fabrica_first::create_standart_book(std::string NB, std::string NA, std::string FA, std::string P, int PR, int NL)
{
	book_base* ptr = new  book(NB, NA, FA, P, PR, NL);
	return ptr;
}