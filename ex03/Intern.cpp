/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:26:19 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 22:09:18 by clara            ###   ########.fr       */
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

AForm&	makeForm(std::string formname, std::string target)
{
	std::string	str[4] = {};


	if ()
		throw Intern::NameError();
	try
	{
		AForm   formname = new formname(target);
		std::cout << "Intern creates " << formname;
	}
	catch(const Intern::NameError& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return *formname;
}

const char* Intern::NameError::what() const throw()
{
	return "Wrong"
}