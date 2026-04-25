/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:50:39 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/23 22:50:39 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
	private:
		std::string _type;

	public:
		Weapon(const std::string &type);
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string &type);
};

#endif