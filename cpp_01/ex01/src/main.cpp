/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:22:15 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/23 19:22:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	horderSize = 5;

	Zombie* horde = zombieHorde(horderSize, "Marquinho");
	for (int i = 0; i < horderSize; i++)
		horde[i].announce();
	
	delete[] horde;
	return 0;
}