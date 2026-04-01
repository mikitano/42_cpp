/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:41:03 by mkitano           #+#    #+#             */
/*   Updated: 2026/04/01 16:33:58 by mkitano          ###   ########.fr       */
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
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void Contact::displaySummary(int index)
{
	std::cout << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << _format(_firstName);
	std::cout << "|" << std::setw(10) << _format(_lastName);
	std::cout << "|" << std::setw(10) << _format(_nickname);
	std::cout << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _secret << std::endl;
}

std::string Contact::getFirstName() const
{
	return (_firstName);
}
std::string Contact::getLastName() const
{
	return (_lastName);
}
std::string Contact::getNickname() const{
	return (_nickname);
}
std::string Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}
std::string Contact::getSecret() const
{
	return (_secret);
}

bool Contact::setFirstName(const std::string &firstName)
{
	if (!_isValid(firstName))
		return false;
	_firstName = firstName;
	return true;
}
bool Contact::setLastName(const std::string &lastName)
{
	if (!_isValid(lastName))
		return false;
	_lastName = lastName;
	return true;
}
bool Contact::setNickname(const std::string &nickname)
{
	if (!_isValid(nickname))
		return false;
	_nickname = nickname;
	return true;
}
bool Contact::setPhoneNumber(const std::string &phoneNumber)
{
	if (!_isValid(phoneNumber))
		return false;
	_phoneNumber = phoneNumber;
	return true;
}
bool Contact::setSecret(const std::string &secret)
{
	if (!_isValid(secret))
		return false;
	_secret = secret;
	return true;
}