#include "phonebook.hpp"
#include <cstdlib>

std::string getValidInput(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "Error getting the input" << std::endl;
			exit(0);
		}
		if (!input.empty())
			return (input);
		std::cout << "Error: Invalid field! Please try again" << std::endl;
	}
}

int	main(void)
{
	std::string choice;
	Phonebook phonebook;

	while (true)
	{
		std::cout << "Please type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, choice);
		if (choice == "ADD")
		{
			Contact newContact;
			newContact.setFirstName(getValidInput("First Name"));
			newContact.setLastName(getValidInput("Last Name"));
			newContact.setNickname(getValidInput("Nickname"));
			newContact.setPhoneNumber(getValidInput("Phonenumber"));
			newContact.setSecret(getValidInput("Darkest Secret"));
			phonebook.addContact(newContact);
			std::cout << "Contact added with success" << std::endl;
		}
		if (choice == "SEARCH")
		{
			phonebook.displayAll();
			std::string indexStr = getValidInput("Enter index to display details");
			phonebook.displayContact(indexStr);
		}
		else if (choice == "Exit")
			break ;
		else
			std::cout << "Invaid option" << std::endl;
	}
}