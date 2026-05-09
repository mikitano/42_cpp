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

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n========== CONSTRUCTORS ==========" << std::endl;

	ClapTrap	vox("Vox");
	ScavTrap	alastor("Alastor");
	FragTrap	angel("Angel");
	DiamondTrap	charlie("Charlie");

	std::cout << "\n========== CLAPTRAP TEST ==========" << std::endl;

	vox.attack("Alastor");
	vox.takeDamage(5);
	vox.beRepaired(3);

	std::cout << "\n========== SCAVTRAP TEST ==========" << std::endl;

	alastor.attack("Vox");
	alastor.guardGate();

	std::cout << "\n========== FRAGTRAP TEST ==========" << std::endl;

	angel.attack("Vox");
	angel.highFivesGuys();

	std::cout << "\n========== DIAMONDTRAP TEST ==========" << std::endl;

	charlie.whoAmI();

	std::cout << "\n--- DiamondTrap attack (should use ScavTrap attack) ---" << std::endl;

	charlie.attack("Vox");

	std::cout << "\n--- DiamondTrap special abilities ---" << std::endl;

	charlie.guardGate();
	charlie.highFivesGuys();

	std::cout << "\n========== ENERGY TEST ==========" << std::endl;

	for (int i = 1; i <= 51; i++)
	{
		std::cout << "Attack " << i << ": ";
		alastor.attack("Vox");
	}

	std::cout << "\n========== DAMAGE / DEATH TEST ==========" << std::endl;

	vox.takeDamage(20);
	vox.attack("Alastor");
	vox.beRepaired(5);

	std::cout << "\n========== COPY TEST ==========" << std::endl;

	DiamondTrap copy(charlie);
	copy.whoAmI();
	copy.attack("Alastor");

	std::cout << "\n========== ASSIGNMENT TEST ==========" << std::endl;

	DiamondTrap another("Vaggie");
	another = charlie;
	another.whoAmI();
	another.attack("Angel");

	std::cout << "\n========== DESTRUCTORS ==========" << std::endl;
	return (0);
}
