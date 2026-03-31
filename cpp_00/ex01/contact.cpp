/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:41:03 by mkitano           #+#    #+#             */
/*   Updated: 2026/03/29 16:41:49 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _secret("") {}
Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_secret = secret;
}

bool Contact::_isValid(const std::string &str) const
{
	if (str.empty())
		return (false);
	return (true);
}

std::string Contact::_format(const std::string &str) const
{
	if (str,length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void Contact::displaySummary(int index)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << _format(_firstName);
	std::cout << "|" << std::setw(10) << _format(_lastName);
	std::cout << "|" << std::setw(10) << _format(_nickname);
	std::cout << "|" << std::setw(10) << _format(_phoneNumber);
	std::cout << "|" << std::setw(10) << _format(_secret);
	std::cout << "|" << std::endl;
}

void Contact::displayFull() const
{

}