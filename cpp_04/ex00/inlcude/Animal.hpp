/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:05:01 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/09 16:13:39 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();
};
