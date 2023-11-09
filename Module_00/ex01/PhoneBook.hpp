#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
	private:
		Contact		ct[8];
		int			current;
	public:
		int			getCurrent();
		void		setCurrent(int a);

		int			addContact(int current);
		void		searchContact();
};

std::string	cutWord(std::string str);
int			check_number(std::string str);
std::string	trimSpaces(std::string str);
void		cleanContact(Contact* ct, int current);
#endif
