#include "Zombie.hpp"

int main(void)
{
	int	horderSize = 5;

	Zombie* horde = zombieHorde(horderSize, "Marquinho");
	for (int i = 0; i < horderSize; i++)
		horde[i].announce();
	
	delete[] horde;
	return 0;
}