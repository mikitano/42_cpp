/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 23:52:32 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/13 23:52:32 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& rhs);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		const std::string& getType() const;
};
