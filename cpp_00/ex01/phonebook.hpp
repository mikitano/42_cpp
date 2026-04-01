/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:41:32 by mkitano           #+#    #+#             */
/*   Updated: 2026/03/29 16:41:47 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#define MAX_SIZE 8
class Phonebook
{
	private:
		Contact _contact[MAX_SIZE];
		int _index;
		int _count;

	public:
		Phonebook();
		int getCount() const;
		void addContact(Contact newContact);
		void displayAll();
		void displayContact(const std::string &indexStr);
};

#endif