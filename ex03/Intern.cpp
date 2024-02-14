/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:26:19 by clara             #+#    #+#             */
/*   Updated: 2024/02/14 19:02:01 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <cctype>

Intern::Intern()
{
}

Intern::Intern(Intern const& src)
{
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(Intern const& src)
{
	return *this;
}

AForm*	makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string formname, std::string target)
{
	AForm*	(*tabmakeForm[])(std::string target) = {&makeShrubbery, &makeRobotomy, &makePresidential};
	std::string	str[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for(int i = 0; i < 3; i++)
	{
		if (str[i] == formname)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return (*tabmakeForm[i])(target);
		}
	}
	std::cerr << "The name " << formname << " doesn't exist" << std::endl;
	return NULL;
}
