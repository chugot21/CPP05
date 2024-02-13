/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:26:23 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 21:47:28 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Intern
{
	private:
		


	public:

		Intern();
		Intern(Intern const& src);
		~Intern();

		Intern&	operator=(Intern const& src);

		AForm&	makeForm(std::string formname, std::string target);

		class	NameError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
};

#endif