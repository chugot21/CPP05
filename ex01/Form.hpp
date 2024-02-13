/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:39 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 15:19:06 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		
		std::string const	_formname;
		bool				_signed;
		int	const			_gradetosign;
		int const			_gradetoexec;

	public:

		Form(std::string formname, int gradetosign, int gradetoexec);
		Form(Form const& src);
		~Form();

		Form&	operator=(Form const& src);

		std::string	getFormName() const;
		bool		getSign() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		void		beSigned(Bureaucrat const& bureaucrat);

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade is too high to sign the form";
			}
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Grade too low to sign the form";
			}
	};

};

std::ostream&	operator<<(std::ostream& o, Form const& i);

#endif