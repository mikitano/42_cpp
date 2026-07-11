/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:29:44 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/11 01:12:06 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern { 
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);
};