/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:41:43 by mkitano           #+#    #+#             */
/*   Updated: 2026/03/29 16:41:46 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : _index(0), _count(0) {}

int Phonebook::getCount() const
{
	return _count;
}

void Phonebook::addContact(Contact newContact)
{
	_contact[_index] = newContact;
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

void Phonebook::displayAll()
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname"
	std::cout << std::setw(10) << std::endl;
	for (int i = 0; i < this->_count; i++)
		this->_contact[i].displaySummary(i);
}

void Phonebook::displayContact(const std::string &indexStr)
{
	if (indexStr.length() != 1 || indexStr[0] < '0' || indexStr[0] > '7')
	{
		std::cout << "Error: index must be between 0 - 7" << std::endl;
		return ;
	}
	int index = indexStr[0] - '0';
	if (index >= _count)
	{
		std::cout << "This contact has not been created yet" << std::endl;
		return ;
	}
	this->_contact[index].displayFull();
}