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

}

void Phonebook::displayAll()
{
	std::cout << std::setw(10) << "Index|" << "FirstName|" << "LastName" << "Nickname" << std::endl;
	for (int i = 0; i < this->_count; i++)
		this->_contact[i].displaySummary(i);
}

void Phonebook::displayContact(const std::string &indexStr)
{

}