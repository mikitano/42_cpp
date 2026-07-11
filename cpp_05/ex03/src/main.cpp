/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:01:39 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/10 19:03:40 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	std::cout << "========== TEST 1 - ShrubberyCreationForm ==========" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 1);
		ShrubberyCreationForm tree("Pomni");

		std::cout << tree << std::endl;

		pomni.signForm(tree);
		pomni.executeForm(tree);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 2 - RobotomyRequestForm ==========" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 1);
		RobotomyRequestForm robot("Jax");

		pomni.signForm(robot);

		for (int i = 0; i < 5; i++)
		{
			pomni.executeForm(robot);
			std::cout << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 3 - PresidentialPardonForm ==========" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 1);
		PresidentialPardonForm pardon("Caine");

		pomni.signForm(pardon);
		pomni.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 4 - Execute without signing ==========" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 1);
		RobotomyRequestForm robot("Jax");

		pomni.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 5 - Grade too low to sign ==========" << std::endl;
	try
	{
		Bureaucrat jax("Jax", 150);
		PresidentialPardonForm pardon("Pomni");

		jax.signForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "========== TEST 6 - Grade too low to execute ==========" << std::endl;
	try
	{
		Bureaucrat caine("Caine", 50);
		RobotomyRequestForm robot("Pomni");

		caine.signForm(robot);
		caine.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}