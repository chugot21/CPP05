/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:42 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 15:23:59 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat  bob("Bob", 1);
		Bureaucrat	marc("Marc", 40);
		//Bureaucrat	axel("Axel", 160);
		Form		form("contrat", 10, 20);
    	std::cout << bob;
		std::cout << marc;
		std::cout << form;
		marc.signForm(form);
		bob.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
    return 0;
}