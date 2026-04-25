/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:04:54 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/25 16:09:29 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "DEBUG TEST:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;	
	
	std::cout << "INFO TEST:" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING TEST:" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR TEST:" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
}