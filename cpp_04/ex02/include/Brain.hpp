/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 23:06:49 by mkitano           #+#    #+#             */
/*   Updated: 2026/05/11 23:06:49 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& rhs);
		~Brain();

		const std::string& getIdea(int i) const;
		void setIdea(int i, const std::string& idea);
};
