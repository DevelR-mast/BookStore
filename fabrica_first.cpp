#include "fabrica_first.h"

Devoma::book_base *Devoma::fabrica_first::create_standart_book()
{
	std::string NameBook;
	std::cout << "Enter name book: "; std::cin >> NameBook;
	std::string NameAuthor;
	std::cout << "Enter name author: "; std::cin >> NameAuthor;
	std::string FamilyAuthor;
	std::cout << "Enter family author: "; std::cin >> FamilyAuthor;
	std::string Publisher;
	std::cout << "Enter publisher: "; std::cin >> Publisher;
	int Price, NumberList;
	std::cout << "Enter price: "; std::cin >> Price;
	std::cout << "Enter number list: "; std::cin >> NumberList;
	book_base* ptr = new  book(NameBook, NameAuthor, FamilyAuthor, Publisher, Price, NumberList);
	return ptr;
}