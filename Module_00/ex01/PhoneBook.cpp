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

int	check_number(std::string str)
{
	int	i = 0;
	int j = str.length();
	while (i < j && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	PhoneBook::addContact(int current)
{
	std::cin.ignore();
	std::string str;
	std::cout << "First Name: ";
    getline(std::cin, str);
	ct[current].setFirst(str);

	std::cout << "Last Name: ";
    getline(std::cin, str);
	ct[current].setLast(str);

	std::cout << "Nickname: ";
    getline(std::cin, str);
	ct[current].setNick(str);

	std::cout << "Darkest Secret: ";
    getline(std::cin, str);
	ct[current].setSecret(str);

	std::cout << "Phone Number: ";
    getline(std::cin, str);
	if (check_number(str) == 1)
	{
		ct[current].setNumber("");
		std::cout << "Not a valid number.\n";
	}
	// else
	// {
	// 	std::cout << "Not a valid number.\n";
	// 	ct[current].setNumber("");
	// }
	if (ct[current].getFirst().empty() || ct[current].getLast().empty() || ct[current].getNick().empty() || ct[current].getSecret().empty() || ct[current].getNumber().empty())
	{
		if (!ct[current].getFirst().empty())
			ct[current].setFirst("");
		if (!ct[current].getLast().empty())
			ct[current].setLast("");
		if (!ct[current].getNick().empty())
			ct[current].setNick("");
		if (!ct[current].getSecret().empty())
			ct[current].setSecret("");
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
			cutWord(ct[f].getFirst()) << std::setw(1) << "|" << std::setw(10) <<
			cutWord(ct[f].getLast()) << std::setw(1) << "|"  << std::setw(10) <<
			cutWord(ct[f].getNick()) << '\n';
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
	std::cout << "Darkest Secret: " << ct[id].getSecret() << "\n";
}

// Falta:
// inserir numro de telemovel
// validar numero de telemovel
// validar numero do index (se se puser letras da erro)

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
	std::cout << "Exiting...\n\n";
	return (0);
}
