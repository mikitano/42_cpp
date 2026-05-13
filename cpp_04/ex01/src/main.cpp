/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:49:51 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 17:49:51 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "=== TESTE CERTO (VIRTUAL) ===" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "type: " << meta->getType() << " " << std::endl;
	std::cout << "type: " << j->getType() << " " << std::endl;
	std::cout << "type: " << i->getType() << " " << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	i->makeSound();
	j->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << std::endl << "=== TESTE ERRADO (SEM VIRTUAL) ===" << std::endl;
	std::cout << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "type: " << wrongMeta->getType() << " " << std::endl;
	std::cout << "type: " << wrongCat->getType() << " " << std::endl;
	std::cout << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongMeta;
	delete wrongCat;
	return 0;
}
