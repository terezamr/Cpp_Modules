#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iomanip>

int	PhoneBook::getCurrent()
{
	return (this->current);
}

void	PhoneBook::setCurrent(int a)
{
	this->current = a;
}

void	PhoneBook::addContact(int current)
{
	Contact	ct;
	std::string str;
	std::cout << "First Name: ";
	std::cin >> str;
	ct[current].setFirst(str);
	// std::cout << "Last Name: ";
	// std::cin >> ct[current].lastName;
	// std::cout << "Nickname: ";
	// std::cin >> ct[current].nickName;
}

void	PhoneBook::searchContact()
{
	int f = 0;
	std::cout << std::right;
	while (!ct[f].firstName.empty())
	{
		std::cout <<
			std::setw(10) << f << std::setw(1) << "|" << std::setw(1) << std::setw(10) <<
			printWord(ct[f].firstName) << std::setw(1) << "|" << std::setw(10) <<
			printWord(ct[f].lastName) << std::setw(1) << "|"  << std::setw(10) <<
			printWord(ct[f].nickName) << '\n';
		f++;
	}
}

std::string PhoneBook::printWord(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	main(void)
{
	PhoneBook book;
	std::string com;
	std::cout << "> ";
	std::cin >> com;
	book.setCurrent(0);
	while (com != "EXIT")
	{
		if (com == "ADD")
		{
			book.addContact(book.getCurrent);
			book.setCurrent(book.getCurrent() + 1);
			if (book.getCurrent() == 8)
				book.setCurrent(0);
			std::cout << "Contact added!\n\n";
		}
		else if (com == "SEARCH")
			book.searchContact();
		else if (com == "EXIT")
			break ;
		else
			std::cout << "Not a valid command\n";
		std::cout << "> ";
		std::cin >> com;
	}
	std::cout << "Exiting...\n";
	return (0);
}
