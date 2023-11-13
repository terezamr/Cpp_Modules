#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

int	main(void)
{
	PhoneBook book;
	std::string com;
	std::cout << "Please insert one of the following commands: ADD, SEARCH or EXIT.\n> ";
	getline(std::cin, com);
	book.setCurrent(0);
	com = trimSpaces(com);
	while (com != "EXIT")
	{
		if (com == "ADD")
		{
			if (book.addContact(book.getCurrent()) == 0)
			{
				book.setCurrent(book.getCurrent() + 1);
				if (book.getCurrent() == 8)
					book.setCurrent(0);
			}
		}
		else if (com == "SEARCH")
			book.searchContact();
		else if (com == "EXIT")
			break ;
		else
			std::cout << "Not a valid command.\n" << std::endl;

		std::cout << "> ";
		getline(std::cin, com);
		com = trimSpaces(com);
	}
	std::cout << "Exiting...\n" << std::endl;
	return (0);
}
