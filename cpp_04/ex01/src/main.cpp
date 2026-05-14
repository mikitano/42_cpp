/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 23:07:45 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/13 23:07:45 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "\n========== ANIMAL TEST ==========\n" << std::endl;

	const Animal* animal = new Animal();
	std::cout << std::endl;
	const Animal* dog = new Dog();
	std::cout << std::endl;
	const Animal* cat = new Cat();

	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "animal type: " << animal->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	std::cout << "\n--- Sounds ---" << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << "\n--- Deleting Animals ---" << std::endl;
	delete animal;
	std::cout << std::endl;
	delete dog;
	std::cout << std::endl;
	delete cat;

	std::cout << "\n========== ARRAY TEST ==========\n" << std::endl;

	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
		{
			animals[i] = new Dog();
			std::cout << std::endl;
		}
		else
		{
			animals[i] = new Cat();
			std::cout << std::endl;
		}
	}

	std::cout << "--- Animal Sounds ---" << std::endl;
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	std::cout << "\n--- Deleting Array ---" << std::endl;
	for (int i = 0; i < size; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "========== DEEP COPY TEST ==========\n" << std::endl;

	Dog originalDog;

	originalDog.setIdea(0, "I love bones");
	originalDog.setIdea(1, "I want to play");

	std::cout << "\n--- Original Dog Ideas ---" << std::endl;
	std::cout << originalDog.getIdea(0) << std::endl;
	std::cout << originalDog.getIdea(1) << std::endl;

	std::cout << "\n--- Creating Copy ---" << std::endl;
	Dog copyDog(originalDog);

	std::cout << "\n--- Changing Original Ideas ---";
	originalDog.setIdea(0, "I want to sleep");
	originalDog.setIdea(1, "I am hungry");

	std::cout << "\nOriginal Dog:" << std::endl;
	std::cout << originalDog.getIdea(0) << std::endl;
	std::cout << originalDog.getIdea(1) << std::endl;

	std::cout << "\nCopy Dog:" << std::endl;
	std::cout << copyDog.getIdea(0) << std::endl;
	std::cout << copyDog.getIdea(1) << std::endl;

	std::cout << "\n========== ASSIGNMENT TEST ==========\n" << std::endl;

	Cat originalCat;
	originalCat.setIdea(0, "I hate dogs");
	std::cout << std::endl;

	Cat copyCat;

	std::cout << "\nOriginal Cat:" << std::endl;
	std::cout << originalCat.getIdea(0) << std::endl;

	std::cout << "\n--- Assignment Operator ---" << std::endl;
	copyCat = originalCat;

	originalCat.setIdea(0, "I want fish");

	std::cout << "\nOriginal Cat:" << std::endl;
	std::cout << originalCat.getIdea(0) << std::endl;

	std::cout << "\nCopy Cat:" << std::endl;
	std::cout << copyCat.getIdea(0) << std::endl;

	std::cout << "\n========== END OF TESTS ==========\n" << std::endl;
	return (0);
}

