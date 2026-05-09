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
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "===== CLAPTRAP TEST =====" << std::endl;

    ClapTrap vox("Vox");
    vox.attack("Alastor");
    vox.takeDamage(5);
    vox.beRepaired(3);
    std::cout << std::endl;

    std::cout << "===== SCAVTRAP TEST =====" << std::endl;

    ScavTrap alastor("Alastor");
    alastor.attack("Vox");
    alastor.takeDamage(20);
    alastor.beRepaired(10);
    alastor.guardGate();
    std::cout << std::endl;

    std::cout << "===== FRAGTRAP TEST =====" << std::endl;

    FragTrap charlie("Charlie");
    charlie.attack("Vox");
    charlie.takeDamage(40);
    charlie.beRepaired(25);
    charlie.highFivesGuys();

    std::cout << std::endl;

    std::cout << "===== ENERGY TEST =====" << std::endl;

	charlie.attack("Training Dummy");
	charlie.attack("Training Dummy");
    std::cout << std::endl;

    std::cout << "===== DEATH TEST =====" << std::endl;

    vox.takeDamage(100);
    vox.attack("Alastor");
    vox.beRepaired(5);
    charlie.takeDamage(100);
    charlie.attack("Vox");
    std::cout << std::endl;

    std::cout << "===== CONSTRUCTION / DESTRUCTION CHAIN =====" << std::endl;

    {
        FragTrap temporary("Temporary");
    }
    std::cout << std::endl;

    std::cout << "===== END OF PROGRAM =====" << std::endl;
    return (0);
}
