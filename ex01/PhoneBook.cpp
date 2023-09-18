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

std::string PhoneBook::cutWord(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	PhoneBook::addContact(int current)
{
	std::cin.ignore();
	std::string str;
	std::cout << "First Name: ";
    getline(std::cin, str);
	ct[current].setFirst(cutWord(str));

	std::cout << "Last Name: ";
    getline(std::cin, str);
	ct[current].setLast(cutWord(str));

	std::cout << "Nickname: ";
    getline(std::cin, str);
	ct[current].setNick(cutWord(str));

	if (ct[current].getFirst().empty() || ct[current].getLast().empty() || ct[current].getNick().empty())
	{
		if (!ct[current].getFirst().empty())
			ct[current].setFirst("");
		if (!ct[current].getLast().empty())
			ct[current].setLast("");
		if (!ct[current].getNick().empty())
			ct[current].setNick("");
		std::cout << "Contacted not added. Please make sure you fill all parameters.\n\n";
		return (1);
	}
	else
	{
		std::cout << "Contact added!\n\n";
		return (0);
	}
}

int	PhoneBook::searchIndex()
{
	int	id;
	std::cout << std::right;
	std::cout << "Index of the contact: ";
    std::cin >> id;
	if (id >= 8 || id < 0 || ct[id].getFirst().empty())
		return (-1);
	return (id);
}

void	PhoneBook::searchContact()
{
	int f = 0;
	int	id;
	std::cout << std::right;
	if (ct[f].getFirst().empty())
		return ;
	while (!ct[f].getFirst().empty())
	{
		std::cout <<
			std::setw(10) << f << std::setw(1) << "|" << std::setw(1) << std::setw(10) <<
			ct[f].getFirst() << std::setw(1) << "|" << std::setw(10) <<
			ct[f].getLast() << std::setw(1) << "|"  << std::setw(10) <<
			ct[f].getNick() << '\n';
		f++;
	}
	id = searchIndex();
	while (id == -1)
	{
		std::cout << "Index out of range\n\n";
		id = searchIndex();
	}
	std::cout << "Index: " << id << "\n";
	std::cout << "First Name: " << ct[id].getFirst() << "\n";
	std::cout << "Last Name: " << ct[id].getLast() << "\n";
	std::cout << "Nickname: " << ct[id].getNick() << "\n";
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
			std::cout << "Not a valid command\n";
		std::cout << "> ";
		std::cin >> com;
	}
	std::cout << "Exiting...\n";
	return (0);
}
