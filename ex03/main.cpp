/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:42 by clara             #+#    #+#             */
/*   Updated: 2024/02/14 19:09:35 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	Bureaucrat  bob("Bob", 1);
	Intern someRandomIntern;

	AForm* rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	//rrf = someRandomIntern.makeForm("presidential request", "Bender"); //test error

	if (rrf == 0)
		return 1;
	
    std::cout << bob;
	std::cout << *rrf;
	std::cout << std::endl;

	try
	{
		bob.signForm(*rrf);
		bob.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
	delete rrf;

    return 0;
}