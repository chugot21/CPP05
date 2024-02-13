/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:04:05 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:26:50 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src) : AForm(src.getFormName(), src.getGradeToSign(), src.getGradeToExec()), _target(src.getTraget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
    this->_target = src.getTraget();
    return *this;
}

std::string     RobotomyRequestForm::getTraget() const
{
    return this->_target;
}

void		RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    std::srand(std::time(0));
    
    if (this->getSign() == false)
        throw AForm::FormIsntSigned();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else if (std::rand() % 2 == 0) //success 50% of the time
    {
        std::cout << "* Some drilling noises *" << std::endl;
        std::cout << this->_target << "_shrubbery has been robotomized successfully" << std::endl;
    }
    else
    {
        throw AForm::FormIsntSigned();
        std::cout << "* Some drilling noises *" << std::endl;
        std::cout << "Robotomy is broken..." << std::endl;
    }
}

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i)
{
    o << "The Robotomy form " << i.getFormName() << " , status : " << i.getSign() << std::endl;
    o << "and can be signed by grade higher or equal to " << i.getGradeToSign() << std::endl;
    o << "and executed by grade higher or equal to " << i.getGradeToExec() << std::endl;
    return o;
}