#include "PhoneBook.hpp"

int	PhoneBook::getCurrent()
{
	return (this->current);
}

void	PhoneBook::setCurrent(int a)
{
	this->current = a;
}

int	PhoneBook::addContact(int current)
{
	std::string str;

	std::cout << "First Name: ";
	ct[current].setFirst("");
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Please enter a non empty parameter.\n" << std::endl;
		return 1;
	}
	else
		ct[current].setFirst(trimSpaces(str));

	ct[current].setLast("");
	std::cout << "Last Name: ";
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Please enter a non empty parameter.\n" << std::endl;
		cleanContact(ct, current);
		return 1;
	}
	else
		ct[current].setLast(trimSpaces(str));
	
	ct[current].setNick("");
	std::cout << "Nickname: ";
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Please enter a non empty parameter.\n" << std::endl;
		cleanContact(ct, current);
		return 1;
	}
	else
		ct[current].setNick(trimSpaces(str));

	ct[current].setSecret("");
	std::cout << "Darkest Secret: ";
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "Please enter a non empty parameter.\n" << std::endl;
		cleanContact(ct, current);
		return 1;
	}
	else
		ct[current].setSecret(trimSpaces(str));
	
	ct[current].setNumber("");
	std::cout << "Phone Number: ";
	getline(std::cin, str);
	if (str.empty())
	{
		cleanContact(ct, current);
		std::cout << "Please enter a non empty parameter.\n" << std::endl;
		return 1;
	}
	else if (check_number(trimSpaces(str)) == 0)
	{
		cleanContact(ct, current);
		std::cout << "Please enter valid number.\n" << std::endl;
		return 1;
	}
	else
		ct[current].setNumber(trimSpaces(str));

	std::cout << "Contact added!\n\n";
	return (0);
}

void	PhoneBook::searchContact()
{
	int f = 1;
	std::cout << std::right;
	if (ct[f - 1].getFirst().empty())
		return ;
	while (f <= 8 && !ct[f - 1].getFirst().empty())
	{
		std::cout <<
			std::setw(10) << f << std::setw(1) << "|" << std::setw(1) << std::setw(10) <<
			cutWord(ct[f - 1].getFirst()) << std::setw(1) << "|" << std::setw(10) <<
			cutWord(ct[f - 1].getLast()) << std::setw(1) << "|"  << std::setw(10) <<
			cutWord(ct[f - 1].getNick()) << std::endl << std::endl;
		f++;
	}

	std::string nb;
	std::cout << "Index of the contact: ";
	getline(std::cin, nb);
	if (check_number(trimSpaces(nb)) == 0)
	{
		std::cout << "Please enter valid number.\n" << std::endl;
		return ;
	}

    const char *z = nb.c_str();
    int id = std::atoi(z);
    if (id < 1 || id > 8)
        std::cout << "You inserted an index out of bounds.\n" << std::endl;
	else if (!ct[id - 1].getFirst().empty())
	{
		std::cout << "\nIndex: " << id << std::endl;
		std::cout << "First Name: " << ct[id - 1].getFirst() << std::endl;
		std::cout << "Last Name: " << ct[id - 1].getLast() << std::endl;
		std::cout << "Nickname: " << ct[id - 1].getNick() << std::endl;
		std::cout << "Darkest Secret: " << ct[id - 1].getSecret() << std::endl;
		std::cout << "Phone Number: " << ct[id - 1].getNumber() << std::endl << std::endl;
	}
	else
		std::cout << "This contact doesn't exist.\n" << std::endl;
}
