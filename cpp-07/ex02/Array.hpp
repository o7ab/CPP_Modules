#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *array;
		size_t length;
	public:
		Array() : array(new T[0]), length(0) {}
		Array(unsigned int n) : array(new T[n]), length(n) {}
		Array(Array const & src) : array(new T[src.length]), length(src.length)
		{
			for (size_t i = 0; i < length; i++)
				array[i] = src.array[i];
		}
		~Array()
		{
			delete[] array;
		}
		Array & operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				delete[] array;
				array = new T[rhs.length];
				length = rhs.length;
				for (size_t i = 0; i < length; i++)
					array[i] = rhs.array[i];
			}
			return *this;
		}
		T & operator[](size_t i)
		{
			try{
			if (i >= length)
				throw std::exception();
			return array[i];
			}
			catch(const std::exception& e)
			{
				std::cerr << "Index out of range" << '\n';
				return array[0];
			}
		}
		size_t size() const
		{
			return length;
		}
};

#endif