/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:40:53 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:28:04 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExec()), _target(src.getTraget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
    this->_target = src.getTraget();
    return *this;
}

std::string     ShrubberyCreationForm::getTraget() const
{
    return this->_target;
}

void		ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getSign() == false)
        throw AForm::FormIsntSigned();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::ofstream   target(this->_target + "_shrubbery");

        target << "   ,d                                     " << std::endl;
        target << "   88                                     " << std::endl;
        target << " MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba, " << std::endl;
        target << "   88    88P*   *Y8 a8P_____88 a8P_____88 " << std::endl;
        target << "   88    88         8PP******* 8PP******* " << std::endl;
        target << "   88,   88         '8b,   ,aa '8b,   ,aa " << std::endl;
        target << "   *Y888 88          `*Ybbd8*'  `*Ybbd8*' " << std::endl;

        target.close();
    }
}

std::ostream&	operator<<(std::ostream& o, ShrubberyCreationForm const& i)
{
    o << "The Shrubbery form " << i.getFormName() << " is on status " << i.getSign() << std::endl;
    o << "and can be signed by grade higher or equal to " << i.getGradeToSign() << std::endl;
    o << "and executed by grade higher or equal to " << i.getGradeToExec() << std::endl;
    return o;
}