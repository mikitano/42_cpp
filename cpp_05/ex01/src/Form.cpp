/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:59:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 02:05:07 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

Form::~Form() {}

const std::string& Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException:: what() const throw() {
	return "Error: Grade too high";
}

const char* Form::GradeTooLowException:: what() const throw() {
	return "Error: Grade too low";
}

std::ostream& operator<<(std::ostream& stream, const Form& form) {
	stream	<< "Form " << form.getName()
			<< ", signed: " << (form.getSigned() ? "yes" : "no")
			<< ", grade to sign: " << form.getGradeToSign()
			<< ", grade to execute: " << form.getGradeToExecute();
	return stream;
}