/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:17:55 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/06 18:33:40 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
	private:
			std::string _name;
			int _grade;

	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& rhs);
			Bureaucrat& operator=(const Bureaucrat& rhs);
			~Bureaucrat();

			class Bureaucrat::GradeTooHighException : public std::exception {

			};

			class Bureaucrat::GradeTooLowException : public std::exception{

			};

			const std::string& getName() const;
			int getGrade() const;
};
