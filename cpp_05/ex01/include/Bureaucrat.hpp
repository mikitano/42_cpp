/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:17:55 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 01:43:13 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	private:
			const std::string _name;
			int _grade;

	public:
			Bureaucrat();
			Bureaucrat(const std::string& name, int grade);
			Bureaucrat(const Bureaucrat& copy);
			Bureaucrat& operator=(const Bureaucrat& rhs);
			~Bureaucrat();

			const std::string& getName() const;
			int getGrade() const;

			void incrementGrade();
			void decrementGrade();

			void signForm(Form& form);

			class GradeTooHighException : public std::exception {
				public:
					const char* what() const throw();
			};

			class GradeTooLowException : public std::exception{
				public:
					const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj);
