/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:39 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 19:34:19 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		
		std::string const	_formname;
		bool				_signed;
		int	const			_gradetosign;
		int const			_gradetoexec;

	public:

		AForm(std::string formname, int gradetosign, int gradetoexec);
		AForm(AForm const& src);
		virtual ~AForm();

		AForm&	operator=(AForm const& src);

		std::string	getFormName() const;
		bool		getSign() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		void		beSigned(Bureaucrat const& bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const;

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class	FormIsntSigned : public std::exception
	{
		public:
			virtual const char * what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& o, AForm const& i);

#endif