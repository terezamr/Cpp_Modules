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

std::string	check_number(std::string str)
{
	int	j = str.length();
	for (int i = 0; i < j; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return ("");
	}
	return (str);
}

std::string	trimSpaces(std::string str)
{
	std::string spaces = " \n\r\t\f\v";
	int	i = str.find_first_not_of(spaces);
	str = str.erase(0, i);

	int j = str.find_last_not_of(spaces) + 1;
	str = str.erase(j);
	return (str);
}

int	PhoneBook::addContact(int current)
{
	std::cin.ignore();
	std::string str;

	std::cout << "First Name: ";
	ct[current].setFirst("");
	while (ct[current].getFirst().empty())
	{
		getline(std::cin, str);
		if (str.empty())
			std::cout << "Please enter a non empty parameter.\n\nFirst Name: ";
		else
			ct[current].setFirst(trimSpaces(str));
	}

	ct[current].setLast("");
	std::cout << "Last Name: ";
	while (ct[current].getLast().empty())
	{
		getline(std::cin, str);
		if (str.empty())
			std::cout << "Please enter a non empty parameter.\n\nLast Name: ";
		else
			ct[current].setLast(trimSpaces(str));
	}
	
	ct[current].setNick("");
	std::cout << "Nickname: ";
	while (ct[current].getNick().empty())
	{
		getline(std::cin, str);
		if (str.empty())
			std::cout << "Please enter a non empty parameter.\n\nNickname: ";
		else
			ct[current].setNick(trimSpaces(str));
	}

	ct[current].setSecret("");
	std::cout << "Darkest Secret: ";
	while (ct[current].getSecret().empty())
	{
		getline(std::cin, str);
		if (str.empty())
			std::cout << "Please enter a non empty parameter.\n\nDarkest Secret: ";
		else
			ct[current].setSecret(trimSpaces(str));;
	}

	ct[current].setNumber("");
	std::cout << "Phone Number: ";
	while (ct[current].getNumber().empty())
	{
		getline(std::cin, str);
		if (str.empty())
			std::cout << "Please enter a non empty parameter.\n\nPhone Number: ";
		else if (!str.empty() && check_number(trimSpaces(str)) == "")
		{
			ct[current].setNumber("");
			std::cout << "Please enter valid number.\n\nPhone Number: \n";
		}
		else
			ct[current].setNumber(trimSpaces(str));
	}
	std::cout << "Contact added!\n\n";
	return (0);
}

void	PhoneBook::searchContact()
{
	int f = 1;
	std::cout << std::right;
	if (ct[f].getFirst().empty())
		return ;
	while (f <= 8 && !ct[f].getFirst().empty())
	{
		std::cout <<
			std::setw(10) << f << std::setw(1) << "|" << std::setw(1) << std::setw(10) <<
			cutWord(ct[f].getFirst()) << std::setw(1) << "|" << std::setw(10) <<
			cutWord(ct[f].getLast()) << std::setw(1) << "|"  << std::setw(10) <<
			cutWord(ct[f].getNick()) << '\n';
		f++;
	}
	int id;
	std::string error;
	std::cout << "Index of the contact: ";
	std::cin >> error;
    const char *z = error.c_str();
    id = std::atoi(z);
    if (id < 1 || id > 8)
        std::cout << "You inserted an index out of bounds" << std::endl;
	else if (!ct[id].getFirst().empty())
	{
		std::cout << "Index: " << id << std::endl;
		std::cout << "First Name: " << ct[id].getFirst() << std::endl;
		std::cout << "Last Name: " << ct[id].getLast() << std::endl;
		std::cout << "Nickname: " << ct[id].getNick() << std::endl;
		std::cout << "Darkest Secret: " << ct[id].getSecret() << std::endl;
		std::cout << "Phone Number: " << ct[id].getNumber() << std::endl;
	}
	else
		std::cout << "This contact doesn't exist" << std::endl;
}
