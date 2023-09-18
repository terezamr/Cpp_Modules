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

std::string	Contact::setFirst(std::string str)
{
	this->firstName = str;
}
