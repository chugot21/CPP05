/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:42 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 12:44:39 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
		//Bureaucrat	marc("Marc", 0);
        Bureaucrat  bob("Bob", 1);
        std::cout << bob;
        bob.setGradeup(); //Grade will be 0.
    }
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std ::endl;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std ::endl;
	}
    return 0;
}