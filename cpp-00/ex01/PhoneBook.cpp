#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
}

void display_search()
{
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

std::string	Layout(std::string str)
{
	if (str.length() > 10)
	{
		std::string cut = str;
		cut.resize(8);
		cut.append(".");
		return (cut);
	}
	return (str);
}

void	PhoneBook::contact_info(int n)
{
	std::cout <<"Name: " << contacts[n].getFname() << " ";
	std::cout << contacts[n].getLname() << std::endl;
	std::cout << "Nickname: " << contacts[n].getNname() << std::endl;
	std::cout << "Phone number: " << contacts[n].getnum() << std::endl;
	std::cout << "Secret: " << contacts[n].getsec() << std::endl;

}
void PhoneBook::print_contacts()
{
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].filled == 1)
		{
			std::cout << std::right << "|" << std::setw(10) << i << "|";
			std::cout << std::right << std::setw(10) << Layout(contacts[i].getFname()) << "|";
			std::cout << std::right << std::setw(10) << Layout(contacts[i].getLname()) << "|";
			std::cout << std::right << std::setw(10) << Layout(contacts[i].getNname()) << "|"<<std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;
		}
	}
}

void	PhoneBook::read_line()
{
	std::string line;
	int i = 0;

	while (1)
	{
		std::cout << "Choose one of the following options:" << std::endl;
		std::cout << "1- ADD: Add a new contact" << std::endl;
		std::cout << "2- SEARCH: Search for contacts" << std::endl;
		std::cout << "3- EXIT: Exit the program" << std::endl;
		std::getline(std::cin, line);
		if (line == "EXIT")
			break;
		if (line == "ADD")
		{
			std::string temp = "";
			do
			{
				std::cout << "Please enter the first name of the contact: " << std::endl;
				std::getline(std::cin, temp);
			}while (temp.size() < 1);
			contacts[i].setFname(temp);
			do
			{
			std::cout << "Please enter the last name of the contact: " << std::endl;
			std::getline(std::cin, temp);
			}while (temp.size() < 1);
			contacts[i].setLname(temp);
			do
			{
			std::cout << "Please enter the nickname of the contact: " << std::endl;
			std::getline(std::cin, temp);
			}while(temp.size() < 1);
			contacts[i].setNname(temp);
			do
			{
			std::cout << "Please enter the phone number of the contact: " << std::endl;
			std::getline(std::cin, temp);
			}while(temp.size() < 1);
			contacts[i].setnum(temp);
			do
			{
			std::cout << "Please enter the darkest secret of the contact: " << std::endl;
			std::getline(std::cin, temp);
			} while (temp.size() < 1);
			contacts[i].setsec(temp);
			contacts[i].filled = 1;
			i = (i + 1) % 8;
			if (size < 7)
				size++;
			std::cout << "Added contact successfully!" << size << std::endl;
		}
		else if (line == "SEARCH")
		{
			std::string index;
			display_search();
			print_contacts();
			std::cout << "Please enter 1 to see the user information, or enter 0 to go back to previous menu." << std::endl;
			std::getline(std::cin, index);
			if (index == "1")
			{
				std::cout << "Please enter the index of the contact you want to see." << std::endl;
				std::getline(std::cin, index);
				if (std::isdigit(index[0]) == 0)
				{
					std::cout << "Please enter a valid index." << std::endl;
					continue;
				}
				int n = std::stoi(index, NULL, 10);
				if (n < 0 || n >= size)
					std::cout << "Please enter an index that is in range." << std::endl;
				else
					contact_info(n);
			}
			else if (index == "0")
				continue;
			else
				std::cout << "Invalid entry back to menu" << std::endl;
		}
		else
			std::cout << "Please enter a valid option." << std::endl;
	}
}

int main()
{
	PhoneBook obj;
	obj.read_line();
}
