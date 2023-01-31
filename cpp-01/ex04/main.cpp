#include <iostream>
#include <fstream>
#include <sstream>


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (!argv[2][0] || !argv[3][0])
	{
		std::cout << "strings can't be empty" << std::endl;
		return (1);
	}
	std::string oldfile = argv[1];
	std::string oldWord = argv[2];
	std::string newWord = argv[3];
	std::ifstream input(oldfile);
	if(!input.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}
	std::string newfile = oldfile + ".replace";
	std::ofstream output(newfile);
	if(!output.is_open())
	{
		input.close();
		std::cout << "Error: file not created" << std::endl;
		return (1);
	}
	std::string line;
	size_t pos = 0;
	size_t len = oldfile.length();
	while (std::getline(input, line))
	{
		pos = 0;
		while ((pos = line.find(oldfile, pos)) != line.npos)
		{
			line.erase(pos,len);
			line.insert(pos, newWord);
			pos = pos + newWord.length();
		}
		output << line;
		output << "\n";
	}
	input.close();
	output.close();
	return (0);
}