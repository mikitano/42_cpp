#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie(void);
		void announce(void);
		//TODO função para setar o nome dos zombies
};

Zombie* zombieHorde( int N, std::string name);
#endif