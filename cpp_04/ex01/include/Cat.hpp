/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:09:15 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 11:09:15 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& rhs);
		~Cat();

		void makeSound() const;

		const std::string& getIdea(int i) const;
		void setIdea(int i, const std::string& idea);
};
