/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:55:14 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:23:41 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUCREAUCRAT_HPP
# define BUCREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <ctime>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		std::string const	_name;
		int					_grade;

	public:

		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		~Bureaucrat();

		Bureaucrat&	operator=(Bureaucrat const& src);
		std::string	getName() const;
		int			getGrade() const;
		void		setGradeup();
		void		setGradedown();
		void		signForm(AForm& form);
		void		executeForm(AForm const& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& i);

#endif