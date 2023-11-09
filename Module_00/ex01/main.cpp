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
	
	while (com != "EXIT" && com != "exit")
	{
		if (com == "ADD" || com == "add")
		{
			if (book.addContact(book.getCurrent()) == 0)
			{
				book.setCurrent(book.getCurrent() + 1);
				if (book.getCurrent() == 8)
					book.setCurrent(0);
			}
		}
		else if (com == "SEARCH" || com == "search")
			book.searchContact();
		else if (com == "EXIT" || com == "exit")
			break ;
		else
			std::cout << "Not a valid command.\n" << std::endl;

		std::cout << "> ";
		getline(std::cin, com);
	}
	std::cout << "Exiting...\n" << std::endl;
	return (0);
}
