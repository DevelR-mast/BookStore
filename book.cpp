#include "book.h"

Devoma::book::book(std::string Name_book, std::string Name_author, std::string Family_author, std::string Publicsher, int Price, int Num_List)
	: book_name{ Name_book }, author_name{ Name_author }, author_family{ Family_author }, publisher{ Publicsher }, price{ Price }, number_list{ Num_List } {};

void Devoma::book::show_data() const
{
	std::cout << "______Information about book______" << std::endl;
	std::cout << "Name book: " << book_name << std::endl;
	std::cout << "Author: " << author_name << " " << author_family << std::endl;
	std::cout << "Publisher: " << publisher << std::endl;
	std::cout << "Price: " << price << " RUB" << std::endl;
	std::cout << "Number list: " << number_list << std::endl;
}

void Devoma::book::set_name_author()
{
	std::cout << "Enter new name author: " << std::endl;
	std::cin >> author_name;
}

void Devoma::book::set_family_author()
{
	std::cout << "Enter new family author: ";
	std::cin >> author_family;
}

void Devoma::book::set_number_list()
{
	std::cout << "Enter new number list: ";
	std::cin >> number_list;
}

void Devoma::book::set_price()
{
	std::cout << "Enter new price from book: ";
	std::cin >> price;
}

void Devoma::book::set_publisher()
{
	std::cout << "Enter new publisher: ";
	std::cin >> publisher;
}

//////////////////////////////////////////////////////////////////////////////

std::string Devoma::book::ret_name_book()		const { return book_name; }

std::string Devoma::book::ret_name_author()		const { return author_name; }

std::string Devoma::book::ret_family_author()	const { return author_family; }

std::string Devoma::book::ret_publisher()		const { return publisher; }

int Devoma::book::ret_price()					const { return price; }

int Devoma::book::ret_number_list()				const { return number_list; }