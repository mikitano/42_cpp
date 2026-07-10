/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:59:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 16:08:13 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_signed);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::checkExecution(Bureaucrat const &executor) const {
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException:: what() const throw() {
	return "Error: Grade too high";
}

const char* AForm::GradeTooLowException:: what() const throw() {
	return "Error: Grade too low";
}

const char* AForm::FormNotSignedException:: what() const throw() {
	return "Error: Form not signed";
}

std::ostream& operator<<(std::ostream& stream, const AForm& form) {
	stream	<< "Form " << form.getName()
			<< ", signed: " << (form.getSigned() ? "yes" : "no")
			<< ", grade to sign: " << form.getGradeToSign()
			<< ", grade to execute: " << form.getGradeToExecute();
	return stream;
}