/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:33 by clara             #+#    #+#             */
/*   Updated: 2024/02/14 18:55:58 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string formname, int gradetosign, int gradetoexec) : _formname(formname), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec)
{
    if (gradetosign > 150 || gradetoexec > 150)
        throw AForm::GradeTooHighException();
    else if (gradetosign < 1 || gradetoexec < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const& src) : _formname(src.getFormName()), _signed(src.getSign()), _gradetosign(src.getGradeToSign()), _gradetoexec(src.getGradeToExec())
{
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(AForm const& src)
{
    this->_signed = src.getSign();
    return *this;
}

std::string	AForm::getFormName() const
{
    return this->_formname;
}

bool		AForm::getSign() const
{
    return this->_signed;
}

int			AForm::getGradeToSign() const
{
    return this->_gradetosign;
}

int			AForm::getGradeToExec() const
{
    return this->_gradetoexec;
}

void		AForm::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradetosign)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

void		AForm::execute(Bureaucrat const& executor) const
{
    if (this->_signed == false)
        throw AForm::FormIsntSigned();
    else if (executor.getGrade() > this->_gradetoexec)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high to sign the form";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign the form";
}

const char* AForm::FormIsntSigned::what() const throw()
{
	return "Form isn't signed or Robotomy didn't work";
}

std::ostream&	operator<<(std::ostream& o, AForm const& i)
{
    o << "The form " << i.getFormName() << " is on status " << i.getSign() << " and can be signed by grade higher or equal to " << i.getGradeToSign() << " and executed by grade higher or equal to " << i.getGradeToExec() << std::endl;
    return o;
}