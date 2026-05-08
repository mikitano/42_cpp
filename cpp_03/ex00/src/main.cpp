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

int main(void)
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
	ClapTrap alice("Alice");
    ClapTrap bob("Bob");
    std::cout << std::endl;

    std::cout << "=== Attack Test ===" << std::endl;
    alice.attack("Bob");
    bob.attack("Alice");
    std::cout << std::endl;

    std::cout << "=== Damage Test ===" << std::endl;
    alice.takeDamage(3);
    bob.takeDamage(5);
    std::cout << std::endl;

    std::cout << "=== Repair Test ===" << std::endl;
    alice.beRepaired(2);
    bob.beRepaired(4);
    std::cout << std::endl;

    std::cout << "=== Energy Loss Test ===" << std::endl;
    alice.attack("Bob");
    alice.attack("Bob");
    alice.attack("Bob");
    alice.attack("Bob");
    alice.attack("Bob");
	alice.attack("Bob");
	alice.attack("Bob");
    alice.attack("Bob");
    alice.attack("Bob");
	alice.beRepaired(10);
    std::cout << std::endl;

    std::cout << "=== Death Test ===" << std::endl;
    bob.takeDamage(100);
    bob.attack("Alice");
    bob.beRepaired(10);
    std::cout << std::endl;

    std::cout << "=== End of Program ===" << std::endl;
    return (0);
}
