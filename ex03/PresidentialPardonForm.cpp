/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:49 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:27:34 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("PresidentialForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExec()), _target(src.getTraget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
    this->_target = src.getTraget();
    return *this;
}

std::string     PresidentialPardonForm::getTraget() const
{
    return this->_target;
}

void		PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getSign() == false)
        throw AForm::FormIsntSigned();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->getTraget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i)
{
    o << "The Presidential form " << i.getFormName() << " on status : " << i.getSign() << std::endl;
    o << "and can be signed by grade higher or equal to " << i.getGradeToSign() << std::endl;
    o << "and executed by grade higher or equal to " << i.getGradeToExec() << std::endl;
    return o;
}