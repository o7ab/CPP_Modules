#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
	private:
		Contact contacts[8];
	public:
		int size;
		PhoneBook();
		void	read_line();
		void	print_contacts();
		void	contact_info(int n);
};

#endif