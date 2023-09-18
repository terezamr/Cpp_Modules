#include "Contact.hpp"

// std::string Contact::printWord(std::string str)
// {
// 	if (str.len >= 10)
// 		return (str.substr(0, 9) + ".");
// 	return (str);
// }

std::string	Contact::getFirst()
{
	return (this->firstName);
}

std::string	Contact::getLast()
{
	return (this->lastName);
}

std::string	Contact::getNick()
{
	return (this->nickName);
}

void	Contact::setFirst(std::string str)
{
	this->firstName = str;
}

void	Contact::setLast(std::string str)
{
	this->lastName = str;
}

void	Contact::setNick(std::string str)
{
	this->nickName = str;
}
