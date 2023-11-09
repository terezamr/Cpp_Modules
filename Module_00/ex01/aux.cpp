#include "PhoneBook.hpp"

std::string cutWord(std::string str)
{
	if (str.size() >= 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int	check_number(std::string str)
{
	int	j = str.length();
	for (int i = 0; i < j; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
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

void	cleanContact(Contact* ct, int current)
{
	ct[current].setFirst("");
	ct[current].setLast("");
	ct[current].setNick("");
	ct[current].setSecret("");
	ct[current].setNumber("");
}
