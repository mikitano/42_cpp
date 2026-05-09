/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 23:15:18 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/07 23:15:18 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "===== CLAPTRAP TEST =====" << std::endl;

    ClapTrap vox("Vox");
    vox.attack("Alastor");
    vox.takeDamage(3);
    vox.beRepaired(2);
    std::cout << std::endl;

    std::cout << "===== SCAVTRAP TEST =====" << std::endl;

    ScavTrap alastor("Alastor");
    alastor.attack("Vox");
    alastor.takeDamage(30);
    alastor.beRepaired(10);
    std::cout << std::endl;

    std::cout << "===== SCAVTRAP SPECIAL SKILL =====" << std::endl;

    alastor.guardGate();
    std::cout << std::endl;

	std::cout << "===== ENERGY DEPLETION TEST =====" << std::endl;

	for (int i = 1; i <= 49; i++)
	{
		std::cout << "Attack #" << i << ": ";
		alastor.attack("Vox");
	}
	std::cout << std::endl;
	
    std::cout << "===== DEATH TEST =====" << std::endl;

    vox.takeDamage(100);
    vox.attack("Alastor");
    vox.beRepaired(5);
    std::cout << std::endl;

    std::cout << "===== END OF PROGRAM =====" << std::endl;
    return (0);
}
