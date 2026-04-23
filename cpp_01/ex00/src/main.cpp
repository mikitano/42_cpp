#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete(heapZombie);

	randomChump("stackZombie");
	return 0;
}