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
		//percorre toda a string transformando td em maiúsculo
	}
	std::endl;
	return (0);
}