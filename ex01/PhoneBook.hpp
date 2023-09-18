#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact ct[8];
		int		current;

		std::string nome;

	public:
		int			addContact(int current);
		int			getCurrent();
		void		setCurrent(int a);
		void		searchContact();
		int			searchIndex();
		std::string cutWord(std::string str);
};

#endif
