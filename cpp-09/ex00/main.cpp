#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <exchange name>" << std::endl;
		return 1;
	}
	std::string exchangeName = argv[1];
	BitcoinExchange exchange(exchangeName);
	exchange.printExchangeRates(exchangeName);
}