#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Contact {
	private:
		std::string	firstName;
	public:
		std::string	lastName;
		std::string	nickName;
  		int			phoneNumber;
		std::string	DarkestSecret;
		std::string	getFirst();
		std::string	setFirst();
	//std::string printWord(std::string str);
};

#endif