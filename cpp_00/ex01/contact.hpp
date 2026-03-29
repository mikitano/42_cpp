/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:40:50 by mkitano           #+#    #+#             */
/*   Updated: 2026/03/29 17:13:52 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _secret;

	public:
	Contact();
	Contact (std::string firstName, std::string lastName, std::string nickname, std::string phonenumber, std::string secret);
	std::string getFirstName()const;
	std::string getLastName()const;
	std::string getNickname()const;
	std::string getPhoneNumber()const;
	std::string getSecret()const;
	
	bool setFirstName(const std::string &firstName);
	bool setLastName(const std::string &lastName);
	bool setNickname(const std::string &nickname);
	bool setPhoneNumber(const std::string &phoneNumber);
	bool setSecret(const std::string &secret);

};

#endif