#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact ct[8];
		int		current;
	public:
		int		getCurrent();
		void	setCurrent(int a);
		void	addContact(int current);
		void	searchContact();
		std::string printWord(std::string str);
};

#endif