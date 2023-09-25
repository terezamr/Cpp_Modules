#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
  		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		std::string	getFirst();
		std::string	getLast();
		std::string	getNick();
		std::string	getSecret();
		std::string	getNumber();
		void		setFirst(std::string);
		void		setLast(std::string);
		void		setNick(std::string);
		void		setSecret(std::string);
		void		setNumber(std::string);
};

#endif