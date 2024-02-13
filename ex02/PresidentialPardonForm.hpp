/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clara <clara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:57 by clara             #+#    #+#             */
/*   Updated: 2024/02/13 20:13:16 by clara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		std::string	_target;

	public:
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		~PresidentialPardonForm();

		PresidentialPardonForm&  operator=(PresidentialPardonForm const& src);

		std::string	getTraget() const;
		void		execute(Bureaucrat const& executor) const;
};

std::ostream&	operator<<(std::ostream& o, PresidentialPardonForm const& i);

#endif