#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}
Brain::Brain(Brain const & src){
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = src;
}
Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}
Brain &Brain::operator=(Brain const & copy){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.getIdea(i);
	return *this;
}
std::string Brain::getIdea(int i) const{
	return this->ideas[i];
}
void Brain::setIdea(int i, std::string idea){
	this->ideas[i] = idea;
}