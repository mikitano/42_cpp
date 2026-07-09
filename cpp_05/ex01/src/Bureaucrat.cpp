/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:05:41 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 01:47:42 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default bureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
		this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form& form) {
	try 
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException:: what() const throw() {
	return "Error: Grade too high";
}

const char* Bureaucrat::GradeTooLowException:: what() const throw() {
	return "Error: Grade too low";
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj) {
	stream	<< obj.getName()
			<< ", bureaucrat grade "
			<< obj.getGrade();
	return stream;
}
