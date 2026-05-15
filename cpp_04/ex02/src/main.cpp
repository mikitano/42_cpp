/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 21:22:48 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/14 21:22:48 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << std::endl;
	const AAnimal *dog = new Dog();
	std::cout << std::endl;
	const AAnimal *cat = new Cat();
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;
	delete cat;
	
	return 0;
}
