#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	try{
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end())
			throw std::exception();
		return it;
	}
	catch (std::exception &e)
	{
		std::cout << "Iterator " << value << " not found" << std::endl;
		return container.end();
	}
}

#endif