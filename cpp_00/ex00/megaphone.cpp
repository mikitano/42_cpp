#include <iostream>
#include <cctypes>
#include <string>

int	main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < ac; i++)
	{
		std::string	str(av[i]);
		for (size_t j = 0; j < str.lenght(); j++)
			std::cout << (char)std::toupper(str[j]);
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}