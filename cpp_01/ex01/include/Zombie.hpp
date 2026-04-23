/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:22:11 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/23 19:22:11 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie(void);
		void announce(void);
		void setZombieName(const std::string name);
};

Zombie* zombieHorde( int N, std::string name);
#endif