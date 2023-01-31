#include "Contact.hpp"

Contact::Contact()
{
	this->filled = 0;
}

void	Contact::setFname(std::string fname)
{
	this->FirstName = fname;
}
void	Contact::setLname(std::string lname)
{
	this->LastName = lname;
}
void	Contact::setNname(std::string nname)
{
	this->NickName = nname;
}
void	Contact::setnum(std::string num)
{
	this->number = num;
}
void	Contact::setsec(std::string sec)
{
	this->secret = sec;
}
std::string Contact::getFname()
{
	return (this->FirstName);
}
std::string Contact::getLname()
{
	return (this->LastName);
}
std::string Contact::getNname()
{
	return (this->NickName);
}
std::string Contact::getnum()
{
	return (this->number);
}
std::string Contact::getsec()
{
	return (this->secret);
}