#include "Contact.hpp"

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

std::string	Contact::getSecret()
{
	return (this->darkestSecret);
}

std::string	Contact::getNumber()
{
	return (this->phoneNumber);
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

void	Contact::setSecret(std::string str)
{
	this->darkestSecret = str;
}

void	Contact::setNumber(std::string str)
{
	this->phoneNumber = str;
}
