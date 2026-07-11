/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:52:01 by mkitano           #+#    #+#             */
/*   Updated: 2026/07/09 23:16:42 by mkitano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this != &rhs)
		AForm::operator=(rhs);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkExecution(executor);
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create file." << std::endl;
		return ;
	}
	outfile	<< "               &&& &&  & &&                                     # #### ####         \n"
    		<< "           && &\\/&\\|&*()|/ @, &&                            ### \\/#|###*|/####      \n"
    		<< "           &\\/(/&/&||/& /_/)_&/_&           *.             ##\\/#/ \\||/##/_/##/_#    \n"
    		<< "        &()*&\\/&|()|/&\\/*'%\" & ()                        ###  \\/###|/ \\/ # ###     \n"
    		<< "       &_\\_&&_\\ |& |&&/&__%_/_& &&              *.      ##_\\_#\\_\\## | #/###_/_####  \n"
    		<< "     && * && & &| &| /& & % ()& /&&                    ## #### # \\ #| /  #### ##/## \n"
    		<< "      ()&_---()&\\&\\|&&-&&--%*--()~   *.                 __#_--###`  |{,###---###-~  \n"
    		<< "          &&     \\|||       .                                     \\ }{            \n"
    		<< "                  |||      .       * .                  *.           }}{      *. \n"
    		<< "                  |||    .'      .       .                           }}{    .'      \n"
    		<< "            , -=-~{ .-^- _  '                                        {{}   '        \n"
    		<< "                                .                               , -=-~{ .-^- _      \n"
    		<< "                * .             *                                   TADC            \n"
    		<< "  ________________________________________________________________________________  \n\n"
			<< "                         Welcome to the Amazing Digital Circus!\n"
			<< "                         Current performer: " << _target << std::endl
			<< "\n  ________________________________________________________________________________  " << std::endl;
	outfile.close();
}