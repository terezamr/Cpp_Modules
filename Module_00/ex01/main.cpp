#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

// Falta:
// testar comandos gerais com espacos (ADD)
// testar numero de telemovel invalido e index negativo

int	main(void)
{
	PhoneBook book;
	std::string com;
	std::cout << "> ";
	std::cin >> com;
	book.setCurrent(1);
	while (com != "EXIT")
	{
		if (com == "ADD")
		{
			if (book.addContact(book.getCurrent()) == 0)
			{
				book.setCurrent(book.getCurrent() + 1);
				if (book.getCurrent() == 9)
					book.setCurrent(1);
			}
		}
		else if (com == "SEARCH")
			book.searchContact();
		else if (com == "EXIT")
			break ;
		else
			std::cout << "Not a valid command.\n";
		std::cout << "> ";
		std::cin >> com;
	}
	std::cout << "Exiting...\n\n";
	return (0);
}
