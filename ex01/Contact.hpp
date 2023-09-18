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
  		//int			phoneNumber;
		std::string	DarkestSecret;
	public:
		std::string	getFirst();
		std::string	getLast();
		std::string	getNick();
		void		setFirst(std::string);
		void		setLast(std::string);
		void		setNick(std::string);
	//std::string printWord(std::string str);
};

#endif