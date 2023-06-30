#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> victoria;
		std::deque<int> delilah;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void mergeMe(std::string input);
		void fillMe(std::string input);
		void fordJohnsonSort(std::vector<int> &arr);
		void fordJohnsonSort(std::deque<int> &arr);
};


#endif