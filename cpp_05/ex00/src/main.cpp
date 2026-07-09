/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:01:39 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/08 21:29:53 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "\n========== VALID CONSTRUCTION ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 42);
		std::cout << pomni << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== PROMOTION ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 5);
		std::cout << pomni << std::endl;
		pomni.incrementGrade();
		std::cout << pomni << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== GRADE TOO HIGH ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 1);
		std::cout << pomni << std::endl;
		pomni.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== DEMOTION ==========\n";
	try
	{
		Bureaucrat jax("Jax", 149);
		std::cout << jax << std::endl;
		jax.decrementGrade();
		std::cout << jax << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== GRADE TOO LOW ==========\n";
	try
	{
		Bureaucrat jax("Jax", 150);
		std::cout << jax << std::endl;
		jax.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID GRADE (0) ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID GRADE (151) ==========\n";
	try
	{
		Bureaucrat jax("Jax", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== COPY TEST ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 42);
		Bureaucrat copy(pomni);
		std::cout << copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== ASSIGNMENT TEST ==========\n";
	try
	{
		Bureaucrat pomni("Pomni", 42);
		Bureaucrat jax("Jax", 10);

		std::cout << pomni << std::endl;
		std::cout << jax << std::endl;

		jax = pomni;
		std::cout << "\nAfter assignment:\n";

		std::cout << pomni << std::endl;
		std::cout << jax << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}