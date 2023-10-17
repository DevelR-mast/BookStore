#include "data_base.h"

Devoma::data_base_file::data_base_file() : file{NAMEFILE} 
{
	std::string NameBook{}, NameAuthor{}, FamilyAuthor{}, Publisher{};
	int Price, NumberList, CountBook;

	Devoma::abstract_fabrica_book* fabrica = new Devoma::fabrica_first{};

	while (!file.eof())
	{
		file >> NameBook; file >> NameAuthor; file >> FamilyAuthor; file >> Publisher;
		file >> Price; file >> NumberList; file >> CountBook;
		container_book.push_back( fabrica->create_standart_book( NameBook, NameAuthor, FamilyAuthor, Publisher, Price, NumberList ));
		container_product[NameBook] = CountBook;
	}
	file.close();
}

Devoma::data_base_file::~data_base_file() {}

void Devoma::data_base_file::add_book()
{
	Devoma::abstract_fabrica_book* fabrica = new Devoma::fabrica_first{};

	std::string NameBook{}, NameAuthor{}, FamilyAuthor{}, Publisher{};
	int Price{}, NumberList{}, CountBook{};
	std::cout << "Enter Name Book: "; std::cin >> NameBook;
	std::cout << "Enter Name Author: "; std::cin >> NameAuthor;
	std::cout << "Enter Family Author: "; std::cin >> FamilyAuthor;
	std::cout << "Enter Publisher: "; std::cin >> Publisher;
	std::cout << "Enter Price: "; std::cin >> Price;
	std::cout << "Enter Numbert List: "; std::cin >> NumberList;
	std::cout << "Enter Count Book: "; std::cin >> CountBook;

	try
	{
		chekup_book(NameBook);
		container_book.push_back( fabrica->create_standart_book( NameBook, NameAuthor, FamilyAuthor, Publisher, Price, NumberList ));
		container_product[NameBook] = CountBook;
	}
	catch (Devoma::error Error)
	{
		std::cout << "Book can't create. She already exists";
	}
	update_file();
}

void Devoma::data_base_file::delete_book()
{
	std::cout << "Enter NameBook: ";
	std::string namebook;
	std::cin >> namebook;
	try
	{
		chekup_book(namebook);
		container_product[namebook] = 0;
		update_file();
	}
	catch (Devoma::error er)
	{
		std::cout << "You can't delete that book. Her don'y have" << std::endl;
	}
}

void Devoma::data_base_file::chekup_book(std::string NameBook) const
{
	for (auto book : container_product)
	{
		if (book.first != NameBook) { continue; }
		else { throw error{}; }
	}
}

void Devoma::data_base_file::show_database() const
{
	std::cout << "\t___Catalog book___" << std::endl;
	for (auto book : container_book)
	{
		book->show_data();
		std::cout << "Count: " << container_product.at(book->ret_name_book()) << std::endl;
	}
}

void Devoma::data_base_file::update_file()
{
	file.open(NAMEFILE);
	file.clear();

	for (auto obj : container_book)
	{
		file << obj->ret_name_book() << " ";
		file << obj->ret_name_author() << " ";
		file << obj->ret_family_author() << " ";
		file << obj->ret_publisher() << " ";
		file << obj->ret_price() << " ";
		file << obj->ret_number_list() << " ";
		file << container_product.at(obj->ret_name_book()) << " ";
	}
}

void Devoma::data_base_file::search_book() const
{
	std::cout << "How are we going search?" << std::endl;
	std::cout << "(1)NameBook | (2)NameAuthor | (3)Publisher" << std::endl;
	std::cout << "(e) Exit" << std::endl;
	char choise{ 'a' };
	std::string message {};
	switch (choise)
	{
	case '1':
	{
		std::cout << "Enter NameBook: "; std::cin >> message;
		for (auto book : container_book)
		{
			if (book->ret_name_book() != message) { continue; }
			else
			{
				book->show_data();
				std::cout << "Count: " << container_product.at(book->ret_name_book()) << std::endl;
			}
		}
		break;
	}
	case '2':
	{
		std::cout << "Enter NameAuthor: "; std::cin >> message;
		for (auto book : container_book)
		{
			if (book->ret_name_book() != message) { continue; }
			else
			{
				book->show_data();
				std::cout << "Count: " << container_product.at(book->ret_name_book()) << std::endl;
			}
		}
		break;
	}
	case '3':
	{
		std::cout << "Enter Publisher: "; std::cin >> message;
		for (auto book : container_book)
		{
			if (book->ret_name_book() != message) { continue; }
			else
			{
				book->show_data();
				std::cout << "Count: " << container_product.at(book->ret_name_book()) << std::endl;
			}
		}
		break;
	}
	case 'e':
	{
		break;
	}
	default:
	{
		std::cout << "Dont correct enter. Repeat." << std::endl;
		search_book();
	}
	}
}