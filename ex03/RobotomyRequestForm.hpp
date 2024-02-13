/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:03:00 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 19:52:23 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

		std::string	_target;

	public:
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();

		RobotomyRequestForm&  operator=(RobotomyRequestForm const& src);

		std::string	getTraget() const;
		void		execute(Bureaucrat const& executor) const;
};

std::ostream&	operator<<(std::ostream& o, RobotomyRequestForm const& i);

#endif