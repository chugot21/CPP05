/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:33 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 21:24:16 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string formname, int gradetosign, int gradetoexec) : _formname(formname), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec)
{
    if (gradetosign > 150 || gradetoexec > 150)
        throw Form::GradeTooHighException();
    else if (gradetosign < 1 || gradetoexec < 1)
        throw Form::GradeTooHighException();
}

Form::Form(Form const& src) : _formname(src.getFormName()), _signed(src.getSign()), _gradetosign(src.getGradeToSign()), _gradetoexec(src.getGradeToExec())
{
}

Form::~Form()
{
}

Form&	Form::operator=(Form const& src)
{
    this->_signed = src.getSign();
    return *this;
}

std::string	Form::getFormName() const
{
    return this->_formname;
}

bool		Form::getSign() const
{
    return this->_signed;
}

int			Form::getGradeToSign() const
{
    return this->_gradetosign;
}

int			Form::getGradeToExec() const
{
    return this->_gradetoexec;
}

void		Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradetosign)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high to sign the form";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign the form";
}

std::ostream&	operator<<(std::ostream& o, Form const& i)
{
    o << "The form " << i.getFormName() << " is on status " << i.getSign() << std::endl;
    o << "and can be signed by grade higher or equal to " << i.getGradeToSign() << std::endl;
    o << "and executed by grade higher or equal to " << i.getGradeToExec() << std::endl;
    return o;
}