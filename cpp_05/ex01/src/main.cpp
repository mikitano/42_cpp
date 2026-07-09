/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:01:39 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 02:01:21 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n========== CONSTRUCTORS ==========\n" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 42);
		Bureaucrat jax("Jax", 120);

		Form circus("Circus Contract", 50, 25);
		Form license("Magic License", 100, 75);

		std::cout << pomni << std::endl;
		std::cout << jax << std::endl;
		std::cout << circus << std::endl;
		std::cout << license << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== SIGN FORM SUCCESS ==========\n" << std::endl;
	try
	{
		Bureaucrat pomni("Pomni", 20);
		Form circus("Circus Contract", 30, 10);

		std::cout << circus << std::endl;
		pomni.signForm(circus);
		std::cout << circus << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== SIGN FORM FAILURE ==========\n" << std::endl;
	try
	{
		Bureaucrat jax("Jax", 120);
		Form circus("Circus Contract", 30, 10);

		jax.signForm(circus);
		std::cout << circus << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID BUREAUCRAT ==========\n" << std::endl;
	try
	{
		Bureaucrat caine("Caine", 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat caine("Caine", 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID FORM ==========\n" << std::endl;
	try
	{
		Form wrong("Wrong Form", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form wrong("Wrong Form", 50, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== COPY TEST ==========\n" << std::endl;
	try
	{
		Form original("Circus Contract", 30, 10);
		Form copy(original);

		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== ASSIGNMENT TEST ==========\n" << std::endl;
	try
	{
		Form first("First Form", 30, 20);
		Form second("Second Form", 120, 120);

		Bureaucrat pomni("Pomni", 1);
		pomni.signForm(first);

		std::cout << "Before assignment:" << std::endl;
		std::cout << first << std::endl;
		std::cout << second << std::endl;

		second = first;
		std::cout << "\nAfter assignment:" << std::endl;
		std::cout << first << std::endl;
		std::cout << second << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n========== END OF TESTS ==========\n" << std::endl;
	return (0);
}