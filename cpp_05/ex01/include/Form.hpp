/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:59:54 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 01:33:40 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form& copy);
		Form& operator=(const Form& rhs);
		~Form();

		const std::string& getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();			
	};
};

std::ostream& operator<<(std::ostream& stream, const Form& form);
