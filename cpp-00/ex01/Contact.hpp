#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string number;
		std::string secret;

	public:
		int filled;
		Contact();
		void	setFname(std::string Fname);
		void	setLname(std::string Lname);
		void	setNname(std::string Nname);
		void	setnum(std::string num);
		void	setsec(std::string sec);
		std::string getFname();
		std::string getLname();
		std::string getNname();
		std::string getnum();
		std::string getsec();
};

#endif