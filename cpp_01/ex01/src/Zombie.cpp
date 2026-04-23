#include "Zombie.hpp"

Zombie::Zombie //TODO inicia vazio

Zombie::~Zombie(){
	std::cout << _name << " is dead again" << std::endl;
}

void Zombie::announce(){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;

	//TODO função que seta nome
}