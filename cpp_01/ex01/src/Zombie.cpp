#include "Zombie.hpp"

Zombie::Zombie() : _name("") {};

Zombie::~Zombie(){
	std::cout << _name << " is dead again" << std::endl;
}

void Zombie::announce(){
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(const std::string name){
	_name = name;
}
