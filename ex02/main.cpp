/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:42 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:28:11 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat  bob("Bob", 1);
	Bureaucrat	marc("Marc", 140);
	AForm		*form1 = new ShrubberyCreationForm("home");
	AForm		*form2 = new RobotomyRequestForm("home1");
	AForm		*form3 = new PresidentialPardonForm("home3");

    std::cout << bob;
	std::cout << marc;
	std::cout << *form1;
	std::cout << *form2;
	std::cout << *form3;
	std::cout << std::endl;

	//Everything ok, bob is PDG so grade 1. Maybe failed for Robotomy because random 50%.
	try
	{
		bob.signForm(*form1);
		bob.signForm(*form2);
		bob.signForm(*form3);
		std::cout << std::endl;
		bob.executeForm(*form1);
		bob.executeForm(*form2);
		bob.executeForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
    
	//Fail to sign
	try
	{
		bob.signForm(*form1);
		bob.signForm(*form2);
		bob.signForm(*form3);
		std::cout << std::endl;
		bob.executeForm(*form1);
		bob.executeForm(*form2);
		bob.executeForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//Fail to execute

	//Execute without signed

	delete form1;
	delete form2;
	delete form3;

    return 0;
}