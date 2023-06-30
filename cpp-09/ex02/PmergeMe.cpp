#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->victoria = other.victoria;
		this->delilah = other.delilah;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::fillMe(std::string input)
{
	bool negative = false;
	while (!input.empty())
	{
		if (input[0] == '-' && std::isdigit(input[1]))
		{
			negative = true;
			input.erase(0, 1);
		}
		if (input[0] == ' ')
			input.erase(0, 1);
		long long value = std::atoll(input.substr(0, input.find(' ')).c_str());
		if (value == 0 && input[0] != '0')
		{
			std::cout << RED << "Error: invalid input" << RESET << std::endl;
			exit(1);
		}
		if (value > INT_MAX || value < INT_MIN)
		{
			std::cout << RED << "Error: value not in range" << RESET << std::endl;
			exit(1);
		}
		if (std::find(this->victoria.begin(), this->victoria.end(), static_cast<int>(value)) != this->victoria.end())
		{
			std::cout << RED << "Error: duplicate value" << RESET << std::endl;
			exit(1);
		}
		this->victoria.push_back(static_cast<int>(value) * (negative ? -1 : 1));
		this->delilah.push_back(static_cast<int>(value) * (negative ? -1 : 1));
		input.erase(0, input.find(' '));
	}

}


void	insertSort(std::deque<int> &arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	insertSort(std::vector<int> &arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &arr)
{
	std::deque<int> u;
	std::deque<int> v;

    for (size_t i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0) 
		{
			u.push_back(arr[i]);
		}
		else
		{
			v.push_back(arr[i]);
		}
    }
	if (u.size() > 1)
    {
        fordJohnsonSort(u);
    }
    if (v.size() > 1)
    {
        fordJohnsonSort(v);
    }
    size_t i = 0, j = 0, k = 0;
    while (i < u.size() && j < v.size())
    {
        if (u[i] < v[j])
        {
            arr[k++] = u[i++];
        }
        else
        {
            arr[k++] = v[j++];
        }
    }

    while (i < u.size())
    {
        arr[k++] = u[i++];
    }
    while (j < v.size())
    {
        arr[k++] = v[j++];
    }
    insertSort(arr);
}

void	PmergeMe::fordJohnsonSort(std::vector<int> &arr)
{
    std::vector<int> u;
	std::vector<int> v;
    for (size_t i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0) 
		{
			u.push_back(arr[i]);
		}
		else
		{
			v.push_back(arr[i]);
		}
    }
	if (u.size() > 1)
    {
        fordJohnsonSort(u);
    }
    if (v.size() > 1)
    {
        fordJohnsonSort(v);
    }
    size_t i = 0, j = 0, k = 0;
    while (i < u.size() && j < v.size())
    {
        if (u[i] < v[j])
        {
            arr[k++] = u[i++];
        }
        else
        {
            arr[k++] = v[j++];
        }
    }

    while (i < u.size())
    {
        arr[k++] = u[i++];
    }
    while (j < v.size())
    {
        arr[k++] = v[j++];
    }
    insertSort(arr);
}

void	PmergeMe::mergeMe(std::string input)
{
	this->fillMe(input);
	if (this->victoria.size() < 2)
	{
		std::cout << RED << "Error: invalid input" << RESET << std::endl;
		exit(1);
	}
	std::cout << "Before: ";
	for (std::vector<int>::iterator it = this->victoria.begin(); it != this->victoria.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;;
	std::cout << "After: ";
	struct timeval start, end;
	gettimeofday(&start, NULL);
	this->fordJohnsonSort(this->victoria);
	gettimeofday(&end, NULL);
	for (std::vector<int>::iterator it = this->victoria.begin(); it != this->victoria.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	long long time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time it took to sort vector container: " << time << "us" << std::endl;
	gettimeofday(&start, NULL);
	this->fordJohnsonSort(this->delilah);
	gettimeofday(&end, NULL);
	time = (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
	std::cout << "Time it took to sort deque container: " << time << "us" << std::endl;	
}